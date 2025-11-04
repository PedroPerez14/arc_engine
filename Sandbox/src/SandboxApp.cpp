#include <ARC.h>

class ExampleLayer : public ARC::Layer
{
public: 
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
		ARC_INFO("ExampleLayer::Update");

		if (ARC::Input::IsKeyPressed(ARC_KEY_TAB))
			ARC_TRACE("TAB IS PRESSED!");
	}

	void OnEvent(ARC::Event& event) override
	{
		ARC_TRACE("{0}", event);
	}
};




class Sandbox : public ARC::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ARC::ImGuiLayer());
	}

	~Sandbox()
	{ 

	}
};

ARC::Application* ARC::CreateApplication()
{
	return new Sandbox();
}
