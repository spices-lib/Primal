#pragma once
#include "Common/CommonHeaders.h"

namespace primal::content {

	struct asset_type {
		enum type : u32 {
			unknown = 0,
			animation,
			audio,
			material,
			mesh,
			skeleton,
			texture,

			count
		};
	};

	typedef struct compiled_shader
	{
		static constexpr u32 hash_length{16};
		constexpr u64 byte_code_size() const { return _byte_code_size; }
		constexpr const u8* byte_code() const { return &_byte_code; }
		constexpr const u8* hash() const { return &_hash[0]; }
		
	private:
		u64    _byte_code_size;
		u8     _hash[hash_length];
		u8     _byte_code;
	} const *compiled_shader_ptr;
	
	id::id_type create_resource(const void* const data, asset_type::type type);
	void destroy_resource(id::id_type id, asset_type::type type);

}