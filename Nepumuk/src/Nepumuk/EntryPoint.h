#pragma once

#ifdef NK_PLATFORM_WINDOWS

extern Nepumuk::Application* Nepumuk::CreateApplication();

int main(int argc, char** argv)
{
	printf("Nepumuk Engine \n");
	auto app = Nepumuk::CreateApplication();
	app->Run();
	delete app;
}

#endif