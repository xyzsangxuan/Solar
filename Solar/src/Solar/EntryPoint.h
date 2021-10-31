#pragma once

#ifdef SL_PALTFORM_WINDOWS

extern Solar::Application* Solar::CreateApplication();

int main(int argc ,char** argv) {

	Solar::Log::Init();
	SL_CORE_WARN("Initialized Log!");
	int a = 5;
	SL_INFO("Hello! var = {0}",a);

	auto app = Solar::CreateApplication();
	app->Run();
	delete app;
}
#endif 