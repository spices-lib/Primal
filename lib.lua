IncludeDir                                = {}
IncludeDir["Engine"]                      = "%{wks.location}/Engine/Source"
IncludeDir["EngineDLL"]                   = "%{wks.location}/EngineDLL/Source"
IncludeDir["PrimalEditor"]                = "%{wks.location}/PrimalEditor/Source"
IncludeDir["DirectXShaderCompiler"]       = "%{wks.location}/ThirdParty/DirectXShaderCompiler/inc"

LibraryDir                                = {}
LibraryDir["DirectXShaderCompiler"]       = "%{wks.location}/ThirdParty/DirectXShaderCompiler/lib/x64"

Library                                   = {}
Library["dxgi"]                           = "dxgi.lib"
Library["d3d12"]                          = "d3d12.lib"
Library["DirectXShaderCompiler"]          = "%{LibraryDir.DirectXShaderCompiler}/dxcompiler.lib"