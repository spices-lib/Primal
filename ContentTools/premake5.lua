project "ContentTools"
	kind "SharedLib"
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
		"%{IncludeDir.Engine}",
		"%{IncludeDir.FBX}"
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

		links
		{
			"%{Library.FBX_Debug_fbx}",
			"%{Library.FBX_Debug_xml}",
			"%{Library.FBX_Debug_zlib}",
		}

		runtime "Debug"
		symbols "On"

	filter "configurations:Release"

		defines 
		{
		}

		links
		{
			"%{Library.FBX_Release_fbx}",
			"%{Library.FBX_Release_xml}",
			"%{Library.FBX_Release_zlib}",
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