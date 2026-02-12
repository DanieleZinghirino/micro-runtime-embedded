#define _POSIX_C_SOURCE 200809L

#include "system.h"
#include <time.h>
#include <unistd.h>


static struct timespec start_time;

void system_init(void) {
    // Initialize system
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

void system_sleep_ms(uint32_t ms) {
    // Sleep for specified milliseconds
    sleep(ms * 1000);
}

uint32_t system_get_tick(void) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    uint32_t tick = (now.tv_sec - start_time.tv_sec) * 1000ULL + (now.tv_nsec - start_time.tv_nsec) / 1000000;
    return tick;
}
