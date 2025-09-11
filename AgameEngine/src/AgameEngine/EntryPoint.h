#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AgameEngine::Application* AgameEngine::CreateApplication();

int main(int argc,char** argv)
{
	auto app = AgameEngine::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error AGE only runs on windows
#endif
