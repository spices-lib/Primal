IncludeDir                                = {}
IncludeDir["Engine"]                      = "%{wks.location}/Engine/Source"
IncludeDir["EngineDLL"]                   = "%{wks.location}/EngineDLL/Source"
IncludeDir["PrimalEditor"]                = "%{wks.location}/PrimalEditor/Source"
IncludeDir["DirectXShaderCompiler"]       = "%{wks.location}/ThirdParty/DirectXShaderCompiler/inc"
IncludeDir["FBX"]                         = "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.7/include"

LibraryDir                                = {}
LibraryDir["DirectXShaderCompiler"]       = "%{wks.location}/ThirdParty/DirectXShaderCompiler/lib/x64"
LibraryDir["FBX"]                         = "%{IncludeDir.FBX}/../lib/x64"

Library                                   = {}
Library["dxgi"]                           = "dxgi.lib"
Library["d3d12"]                          = "d3d12.lib"
Library["DirectXShaderCompiler"]          = "%{LibraryDir.DirectXShaderCompiler}/dxcompiler.lib"

Library["FBX_Debug_fbx"]                  = "%{LibraryDir.FBX}/debug/libfbxsdk-mt.lib"
Library["FBX_Debug_xml"]                  = "%{LibraryDir.FBX}/debug/libxml2-mt.lib"
Library["FBX_Debug_zlib"]                 = "%{LibraryDir.FBX}/debug/zlib-mt.lib"

Library["FBX_Release_fbx"]                = "%{LibraryDir.FBX}/release/libfbxsdk-mt.lib"
Library["FBX_Release_xml"]                = "%{LibraryDir.FBX}/release/libxml2-mt.lib"
Library["FBX_Release_zlib"]               = "%{LibraryDir.FBX}/release/zlib-mt.lib"