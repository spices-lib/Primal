#pragma once
#include "ComponentsCommon.h"
#include "EngineAPI/TransformComponent.h"
#include "EngineAPI/GameEntity.h"

namespace primal::transform {

	struct init_info
	{
		f32 position[3]{};
		f32 rotation[4]{};
		f32 scale[3]{ 1.0f, 1.0f, 1.0f };
	};

	component create(const init_info& info, game_entity::entity entity);
	void remove(component c);

}