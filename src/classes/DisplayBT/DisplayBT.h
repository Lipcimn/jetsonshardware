#ifndef DISPLAYBT_H
#define DISPLAYBT_H

#include <stdint.h>
class DisplayBT
{
public:
    uint8_t coordX, coordY, width, height;
    DisplayBT(unsigned int x, unsigned int y, uint8_t w, uint8_t h);
};

#endif