#pragma once
#include "D3D12CommonHeaders.h"

namespace primal::graphics::d3d12::shaders {

	struct shader_type
	{
		enum type : u32 {
			vertex = 0,
			hull,
			domin,
			geometry,
			pixel,
			compute,
			amplification,
			mesh,

			count
		};
	};

	struct engine_shader {
		enum id : u32 {
			full_screen_triangle_vs,
			fill_color_ps = 1,

			count
		};
	};

	bool initialize();
	void shutdown();

	D3D12_SHADER_BYTECODE get_engine_shader(engine_shader::id id);
}