#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

void system_init(void);
void system_sleep_ms(uint32_t ms);
uint32_t system_get_tick(void);

#endif /* SYSTEM_H */