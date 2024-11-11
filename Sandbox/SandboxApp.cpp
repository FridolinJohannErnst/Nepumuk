#include <Nepumuk.h>

class Sandbox : public Nepumuk::Application
{
public:
	Sandbox()
	{

	}
	
	~Sandbox()
	{

	}

};

Nepumuk::Application* Nepumuk::CreateApplication()
{
	return new Sandbox();
}