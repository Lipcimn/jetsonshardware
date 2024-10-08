#ifndef DISPLAY_LABEL_H
#define DISPLAY_LABEL_H

#include <stdint.h>
#include <string>

class DisplayLabel
{
public:
    uint16_t coordX, coordY, width, height;
    uint32_t color;
    DisplayLabel(unsigned int x, unsigned int y, uint16_t w, uint16_t h, uint32_t c);
};

#endif