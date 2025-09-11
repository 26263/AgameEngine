#pragma once

#include "Core.h"

namespace AgameEngine {

	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	//To be defined in Client
	Application* CreateApplication();

	
}

