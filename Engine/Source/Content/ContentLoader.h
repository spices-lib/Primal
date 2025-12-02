#pragma once
#include "Common/CommonHeaders.h"

#if !define(SHIPPING)

namespace primal::content {

	bool load_game();
	void unload_game();

}

#endif