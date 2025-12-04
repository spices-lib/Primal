workspace "Primal"
	startproject "PrimalEditor"

	configurations
	{
		"Debug",
		"DebugWithEditor",
		"Release",
		"ReleaseWithEditor",
	}

	filter "system:windows"
		architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "lib.lua"

include "Engine"
include "EngineDLL"
include "PrimalEditor"
include "EngineTest"
include "ContentTools"
include "FirstGameProject"