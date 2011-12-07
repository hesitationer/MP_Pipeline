#include <Windows.h>
#include "avisynth.h"

#define TCPSOURCE_TEMPLATE "TCPSource(\"127.0.0.1\", %d, \"None\")"

#define MAX_PLATFORM_LENGTH 16

#if defined(_M_X86)

#define CURRENT_PLATFORM "win32"

#elif defined(_M_X64)

#define CURRENT_PLATFORM "win64"

#else

#define CURRENT_PLATFORM "unknown"

#endif

typedef struct _slave_create_params
{
    const char* filter_name;
    const char* script;
    int source_port;
    char slave_platform[MAX_PLATFORM_LENGTH + 1];
} slave_create_params;

void create_slave(IScriptEnvironment* env, slave_create_params* params, int* new_slave_port, HANDLE* slave_stdin_handle);