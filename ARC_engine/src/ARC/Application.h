#pragma once

#include "Core.h"

#include "Window.h"
#include "ARC/LayerStack.h"
#include "ARC/Events/Event.h"
#include "ARC/Events/ApplicationEvent.h"

namespace ARC
{
	class ARC_API Application
	{
	public:
		Application();
		virtual ~Application(); 
		// We make it virtual since it will be inherited by almost everything
		// (And a virtual base destructor makes sure every destructor will get called in the hierarchy, 
		// instead of undefined behaviour)

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();	// Left to be implemented (defined) in the CLIENT
}
