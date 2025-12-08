#pragma once

//#pragma warning(disable: 4530) // disable exception warning

#include <stdint.h>
#include <assert.h>
#include <typeinfo>
#include <memory>
#include <unordered_map>
#include <string>
#include <mutex>

#if defined(_WIN64)
#include <DirectXMath.h>
#endif

#define DISABLE_COPY(T)                  \
	explicit T(const T&) = delete;       \
	T& operator=(const T&) = delete;  

#define DISABLE_MOVE(T)                  \
	explicit T(T&&) = delete;            \
	T& operator=(const T&) = delete;

#define DISABLE_COPY_AND_MOVE(T)         \
	DISABLE_COPY(T)                      \
	DISABLE_MOVE(T)

#ifdef _DEBUG
#define DEBUG_OP(x) x
#else
#define DEBUG_OP(x)
#endif

#include "Utilities/Math.h"
#include "Utilities/Utilities.h"
#include "PrimitiveTypes.h"
#include "Id.h"