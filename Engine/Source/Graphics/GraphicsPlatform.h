#pragma once
#include "Common/CommonHeaders.h"

enum class graphics_platform : u32
{
    direct3d12 = 0,
    vulkan = 1,
    open_gl = 2,
};