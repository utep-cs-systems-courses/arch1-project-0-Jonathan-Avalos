#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 16; row++) {
    unsigned short rowBits = 1 << (row);
    for (char col = 0; col < 11; col++) {
      unsigned short colMask = font_11x16[c][col]; /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
void print_char_8x12(char c)
{
  c -= 0x20;
  for (char col = 0; col < 12; col++) {
    unsigned short colMask = font_8x12[c][col];
    for (char row = 0; row < 8; row++) {
      unsigned short rowBits = 1 << (7-row);
      putchar( (rowBits & colMask) ? ' ' : '*');
    }
    putchar('\n');
  }
}
