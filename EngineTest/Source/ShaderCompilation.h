#pragma once
#include <cstdint>

struct shader_file_info
{
    const char*         file_name;
    const char*         function;
    uint32_t            type;
};

bool compile_shaders();