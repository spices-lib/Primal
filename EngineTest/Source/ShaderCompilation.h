#pragma once
#include "Common/CommonHeaders.h"
#include <cstdint>

struct shader_file_info
{
    const char*         file_name;
    const char*         function;
    uint32_t            type;
};

std::unique_ptr<u8[]> compile_shader(shader_file_info info, const char* file_path);
bool compile_shaders();