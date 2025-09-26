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
	}

	~Sandbox()
	{ 

	}
};

ARC::Application* ARC::CreateApplication()
{
	return new Sandbox();
}
