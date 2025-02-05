#include "DisplayLabel.h"

/** Constructor for DisplayBT class.
 * @param x: Coordenada X da label | The x coordinate of the label
 * @param y: Coordenada Y da label | The y coordinate of the label
 * @param w: Largura da label | The width of the label
 * @param h: Altura da label | The height of the label
 */
DisplayLabel::DisplayLabel(unsigned int x, unsigned int y, uint16_t w, uint16_t h, uint32_t c)
{
    this->coordX = x;
    this->coordY = y;
    this->width = w;
    this->height = h;
    this->color = c;
}