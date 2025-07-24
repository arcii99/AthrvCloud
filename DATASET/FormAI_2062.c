//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char hex[10], red[3], green[3], blue[3];
  int r, g, b;

  printf("Enter a hex color code: ");
  scanf("%s", hex);

  if(strlen(hex) == 6) {
    strncpy(red, hex, 2);
    strncpy(green, hex + 2, 2);
    strncpy(blue, hex + 4, 2);

    r = (int) strtol(red, NULL, 16);
    g = (int) strtol(green, NULL, 16);
    b = (int) strtol(blue, NULL, 16);

    printf("\nRGB color code: (%d, %d, %d)\n\n", r, g, b);

  } else {
    printf("\nInvalid hex color code.\n\n");
  }

  return 0;
}