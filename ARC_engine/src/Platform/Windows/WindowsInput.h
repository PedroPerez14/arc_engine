#pragma once

#include "ARC/Input.h"

namespace ARC
{
	class WindowsInput : public Input		// Why don't we export this into the .dll file??
	{
	protected:
		bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}