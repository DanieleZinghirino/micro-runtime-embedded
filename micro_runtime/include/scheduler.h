#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

#define MAX_TASKS 8

void scheduler_init(void);
int scheduler_add_task(task_func_t function, uint32_t period_ms);
void scheduler_run(void);

#endif /* SCHEDULER_H */