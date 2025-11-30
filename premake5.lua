workspace "Primal"
	startproject "PrimalEditor"

	configurations
	{
		"Debug",
		"Release",
	}

	filter "system:windows"
		architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "lib.lua"

include "Engine"
include "EngineDLL"
include "PrimalEditor"
include "EngineTest"