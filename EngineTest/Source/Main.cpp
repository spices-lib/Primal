#include <crtdbg.h>

#define TEST_ENTITY_COMPONENTS 0
#define TEST_WINDOW 1

#if TEST_ENTITY_COMPONENTS
#include "TestEntityComponents.h"
#elif TEST_WINDOW
#include "TestWindows.h"
#else
#error One of the tests needs to be enabled
#endif

int main()
{

#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	engine_test test{};

	if (test.initialize())
	{
		test.run();
	}

	test.shutdown();
	
	
}