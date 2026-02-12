#include "scheduler.h"
#include "system.h"
#include <stdio.h>

static task_t tasks[MAX_TASKS];
static uint8_t task_count = 0;

void scheduler_init(void) {
    task_count = 0;
}

int scheduler_add_task(task_func_t func, uint32_t period_ms) {
    if (task_count >= MAX_TASKS) {
        return -1; // No space for more tasks
    }
    tasks[task_count].function = func;
    tasks[task_count].period_ms = period_ms;
    tasks[task_count].last_run = 0;
    tasks[task_count].active = 1;
    task_count++;

    return 0; // Task added successfully
}

void scheduler_run(void) {
    while (1) {
        uint32_t now = system_get_tick();

        for(uint8_t i = 0; i < task_count; i++) {
            if (tasks[i].active && (uint32_t)(now - tasks[i].last_run) >= tasks[i].period_ms) {
                uint32_t start = system_get_tick();
                tasks[i].function();
                tasks[i].last_run = now;

                uint32_t end = system_get_tick();
                uint32_t exec_time = end - start;
                printf("[TIMING] Task %u executed in %d ms\n", i, exec_time);
            }
        }
        system_sleep_ms(1); // Sleep for a short time to prevent busy waiting
    }
}
