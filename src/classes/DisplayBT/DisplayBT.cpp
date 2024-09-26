#include "DisplayBT.h"

/** Constructor for DisplayBT class.
 * @param x: The x coordinate of the button
 * @param y: The y coordinate of the button
 * @param w: The width of the button
 * @param h: The height of the button
 */
DisplayBT::DisplayBT(unsigned int x, unsigned int y, uint8_t w, uint8_t h, const char *l)
{
    coordX = x;
    coordY = y;
    width = w;
    height = h;
    label = l;
}
