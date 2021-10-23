#pragma once

#ifdef SL_PALTFORM_WINDOWS
extern Solar::Application* Solar::CreateApplication();

int main(int argc ,char** argv) {
	
	auto app = Solar::CreateApplication();
	app->Run();
	delete app;
}
#endif 