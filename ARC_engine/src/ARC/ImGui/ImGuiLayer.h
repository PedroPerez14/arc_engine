#pragma once

#include "ARC/Layer.h"

#include "ARC/Events/ApplicationEvent.h"
#include "ARC/Events/KeyEvent.h"
#include "ARC/Events/MouseEvent.h"

namespace ARC
{
	class ARC_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
