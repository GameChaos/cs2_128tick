
#include "gc_common.h"
#include <windows.h>
#include "subhook/subhook.h"

typedef void *CreateInterface_t(const char *name, int *ret);
typedef struct
{
	struct
	{
		void (*funcs[13])(void);
		f32 (*GetTickInterval)(void);
	} *vtable;
} ISource2ServerConfig;

#define GETTICKINTERVAL(name) f32 name(void *this_)
typedef GETTICKINTERVAL(GetTickInterval_t);
subhook_t GetTickInterval_hook;
internal GETTICKINTERVAL(Hook_GetTickInterval);

HMODULE g_cs2ServerDll = NULL;
CreateInterface_t *CreateInterface_Orig = NULL;

internal GETTICKINTERVAL(Hook_GetTickInterval)
{
	f32 result = (1.0f / 128.0f);
	return result;
}

__declspec(dllexport) void *CreateInterface(const char *name, int *ret)
{
	if (!g_cs2ServerDll)
	{
		g_cs2ServerDll = LoadLibrary("../../csgo/bin/win64/server.dll");
		CreateInterface_Orig = (CreateInterface_t *)GetProcAddress(g_cs2ServerDll, "CreateInterface");
	}
	
	void *result = NULL;
	if (CreateInterface_Orig)
	{
		result = CreateInterface_Orig(name, ret);
		if (strncmp(name, "Source2ServerConfig", sizeof("Source2ServerConfig") - 1) == 0)
		{
			ISource2ServerConfig *source2ServerConfig = (ISource2ServerConfig *)result;
			
			GetTickInterval_hook = subhook_new((void *)source2ServerConfig->vtable->GetTickInterval, Hook_GetTickInterval, SUBHOOK_64BIT_OFFSET);
			subhook_install(GetTickInterval_hook);
			
			f32 tickInterval = source2ServerConfig->vtable->GetTickInterval();
			tickInterval = tickInterval;
		}
	}
	return result;
}

