//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Color Code Converter!\n");
  printf("Please enter a color code in the format RRGGBB: ");

  char hex[7];
  scanf("%s", hex);

  int red = strtol(hex, NULL, 16) >> 16;
  int green = (strtol(hex, NULL, 16) >> 8) & 0xFF;
  int blue = strtol(hex, NULL, 16) & 0xFF;

  printf("\nYour color code in RGB format is:\n");
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  printf("\nAmazing! You have successfully converted your color code to RGB!\n");

  return 0;
}