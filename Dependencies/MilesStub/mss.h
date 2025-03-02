// Tip: This file is included in the Miles Sound System SDK, but it is not included in the SDK's
//       documentation. It is used to define the functions that are used in the Miles Sound System
#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef WIN32_EXTRA_LEAN
#define WIN32_EXTRA_LEAN
#endif

#ifndef STRICT
#define STRICT
#endif

#include <windows.h>
#include <mmsystem.h>

#if !defined _MSC_VER
#if !defined(__stdcall)
#if defined __has_attribute && __has_attribute(stdcall)
#define __stdcall __attribute__((stdcall))
#else
#define __stdcall
#endif
#endif /* !defined __stdcall */
#endif /* !defined COMPILER_MSVC */

#ifdef __cplusplus
extern "C" {
#endif


// typedef struct _HWAVEOUT *LPHWAVEOUT;

typedef struct h3DPOBJECT
{
    unsigned int junk;
} h3DPOBJECT;
typedef h3DPOBJECT *H3DPOBJECT;
typedef H3DPOBJECT H3DSAMPLE;
typedef struct _SAMPLE *HSAMPLE;
typedef struct _STREAM *HSTREAM;
typedef struct _DIG_DRIVER
{
    char pad[168];
    int emulated_ds;
} DIG_DRIVER;
typedef struct _DIG_DRIVER *HDIGDRIVER;
typedef struct _AUDIO *HAUDIO;
typedef struct _HMDIDRIVER *HMDIDRIVER;
typedef struct _HDLSDEVICE *HDLSDEVICE;
typedef unsigned long HPROVIDER;
typedef int HTIMER;
typedef unsigned int HPROENUM;
typedef int M3DRESULT;

typedef void *AILLPDIRECTSOUND;
typedef void *AILLPDIRECTSOUNDBUFFER;

typedef struct _AILSOUNDINFO
{
    int format;
    const void *data_ptr;
    unsigned int data_len;
    unsigned int rate;
    int bits;
    int channels;
    unsigned int samples;
    unsigned int block_size;
    const void *initial_ptr;
} AILSOUNDINFO;

typedef enum
{
    DP_ASI_DECODER = 0, // Must be "ASI codec stream" provider
    DP_FILTER, // Must be "MSS pipeline filter" provider
    DP_MERGE, // Must be "MSS mixer" provider
    N_SAMPLE_STAGES, // Placeholder for end of list (= # of valid stages)
    SAMPLE_ALL_STAGES // Used to signify all pipeline stages, for shutdown
} SAMPLESTAGE;

#define AILCALLBACK __stdcall

typedef unsigned long U32;
typedef long S32;
typedef float F32;

#define AIL_set_3D_object_user_data AIL_set_3D_user_data
#define AIL_3D_object_user_data AIL_3D_user_data
#define AIL_3D_open_listener AIL_open_3D_listener

/*
 * Various callback typedefs.
 */
typedef unsigned long(__stdcall *AIL_file_open_callback)(const char *, unsigned long*);
typedef void(__stdcall *AIL_file_close_callback)(unsigned long);
typedef long(__stdcall *AIL_file_seek_callback)(unsigned long, long, unsigned long);
typedef unsigned long(__stdcall *AIL_file_read_callback)(unsigned long, void *, unsigned long);
typedef void(__stdcall *AIL_stream_callback)(HSTREAM);
typedef void(__stdcall *AIL_3dsample_callback)(H3DPOBJECT);
typedef void(__stdcall *AIL_sample_callback)(HSAMPLE);

#if !defined BUILD_STUBS && defined _WIN32
#define IMPORTS __declspec(dllimport)
#else
#define IMPORTS
#endif

#define DIG_USE_WAVEOUT 15
#define AIL_LOCK_PROTECTION 18
#define WAVE_FORMAT_IMA_ADPCM 0x11
#define ENVIRONMENT_GENERIC 0
#define HPROENUM_FIRST 0
#define AIL_NO_ERROR 0
#define AIL_FILE_SEEK_BEGIN 0
#define AIL_FILE_SEEK_CURRENT 1
#define AIL_FILE_SEEK_END 2
#define AIL_3D_2_SPEAKER 0
#define AIL_3D_HEADPHONE 1
#define AIL_3D_SURROUND 2
#define AIL_3D_4_SPEAKER 3
#define AIL_3D_51_SPEAKER 4
#define AIL_3D_71_SPEAKER 5
#define M3D_NOERR 0

#ifndef YES
#define YES 1
#endif

#ifndef NO
#define NO  0
#endif

IMPORTS long __stdcall AIL_3D_sample_volume(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_set_3D_sample_volume(H3DSAMPLE sample, long volume);
IMPORTS void __stdcall AIL_end_3D_sample(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_resume_3D_sample(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_stop_3D_sample(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_start_3D_sample(H3DSAMPLE sample);
IMPORTS int __stdcall AIL_3D_sample_loop_count(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_set_3D_sample_offset(H3DSAMPLE sample, int offset);
IMPORTS int __stdcall AIL_3D_sample_length(H3DSAMPLE sample);
IMPORTS int __stdcall AIL_3D_sample_offset(H3DSAMPLE sample);
IMPORTS int __stdcall AIL_3D_sample_playback_rate(H3DSAMPLE sample);
IMPORTS void __stdcall AIL_set_3D_sample_playback_rate(H3DSAMPLE sample, int playback_rate);
IMPORTS int __stdcall AIL_set_3D_sample_file(H3DSAMPLE sample, const void* file_image);
IMPORTS HPROVIDER __stdcall AIL_set_sample_processor(HSAMPLE sample, SAMPLESTAGE pipeline_stage, HPROVIDER provider);
IMPORTS void __stdcall AIL_set_filter_sample_preference(HSAMPLE sample, const char* name, const void* val);
IMPORTS void __stdcall AIL_release_sample_handle(HSAMPLE sample);
IMPORTS void __stdcall AIL_close_3D_provider(HPROVIDER lib);
IMPORTS int __stdcall AIL_set_preference(unsigned int number, int value);
IMPORTS int __stdcall AIL_waveOutOpen(HDIGDRIVER* driver, LPHWAVEOUT* waveout, int id, LPWAVEFORMAT format);
IMPORTS void __stdcall AIL_waveOutClose(HDIGDRIVER driver);
IMPORTS void __stdcall AIL_set_3D_sample_loop_count(H3DSAMPLE sample, int count);
IMPORTS void __stdcall AIL_set_stream_playback_rate(HSTREAM stream, int rate);
IMPORTS int __stdcall AIL_stream_playback_rate(HSTREAM stream);
IMPORTS void __stdcall AIL_stream_ms_position(HSTREAM sample, S32* total_milliseconds, S32* current_milliseconds);
IMPORTS void __stdcall AIL_set_stream_ms_position(HSTREAM stream, int pos);
IMPORTS int __stdcall AIL_stream_loop_count(HSTREAM stream);
IMPORTS void __stdcall AIL_set_stream_loop_block(HSTREAM stream, int loop_start, int loop_end);
IMPORTS void __stdcall AIL_set_stream_loop_count(HSTREAM stream, int count);
IMPORTS int __stdcall AIL_stream_volume(HSTREAM stream);
IMPORTS void __stdcall AIL_set_stream_volume(HSTREAM stream, int volume);
IMPORTS int __stdcall AIL_stream_pan(HSTREAM stream);
IMPORTS void __stdcall AIL_set_stream_pan(HSTREAM stream, int pan);
IMPORTS void __stdcall AIL_close_stream(HSTREAM stream);
IMPORTS void __stdcall AIL_pause_stream(HSTREAM stream, int onoff);
IMPORTS AIL_stream_callback __stdcall AIL_register_stream_callback(HSTREAM stream, AIL_stream_callback callback);
IMPORTS AIL_3dsample_callback __stdcall AIL_register_3D_EOS_callback(H3DSAMPLE sample, AIL_3dsample_callback EOS);
IMPORTS AIL_sample_callback __stdcall AIL_register_EOS_callback(HSAMPLE sample, AIL_sample_callback EOS);
IMPORTS void __stdcall AIL_start_stream(HSTREAM stream);
IMPORTS HSTREAM __stdcall AIL_open_stream_by_sample(HDIGDRIVER driver, HSAMPLE sample, const char* file_name, int mem);
IMPORTS void __stdcall AIL_set_sample_playback_rate(HSAMPLE sample, int playback_rate);
IMPORTS int __stdcall AIL_sample_playback_rate(HSAMPLE sample);
IMPORTS void __stdcall AIL_sample_ms_position(HSAMPLE sample, long* total_ms, long* current_ms);
IMPORTS void __stdcall AIL_set_sample_ms_position(HSAMPLE sample, int pos);
IMPORTS int __stdcall AIL_sample_loop_count(HSAMPLE sample);
IMPORTS void __stdcall AIL_set_sample_loop_count(HSAMPLE sample, int count);
IMPORTS int __stdcall AIL_sample_volume(HSAMPLE sample);
IMPORTS void __stdcall AIL_set_sample_volume(HSAMPLE sample, int volume);
IMPORTS int __stdcall AIL_sample_pan(HSAMPLE sample);
IMPORTS void __stdcall AIL_set_sample_pan(HSAMPLE sample, int pan);
IMPORTS void __stdcall AIL_end_sample(HSAMPLE sample);
IMPORTS void __stdcall AIL_resume_sample(HSAMPLE sample);
IMPORTS void __stdcall AIL_stop_sample(HSAMPLE sample);
IMPORTS void __stdcall AIL_start_sample(HSAMPLE sample);
IMPORTS void __stdcall AIL_init_sample(HSAMPLE sample);
IMPORTS int __stdcall AIL_set_named_sample_file(
    HSAMPLE sample, const char* file_name, const void* file_image, int file_size, int block);
IMPORTS void __stdcall AIL_set_3D_sample_effects_level(H3DSAMPLE sample, float effect_level);
IMPORTS void __stdcall AIL_set_3D_sample_distances(H3DSAMPLE sample, float max_dist, float min_dist);
IMPORTS void __stdcall AIL_set_3D_velocity_vector(H3DSAMPLE sample, float x, float y, float z);
IMPORTS void __stdcall AIL_set_3D_position(H3DPOBJECT obj, float X, float Y, float Z);
IMPORTS void __stdcall AIL_set_3D_orientation(
    H3DPOBJECT obj, float X_face, float Y_face, float Z_face, float X_up, float Y_up, float Z_up);
IMPORTS int __stdcall AIL_WAV_info(const void* data, AILSOUNDINFO* info);
IMPORTS void __stdcall AIL_stop_timer(HTIMER timer);
IMPORTS void __stdcall AIL_release_timer_handle(HTIMER timer);
IMPORTS void __stdcall AIL_shutdown(void);
IMPORTS int __stdcall AIL_enumerate_filters(HPROENUM* next, HPROVIDER* dest, char** name);
IMPORTS void __stdcall AIL_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb,
    AIL_file_seek_callback seekcb, AIL_file_read_callback readcb);
IMPORTS void __stdcall AIL_release_3D_sample_handle(H3DSAMPLE sample);
IMPORTS H3DSAMPLE __stdcall AIL_allocate_3D_sample_handle(HPROVIDER lib);
IMPORTS void __stdcall AIL_set_3D_user_data(H3DPOBJECT obj, unsigned int index, int value);
IMPORTS void __stdcall AIL_unlock(void);
IMPORTS void __stdcall AIL_lock(void);
IMPORTS void __stdcall AIL_set_3D_speaker_type(HPROVIDER lib, int speaker_type);
IMPORTS void __stdcall AIL_close_3D_listener(H3DPOBJECT listener);
IMPORTS int __stdcall AIL_enumerate_3D_providers(HPROENUM* next, HPROVIDER* dest, char** name);
IMPORTS M3DRESULT __stdcall AIL_open_3D_provider(HPROVIDER lib);
IMPORTS char* __stdcall AIL_last_error(void);
IMPORTS H3DPOBJECT __stdcall AIL_open_3D_listener(HPROVIDER lib);
IMPORTS int __stdcall AIL_3D_user_data(H3DSAMPLE sample, int index);
IMPORTS int __stdcall AIL_sample_user_data(HSAMPLE sample, int index);
IMPORTS HSAMPLE __stdcall AIL_allocate_sample_handle(HDIGDRIVER dig);
IMPORTS void __stdcall AIL_set_sample_user_data(HSAMPLE sample, unsigned int index, int value);
IMPORTS int __stdcall AIL_decompress_ADPCM(const AILSOUNDINFO *info, void **outdata, unsigned long *outsize);
IMPORTS void __stdcall AIL_get_DirectSound_info(HSAMPLE sample, AILLPDIRECTSOUND *lplpDS, AILLPDIRECTSOUNDBUFFER *lplpDSB);
IMPORTS void __stdcall AIL_mem_free_lock(void *ptr);
IMPORTS HSTREAM __stdcall AIL_open_stream(HDIGDRIVER dig, const char *filename, int stream_mem);
IMPORTS int __stdcall AIL_startup(void);
IMPORTS void __stdcall AIL_quick_unload(HAUDIO audio);
IMPORTS HAUDIO __stdcall AIL_quick_load_and_play(const char *filename, unsigned int loop_count, int wait_request);
IMPORTS void __stdcall AIL_quick_set_volume(HAUDIO audio, float volume, float extravol);
IMPORTS int __stdcall AIL_quick_startup(
    int use_digital, int use_MIDI, unsigned int output_rate, int output_bits, int output_channels);
IMPORTS void __stdcall AIL_quick_handles(HDIGDRIVER *pdig, HMDIDRIVER *pmdi, HDLSDEVICE *pdls);
IMPORTS void __stdcall AIL_sample_volume_pan(HSAMPLE sample, float *volume, float *pan);
IMPORTS void __stdcall AIL_set_3D_sample_occlusion(H3DSAMPLE sample, float occlusion);
IMPORTS char *__stdcall AIL_set_redist_directory(const char *dir);
IMPORTS int __stdcall AIL_set_sample_file(HSAMPLE sample, const void *file_image, int block);
IMPORTS void __stdcall AIL_set_sample_volume_pan(HSAMPLE sample, float volume, float pan);
IMPORTS void __stdcall AIL_set_stream_volume_pan(HSTREAM stream, float volume, float pan);
IMPORTS void __stdcall AIL_stream_volume_pan(HSTREAM stream, float *volume, float *pan);
IMPORTS unsigned long __stdcall AIL_get_timer_highest_delay(void);
int MSS_auto_cleanup(void);

#if !defined BUILD_STUBS
#define AIL_startup() (MSS_auto_cleanup(), AIL_startup())
#endif

#ifdef __cplusplus
} // extern "C"
#endif
