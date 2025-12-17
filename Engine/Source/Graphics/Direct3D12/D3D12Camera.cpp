#include "D3D12Camera.h"
#include "EngineAPI/GameEntity.h"

namespace primal::graphics::d3d12::camera {
    
    namespace {
        
        utl::free_list<d3d12_camera> cameras;
        
        void set_up_vector(d3d12_camera camera, const void* data, u32 size)
        {
            math::v3 up_vector { *(math::v3*)data };
            assert(sizeof(up_vector) == size);
            camera.up(up_vector);
        }
        
        void set_field_of_view(d3d12_camera camera, const void* data, u32 size)
        {
            assert(camera.projection_type() == graphics::camera::type::perspective);
            f32 fov { *(f32*)data };
            assert(sizeof(fov) == size);
            camera.field_of_view(fov);
        }
        
        void set_aspect_ratio(d3d12_camera camera, const void* data, u32 size)
        {
            assert(camera.projection_type() == graphics::camera::type::perspective);
            f32 aspect_ratio { *(f32*)data };
            assert(sizeof(aspect_ratio) == size);
            camera.aspect_ratio(aspect_ratio);
        }
        
        void set_view_width(d3d12_camera camera, const void* data, u32 size)
        {
            assert(camera.projection_type() == graphics::camera::type::orthographic);
            f32 view_width { *(f32*)data };
            assert(sizeof(view_width) == size);
            camera.view_width(view_width);
        }
        
        void set_view_height(d3d12_camera camera, const void* data, u32 size)
        {
            assert(camera.projection_type() == graphics::camera::type::orthographic);
            f32 view_height { *(f32*)data };
            assert(sizeof(view_height) == size);
            camera.view_height(view_height);
        }
        
        void set_near_z(d3d12_camera camera, const void* data, u32 size)
        {
            f32 near_z { *(f32*)data };
            assert(sizeof(near_z) == size);
            camera.near_z(near_z);
        }
        
        void set_far_z(d3d12_camera camera, const void* data, u32 size)
        {
            f32 far_z { *(f32*)data };
            assert(sizeof(far_z) == size);
            camera.far_z(far_z);
        }
        
        void get_view(d3d12_camera camera, const void* data, u32 size)
        {
            math::m4x4* matrix { (math::m4x4*)data };
            assert(sizeof(math::m4x4) == size);
            DirectX::XMStoreFloat4x4(matrix, camera.view());
        }
        
        void get_projection(d3d12_camera camera, const void* data, u32 size)
        {
            math::m4x4* matrix { (math::m4x4*)data };
            assert(sizeof(math::m4x4) == size);
            DirectX::XMStoreFloat4x4(matrix, camera.projection());
        }
    }
    
    d3d12_camera::d3d12_camera(camera_init_info info)
        : _up{ DirectX::XMLoadFloat3(&info.up) }
        , _near_z{ info.near_z }, _far_z{ info.far_z }
        , _field_of_view{ info.field_of_view }, _aspect_ratio{ info.aspect_ratio }
        , _projection_type{ info.type }, _entity_id{ info.entity_id }, _is_dirty{ true }
    {
        assert(id::is_valid(_entity_id));
        update();
    }
    
    void d3d12_camera::update()
    { 
        
    }
    
    void d3d12_camera::up(math::v3 up)
    {
        _up = DirectX::XMLoadFloat3(&up);
        _is_dirty = true;
    }
    
    void d3d12_camera::field_of_view(f32 fov)
    {
        assert(_projection_type == graphics::camera::type::perspective);
        _field_of_view = fov;
        _is_dirty = true;
    }
    
    void d3d12_camera::aspect_ratio(f32 aspect_ratio)
    {
        assert(_projection_type == graphics::camera::type::perspective);
        _aspect_ratio = aspect_ratio;
        _is_dirty = true;
    }
    
    void d3d12_camera::view_width(f32 width)
    {
        assert(_projection_type == graphics::camera::type::orthographic);
        _view_width = width;
        _is_dirty = true;
    }
    
    void d3d12_camera::view_height(f32 height)
    {
        assert(_projection_type == graphics::camera::type::orthographic);
        _view_height = height;
        _is_dirty = true;
    }
    
    void d3d12_camera::near_z(f32 near_z)
    {
        _near_z = near_z;
        _is_dirty = true;
    }
    
    void d3d12_camera::far_z(f32 far_z)
    {
        _far_z = far_z;
        _is_dirty = true;
    }
    
    graphics::camera create(camera_init_info info)
    {
        return graphics::camera{ camera_id{ cameras.add(info) } };
    }
    
    void remove(graphics::camera_id id)
    {
        assert(id::is_valid(id));
        cameras.remove(id);
    }
    
    void set_parameter(camera_id id, camera_parameter::parameter parameter, const void* data, u32 data_size)
    {
        
    }
    
    void get_parameter(camera_id id, camera_parameter::parameter parameter, void* data, u32 data_size)
    {
        
    }
    
    d3d12_camera& get(camera_id id)
    {
        
    }
}