#include "system.h"
#include "scheduler.h"

void sensor_task(void);
void control_task(void);
void logger_task(void);
void app_init(void);

int main(void) {
    system_init();
    scheduler_init();
    app_init();

    scheduler_add_task(sensor_task, 100);   
    scheduler_add_task(control_task, 150);
    scheduler_add_task(logger_task, 1000);

    scheduler_run();
    return 0;
}