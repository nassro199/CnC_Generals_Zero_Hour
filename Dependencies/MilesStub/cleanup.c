#include "mss.h"
#include <stdlib.h>

void MSS_cleanup(void)
{
    AIL_shutdown();
}

int MSS_auto_cleanup(void)
{
    atexit(MSS_cleanup);
    return 0;
}
