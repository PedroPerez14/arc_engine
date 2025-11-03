#pragma once

#include "arcpch.h"

#include "ARC/Core.h"
#include "ARC/Events/Event.h"

namespace ARC
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "ARC Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// This class is just an interface containing a minimal
	//	representation of a window and its properties
	//	(assuming desktop as target platform)
	class ARC_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}						// Virtual destructor to avoid fuck ups later on

		virtual void OnUpdate() = 0;				// Swap buffers and stuff like poll events

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;	// void* since we might change glfw in the future for something else

		static Window* Create(const WindowProps& props = WindowProps());
	};
}

