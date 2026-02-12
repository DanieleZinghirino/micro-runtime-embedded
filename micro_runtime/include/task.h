#ifndef TASK_H
#define TASK_H

#include <stdint.h>

typedef void (*task_func_t)(void);

typedef struct {
    task_func_t function;
    uint32_t period_ms;
    uint32_t last_run;
    uint8_t active;
} task_t;

#endif /* TASK_H */
