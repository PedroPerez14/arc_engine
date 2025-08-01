#include "arcpch.h"

#include "Application.h"

#include "ARC/Events/ApplicationEvent.h"
#include "ARC/Log.h"

namespace ARC
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		ARC_TRACE(e.ToString());

		while (true)
		{
			// Do Stuff
		}
	}
}
