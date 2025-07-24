#pragma once
#include <ARC/Log.h>

#ifdef ARC_PLATFORM_WINDOWS

// This function will be created somewhere outside the engine (the application, a.k.a game)
//	and it returns an Application pointer, which we can now use in our main
extern ARC::Application* ARC::CreateApplication();

int main(int argc, char** argv)
{
	// Logging test, delete at some point
	ARC::Log::Init();
	ARC_CORE_WARN("Initialized Log!");

	int wasd = 5;
	ARC_INFO("Hello there! Variable = {0}", wasd);

	auto app = ARC::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error ARC_Engine is only supported for Windows!
#endif
