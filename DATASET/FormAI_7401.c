//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex[7], c;
  int r, g, b;

  printf("Enter a CSS color code in hexadecimal format (e.g. #RRGGBB): ");
  for (int i = 0; i < 7; i++) {
    scanf("%c", &c);
    if (c == '\n') break;
    hex[i] = c;
  }

  r = strtol(hex+1, NULL, 16) >> 16;
  g = (strtol(hex+1, NULL, 16) >> 8) & 0xFF;
  b = strtol(hex+1, NULL, 16) & 0xFF;

  printf("RGB representation: (%d, %d, %d)\n", r, g, b);

  return 0;
}