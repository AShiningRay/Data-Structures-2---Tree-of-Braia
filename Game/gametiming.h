#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#define TARGET_FPS 30
#define TARGET_TIME (1000000 / TARGET_FPS)

long last_render_time = 0; // Get the start time
long frame_delay = TARGET_TIME;

// Function to get the current time in microseconds
long getCurTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void initFPSLimit() { last_render_time = getCurTime(); }

long limitFPS(long extraUs) 
{
    long current_time = getCurTime();
    long elapsed_time = current_time - last_render_time;

    if (elapsed_time < frame_delay + extraUs*1000) { usleep((frame_delay + extraUs*1000) - elapsed_time); }
    last_render_time = getCurTime(); // Update last time for the next frame
}