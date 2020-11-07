#ifndef TXTCOLOR_H_INCLUDED
#define TXTCOLOR_H_INCLUDED
#endif // TXTCOLOR_H_INCLUDED
#include <iostream>
#include <windows.h>

/*

    0 - 15 Negro
    16 - 31  Azul Oscuro
    32 - 47 Verde Oscuro
    48 - 63 Aqua
    64 - 79 Tinto
    80 - 95 Morado
    96 - 111 Café
    112 - 127 Gris Claro
    128 - 143 Gris Oscuro
    144 - 159 Azul Rey
    160 - 175 Verde Claro
    176 - 191 Azul Claro
    192 - 207 Rojo
    208 - 223 Rosa
    224 - 239 Amarillo
    240 - 255 Blanco

*/

void TextColor(int color_num)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color_num);
}
