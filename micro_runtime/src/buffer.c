#include "buffer.h"

void buffer_init(circular_buffer_t *buffer) {
    buffer->head = 0;
    buffer->tail = 0;
}

int buffer_write(circular_buffer_t *buffer, uint8_t byte) {
    uint32_t next = (buffer->head + 1) % BUFFER_SIZE;
    if (next == buffer->tail) {
        return -1; // Buffer full
    }
    buffer->data[buffer->head] = byte;
    buffer->head = next;
    return 0;
}

int buffer_read(circular_buffer_t *buffer, uint8_t *byte) {
    if (buffer->tail == buffer->head) {
        return -1; // Buffer empty
    }
    *byte = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
    return 0;
}

int buffer_is_empty(const circular_buffer_t *buffer) {
    return buffer->tail == buffer->head;
}
