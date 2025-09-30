workspace "AgameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder(solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "AgameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "AgameEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "AgameEngine/vendor/imgui"


include "AgameEngine/vendor/GLFW"
include "AgameEngine/vendor/Glad"
include "AgameEngine/vendor/imgui"



project "AgameEngine"
	location "AgameEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "agepch.h"
	pchsource "AgameEngine/src/agepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		--staticruntime "On"
		systemversion "latest"

		defines
		{
			"AGE_PLATFORM_WINDOWS",
			"AGE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"

		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "AGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "AGE_RELEASE"
		buildoptions "/MD"
		optimize "On"
	
	filter "configurations:Dist"
		defines "AGE_DIST"
		buildoptions "/MD"
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }
	

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"AgameEngine/vendor/spdlog/include",
		"AgameEngine/src"
	}
	
	links
	{
		"AgameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		--staticruntime "On"
		systemversion "latest"

		defines
		{
			"AGE_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "AGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "AGE_RELEASE"
		buildoptions "/MD"
		optimize "On"
	
	filter "configurations:Dist"
		defines "AGE_DIST"	
		buildoptions "/MD"
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }
	