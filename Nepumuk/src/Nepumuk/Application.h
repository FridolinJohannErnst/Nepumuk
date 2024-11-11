#pragma once

#include "Core.h"

namespace Nepumuk {

	class NEPUMUK_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
