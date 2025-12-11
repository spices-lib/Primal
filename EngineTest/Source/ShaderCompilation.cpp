#include <d3d12shader.h>
#include "ShaderCompilation.h"
#include <dxcapi.h>
#include <Graphics/Direct3D12/D3D12Core.h>
#include <Graphics/Direct3D12/D3D12Shaders.h>
#include <filesystem>

using namespace primal;
using namespace primal::graphics::d3d12::shaders;
using namespace Microsoft::WRL;

namespace {

	struct shader_file_info
	{
		const char*         file;
		const char*         function;
		engine_shader::id   id;
		shader_type::type   type;
	};

	constexpr shader_file_info shader_files[]
	{
		{ "FullScreenTriangle.hlsl", "FullScreenTriangleVS", engine_shader::full_screen_triangle, shader_type::vertex },
	};

	static_assert(_countof(shader_files) == engine_shader::count);

	constexpr const char* shaders_source_path{ "../../Engine/Graphics/Direct3D12/Shaders/" };

	bool compiled_shaders_are_up_to_date()
	{
		return true;
	}

	bool save_compiled_shaders(utl::vector<ComPtr<IDxcBlob>>& shaders)
	{

	}
}

bool compile_shaders()
{
	if (compiled_shaders_are_up_to_date()) return true;
	utl::vector<ComPtr<IDxcBlob>> shaders;
	std::filesystem::path path{};
	std::filesystem::path full_path{};

	for (u32 i{ 0 }; i < engine_shader::count; ++i)
	{
		auto& info = shader_files[i];
		path = shaders_source_path;
		path += info.file;
		full_path = std::filesystem::absolute(path);
		if (!std::filesystem::exists(full_path)) return false;
		ComPtr<IDxcBlob> compiled_shader{};
		if (compiled_shader && compiled_shader->GetBufferPointer() && compiled_shader->GetBufferSize())
		{
			shaders.emplace_back(std::move(compiled_shader));
		}
		else
		{
			return false;
		}
	}

	return save_compiled_shaders(shaders);
}