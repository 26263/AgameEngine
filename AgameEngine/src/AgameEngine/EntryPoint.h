#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AgameEngine::Application* AgameEngine::CreateApplication();

int main(int argc,char** argv)
{
	AgameEngine::Log::Init();
	//AGE_CORE_WARN("Initialized Core Log");
	//int a = 5;
	//AGE_INFO("Initialized App Log and a={0}",a);


	auto app = AgameEngine::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error AGE only runs on windows
#endif
