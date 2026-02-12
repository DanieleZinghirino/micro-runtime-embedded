#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t data[BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
} circular_buffer_t;

void buffer_init(circular_buffer_t *buffer);
int buffer_write(circular_buffer_t *buffer, uint8_t byte);
int buffer_read(circular_buffer_t *buffer, uint8_t *byte);
int buffer_is_empty(const circular_buffer_t *buffer);

#endif /* BUFFER_H */