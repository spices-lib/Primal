project "FirstGameProject"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	flags { "MultiProcessorCompile" }

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
		"Source",
		"%{IncludeDir.Engine}"
	}

	links
	{
		"Engine"
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