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
