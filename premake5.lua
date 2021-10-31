workspace "Solar"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Solar"
	location "Solar"
	kind "Sharedlib"
	language "C++"

	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vender/spdlog/include"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"SL_PALTFORM_WINDOWS",
			"SL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.."/Sandbox")
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Solar/vender/spdlog/include",
		"Solar/src"
	}

	links
	{
		"Solar"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"SL_PALTFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"