#include <AgameEngine.h>


class Sandbox : public AgameEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

AgameEngine::Application* AgameEngine::CreateApplication()
{
	return new Sandbox();
}