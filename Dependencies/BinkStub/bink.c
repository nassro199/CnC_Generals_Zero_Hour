
#define BINKDLL
#include "bink.h"
#include <stddef.h>
BINK *__stdcall BinkOpen(const char *name, unsigned int flags)
{
    return NULL;
}

void __stdcall BinkSetSoundTrack(unsigned int total_tracks, unsigned int *tracks)
{
    
}

int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param)
{
    return 0;
}

void *__stdcall BinkOpenDirectSound(unsigned long param)
{
    return NULL;
}

void __stdcall BinkClose(BINK *handle)
{
    
}

int __stdcall BinkWait(BINK *handle)
{
    return 0;
}

int __stdcall BinkDoFrame(BINK *handle)
{
    return 0;
}

int __stdcall BinkCopyToBuffer(
    BINK *handle, void *dest, int destpitch, unsigned int destheight, unsigned int destx, unsigned int desty, unsigned int flags)
{
    return 0;
}

void __stdcall BinkSetVolume(BINK *handle, unsigned int trackid, int volume)
{
    
}

void __stdcall BinkNextFrame(BINK *handle)
{
    
}

void __stdcall BinkGoto(BINK *handle, unsigned int frame, int flags)
{
    
}
