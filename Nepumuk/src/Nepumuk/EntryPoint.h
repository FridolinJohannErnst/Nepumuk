#pragma once

#ifdef NK_PLATFORM_WINDOWS

extern Nepumuk::Application* Nepumuk::CreateApplication();

int main(int argc, char** argv)
{
	Nepumuk::Log::Init();
	NK_CORE_WARN("Initialized Log!");
	int a = 5;
	NK_INFO("Hello! Var={0}", a);

	auto app = Nepumuk::CreateApplication();
	app->Run();
	delete app;
}

#endif