#include <ARC.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		// TODO: We will make these linkable in the coming commits :D 
		//	(either make everything static or wrap some imgui functions and export those)
		
		// ImGui::Begin("Test?");
		// ImGui::Text("Hello There!");
		// ImGui::End();
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
