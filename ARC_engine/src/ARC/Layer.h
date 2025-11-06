#pragma once

#include "ARC/Core.h"
#include "ARC/Events/Event.h"

// Layers should be used only in debug builds, not distribution ones! (i'm sure i'll forget this later)

namespace ARC
{
	class ARC_API Layer
	{
	public: 
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// We only contemplate (for now) 4 types of "events"
		// Later on we'll add enabling and disabling, but not yet
		virtual void OnAttach() {}				// when pushed into the layer stack
		virtual void OnDetach() {}				// when it's pulled out of the layer stack
		virtual void OnUpdate() {}				// self-explanatory
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}	// for other, more general events

		inline const std::string& getName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
