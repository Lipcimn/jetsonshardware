#ifndef DISPLAY_LABEL_H
#define DISPLAY_LABEL_H

#include <stdint.h>
#include <string>

/**
 * Essa classe armazena os valores de tamanho e posição de um texto na tela
 *
 * This is a class that will store the values of size and position of a text on a display touch
 */
class DisplayLabel
{
public:
    uint16_t coordX, coordY, width, height;
    uint32_t color; // Isso é necessário porque sempre que um novo texto for impresso, ele não substituirá o texto antigo. Ele é necessário para imprimir uma caixa acima do texto antigo para "deletá-lo" | This is needed because everytime a new text is printed, it does not replace the old one. It's necessary to print a box above the old text to "delete" it.
    DisplayLabel(unsigned int x, unsigned int y, uint16_t w, uint16_t h, uint32_t c);
};

#endif