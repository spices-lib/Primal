#include "Platform.h"
#include "PlatformTypes.h"

#ifdef _WIN64

#include "PlatformWin32.h"

#elif LINUX

#else
#error "must implement at least one platform"
#endif