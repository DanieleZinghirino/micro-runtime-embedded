#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

static circular_buffer_t uart_buffer;

void sensor_task(void) {
    // Simulate reading from a sensor
    uint8_t sensor_data = rand() % 100; // Random byte for demo
    buffer_write(&uart_buffer, sensor_data);
    printf("[SENSOR] Generated value: %u\n", sensor_data);
}

void control_task(void) {
    uint8_t data;

    if (buffer_read(&uart_buffer, &data) == 0) {
        if(data > 70) {
            printf("[CONTROL] Alert: High value received: %u\n", data);
        } else {
            printf("[CONTROL] Normal value received: %u\n", data);
        }
    }
}

void logger_task(void) {
    printf("[LOGGER] System is running\n");
}

void app_init(void) {
    buffer_init(&uart_buffer);
}