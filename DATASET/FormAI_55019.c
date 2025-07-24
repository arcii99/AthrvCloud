//FormAI DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[7];
  int red, green, blue;

  printf("Enter a hex color code (e.g. #FF00FF): ");
  scanf("%s", input);

  if (input[0] != '#') {
    printf("Invalid input! Color code must start with a '#' character.\n");
    return 1;
  }

  red = strtol(&input[1], NULL, 16);
  green = strtol(&input[3], NULL, 16);
  blue = strtol(&input[5], NULL, 16);

  printf("Color converted to RGB: %d %d %d\n", red, green, blue);

  return 0;
}