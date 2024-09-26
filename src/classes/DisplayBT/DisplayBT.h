#ifndef DISPLAYBT_H
#define DISPLAYBT_H

#include <stdint.h>
#include <string>

class DisplayBT
{
public:
    uint8_t coordX, coordY, width, height;
    uint8_t state = 0;
    const char *label;
    DisplayBT(unsigned int x, unsigned int y, uint8_t w, uint8_t h, const char *l);
};

#endif