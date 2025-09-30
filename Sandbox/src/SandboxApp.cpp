#include <AgameEngine.h>

class ExampleLayer : public AgameEngine::Layer
{
public:
	ExampleLayer()
		:Layer("ExampleLayer") 
	{
	}

	void OnUpdate() override
	{
		//AGE_INFO("ExampleLayer::Update");
	}

	void OnEvent(AgameEngine::Event& event)
	{
		AGE_TRACE("{0} received by ExampleLayer", event);
	}
};



class Sandbox : public AgameEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverLay(new AgameEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

AgameEngine::Application* AgameEngine::CreateApplication()
{
	return new Sandbox();
}