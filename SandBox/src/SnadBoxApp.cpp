#include <Solar.h>

class SandBox:public Solar::Application
{
public:
	SandBox() {

	}
	~SandBox() {

	}

private:

};

Solar::Application* Solar::CreateApplication() {
	return new SandBox();
}