#include "arcpch.h"

#include "Application.h"

#include "ARC/Log.h"

#include <GLFW/glfw3.h>

namespace ARC
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		// Events will be dispatched from here
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		
		ARC_CORE_INFO("{0}", e);			// Only for debugging purposes
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
			m_Window->OnUpdate();

			// Next up: Window events !!1!
		}
	}
}
