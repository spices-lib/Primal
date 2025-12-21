#include "Components/ComponentsCommon.h"
#include <Content/ContentLoader.h>
#include <Content/ContentToEngine.h>
#include <ShaderCompilation.h>
#include <filesystem>

#include "Graphics/Direct3D12/D3D12Shaders.h"

using namespace primal;

bool read_file(std::filesystem::path path, std::unique_ptr<u8[]>& data, u64& size);

namespace {
    
    id::id_type model_id{ id::invalid_id };
    id::id_type vs_id{ id::invalid_id };
    id::id_type ps_id{ id::invalid_id };
    
    void load_model()
    {
        std::unique_ptr<u8[]> model;
        u64 size{ 0 };
        if (!read_file("../../enginetest/model.model", model, size)) return;
        
        model_id = content::create_resource(model.get(), content::asset_type::mesh);
        assert(id::is_valid(model_id));
    }
    
    void load_shaders()
    {
        using namespace graphics::d3d12::shaders;
        
        shader_file_info info{};
        info.file_name = "TestShader.hlsl";
        info.function = "TestShaderVS";
        info.type = shader_type::vertex;
        
        const char* shader_path{ "../../enginetest/" };
        
        auto vertex_shader = compile_shader(info, shader_path);
        assert(vertex_shader.get());
        
        info.function = "TestShaderPS";
        info.type = shader_type::pixel;
        
        auto pixel_shader = compile_shader(info, shader_path);
        assert(pixel_shader.get());
        
        vs_id = content::add_shader(vertex_shader.get());
        ps_id = content::add_shader(pixel_shader.get());
    }
}

id::id_type create_render_item(id::id_type entity_id)
{
    auto _1 = std::thread([]{ load_model(); });
    auto _2 = std::thread([]{ load_shaders(); });
    
    _1.join();
    _2.join();
    
    return id::invalid_id;
}

void destroy_render_item(id::id_type item_id)
{
    
}