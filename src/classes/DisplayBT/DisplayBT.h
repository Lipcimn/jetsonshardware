#ifndef DISPLAYBT_H
#define DISPLAYBT_H

#include <stdint.h>
#include <string>

/**
 * This is a class that will store the values of the size, position, text and state of a button on the display touch
 */
class DisplayBT
{
public:
    uint8_t coordX, coordY, width, height; 
    bool state = false; //Button's state: ```true``` if pressed, otherwise ```false```
    const char *label; //Text inside the button
    DisplayBT(unsigned int x, unsigned int y, uint8_t w, uint8_t h, const char *l);
    friend bool operator == (DisplayBT a, DisplayBT b);
};

#endif