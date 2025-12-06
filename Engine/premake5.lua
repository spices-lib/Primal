project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	flags { "MultiProcessorCompile" }

	--pchheader "Pchheader.h"
	--pchsource "src/Pchheader.cpp"

	files
	{
		"Source/**.h",
		"Source/**.hpp",
		"Source/**.cpp",
		"Source/**.c",
		"Source/**.cc",
	}

	defines
	{
	}

	includedirs
	{
		"Source"
	}

	links
	{
	}

	filter "system:windows"
		systemversion   "latest" 
		editAndContinue "Off"

		includedirs
		{
		}

		defines
		{
		}

		links
		{
			"%{Library.dxgi}",
			"%{Library.d3d12}",
		}

		buildoptions 
		{ 
			"/utf-8"
		}

	filter "configurations:Debug"

		defines 
		{
		}

		runtime "Debug"
		symbols "On"

	filter "configurations:Release"

		defines 
		{
		}

		runtime "Release"
		optimize "On"

	filter "configurations:DebugWithEditor"

		defines 
		{
			"USE_WITH_EDITOR"
		}

		runtime "Debug"
		symbols "On"

	filter "configurations:ReleaseWithEditor"

		defines 
		{
			"USE_WITH_EDITOR"
		}

		runtime "Release"
		optimize "On"