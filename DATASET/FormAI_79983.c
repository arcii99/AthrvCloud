//FormAI DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex[7], rgb[13];
  int r, g, b;

  printf("Enter a hexadecimal color code (with or without the # symbol): ");
  scanf("%s", hex);

  if (hex[0] == '#') {
    sscanf(hex+1, "%02x%02x%02x", &r, &g, &b);
  } else {
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
  }

  sprintf(rgb, "rgb(%d, %d, %d)", r, g, b);

  printf("The RGB color code for %s is: %s\n", hex, rgb);

  return 0;
}