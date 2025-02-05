#include "DisplayBT.h"

/** Constructor for DisplayBT class.
 * @param x: Coordenada X do botão | The x coordinate of the button
 * @param y: Coordenada Y do botão | The y coordinate of the button
 * @param w: Largura do botão | The width of the button
 * @param h: Altura do botão | The height of the button
 */
DisplayBT::DisplayBT(unsigned int x, unsigned int y, uint8_t w, uint8_t h, const char *l)
{
    this->coordX = x;
    this->coordY = y;
    this->width = w;
    this->height = h;
    this->label = l;
}

/**
 *
 * Operador ```==``` para a classe DisplayBT.
 * Verifica se dois objetos DisplayBT são iguais.
 *
 * Operator ```==``` for DisplayBT class.
 * Checks if two DisplayBT objects are equal.
 * @param a: O primeiro objeto DisplayBT | The first DisplayBT object
 * @param b: O segundo objeto DisplayBT | The second DisplayBT object
 * @return: ```true``` se os objetos forem iguais, ```false``` caso contrário | ```true``` if the objects are equal, ```false``` otherwise
 */
bool operator==(DisplayBT a, DisplayBT b)
{
    return (a.coordX == b.coordX && a.coordY == b.coordY && a.width == b.width && a.height == b.height && a.label == b.label);
}