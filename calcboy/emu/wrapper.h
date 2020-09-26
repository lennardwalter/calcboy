#pragma once
#include <stdint.h>

#ifdef __cplusplus

extern "C"
{
#endif

    uint8_t *getKeyStates();
    uint64_t millis();
    void sleep(uint32_t);
    void drawLine(uint16_t *pixels, uint8_t y);

#ifdef __cplusplus
}
#endif
