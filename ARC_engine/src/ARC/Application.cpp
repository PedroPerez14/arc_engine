#include "arcpch.h"

#include "Application.h"

#include "ARC/Events/ApplicationEvent.h"
#include "ARC/Log.h"

#include <GLFW/glfw3.h>

namespace ARC
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

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
