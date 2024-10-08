#include "DisplayLabel.h"

/** Constructor for DisplayBT class.
 * @param x: The x coordinate of the label
 * @param y: The y coordinate of the label
 * @param w: The width of the label
 * @param h: The height of the label
 */
DisplayLabel::DisplayLabel(unsigned int x, unsigned int y, uint16_t w, uint16_t h, uint32_t c)
{
    coordX = x;
    coordY = y;
    width = w;
    height = h;
    color = c;
}