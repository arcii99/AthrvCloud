//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hex_to_rgb(char *hex, int *r, int *g, int *b) {
  int num = (int) strtol(hex, NULL, 16);
  *r = (num >> 16) & 0xFF;
  *g = (num >> 8) & 0xFF;
  *b = num & 0xFF;
}

void rgb_to_hex(int r, int g, int b, char *hex) {
  sprintf(hex, "%02X%02X%02X", r, g, b);
}

int main() {
  char color[7];
  printf("Enter a hex color code (with the # symbol): ");
  scanf("%s", color);

  // Remove the # symbol if it's there
  if (color[0] == '#') {
    memmove(color, color+1, strlen(color));
  }

  int r, g, b;
  hex_to_rgb(color, &r, &g, &b);
  printf("The R, G, B values are: %d, %d, %d\n", r, g, b);

  char new_hex[7];
  rgb_to_hex(r, g, b, new_hex);
  printf("The new hex code is: #%s\n", new_hex);

  return 0;
}