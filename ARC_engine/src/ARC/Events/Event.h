#pragma once

#include "ARC/Core.h"

#include <string>
#include <functional>

namespace ARC
{
	// Copied from TheCherno's post:
	// Events in ARC_engine are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then and there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// We may want to filter events according to their type
	// For example, we might want to forward only one type to a component
	// BItmask (multiple categories might be assigned)
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication     = BIT(0),
		EventCategoryInput           = BIT(1),
		EventCategoryKeyboard        = BIT(2),
		EventCategoryMouse           = BIT(3),
		EvcentCategoryMouseButton    = BIT(4)
	};



	class ARC_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>

		/// TODO: Finish implementing this (check the code in the video)
		// Now TheCherno has just jumped into KeyEvent.h, so go there first, I guess
	};

}