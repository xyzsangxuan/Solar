#pragma once

#ifdef SL_PALTFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define SOLAR_API _declspec(dllexport)
	#else SL_BUILD_DLL
		#define SOLAR_API _declspec(dllimport)
	#endif
#else
	#error Solar only Supports Windows!
#endif // SL_PALTFORM_WINDOWS

