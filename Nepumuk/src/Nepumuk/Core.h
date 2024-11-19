#pragma once

#ifdef NK_PLATFORM_WINDOWS
	#ifdef NK_BUILD_DLL
		#define NEPUMUK_API __declspec(dllexport)
	#else
		#define NEPUMUK_API __declspec(dllimport)
	#endif // NK_BUILD_DLL
#else
	#error Nepumuk only supports Windows!
#endif

#ifdef NK_ENABLE_ASSERTS
#define	NK_ASSERT(x, ...) { if(!(x)) { NK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define	NK_CORE_ASSERT(x, ...) { if(!(x)) { NK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else	NK
#define	NK_ASSERT(x, ...)
#define	NK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)