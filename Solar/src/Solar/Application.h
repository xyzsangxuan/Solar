#pragma once
#include "Core.h"

namespace Solar {
	class SOLAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in CLIENT
	Application* CreateApplication();
}


