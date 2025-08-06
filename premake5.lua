workspace "ARC_engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	-- DELETE LATER
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the relevant directories, we'll do that through a lua struct 
-- (i'm just following a tutorial but i'm taing notes of everything because i want to fucking learn something)

IncludeDir = {}
IncludeDir["GLFW"] = "ARC_engine/vendor/GLFW/include"

-- This includes the premake in that directory, as a C++ style include
-- (nothing to do with directories)
include "ARC_engine/vendor/GLFW"

project "ARC_engine"
	location "ARC_engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "arcpch.h"
	pchsource "ARC_engine/src/arcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ARC_PLATFORM_WINDOWS",
			"ARC_BUILD_DLL"
		}

		buildoptions
		{
			"/utf-8"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ARC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARC_DIST"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ARC_engine/vendor/spdlog/include",
		"ARC_engine/src"
	}

	links
	{
		"ARC_engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ARC_PLATFORM_WINDOWS"
		}

		buildoptions
		{
			"/utf-8"
		}

	filter "configurations:Debug"
		defines "ARC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARC_DIST"
		optimize "On"