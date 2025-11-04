#include "arcpch.h"

#include "Application.h"

#include "ARC/Log.h"

#include <glad/glad.h>

#include "Input.h"


namespace ARC
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ARC_CORE_ASSERT(!s_Instance, "An instance of Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application()
	{
		
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		// Events will be dispatched from here
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		
		ARC_CORE_TRACE("{0}", e);			// Only for debugging purposes

		// Propagate events to our layers, in reverse order!
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}


	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while(m_Running)
		{
			glClearColor(0.2, 1, 0.3, 1);	// A cool green shade (every green shade is cool, green itself is cool)
			glClear(GL_COLOR_BUFFER_BIT);

			// Update method for our layers
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}


			// Update method for our window (s?)
			m_Window->OnUpdate();
		}
	}
}
