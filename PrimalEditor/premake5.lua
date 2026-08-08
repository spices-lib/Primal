project "PrimalEditor"
	kind "ConsoleApp"
	language "C#"
	dotnetframework "net10.0-windows"
	wpf "On"

	targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	multiprocessorcompile "On"

	files
	{
		"Source/**.cs",
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