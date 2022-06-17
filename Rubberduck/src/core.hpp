#pragma once

// #ifdef RUBBERDUCK_PLATFORM_WINDOWS
// 	#ifdef RUBBERDUCK_BUILD_DLL
// 		#define RUBBERDUCK_API __declspec(dllexport);
// 	#else
// 		#define RUBBERDUCK_API __declspec(dllimport);
// 	#endif
// #else
// 	#error Hazel only supports Windows!
// #endif

#ifdef RUBBERDUCK_ENABLE_ASSERTS
	#define RUBBERDUCK_ASSERT(x, ...) {if(!(x)) { RUBBERDUCK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); "}}
	#define RUBBERDUCK_CORE_ASSERT(x, ...) {if(!(x)) { RUBBERDUCK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); "}}
#else
	#define RUBBERDUCK_ASSERT(x, ...)
	#define RUBBERDUCK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) ( 1 << x)