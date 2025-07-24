//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
  int colorChoice;
  char colorHex[7];
  char red[2];
  char green[2];
  char blue[2];
  printf("Welcome to the Color Code Converter!\n\n");

  printf("What kind of color code would you like to convert?\n");
  printf("1. RGB\n");
  printf("2. HEX\n");
  scanf("%d", &colorChoice);

  if(colorChoice == 1) {
    printf("\nEnter the red value (0-255): ");
    scanf("%s", red);
    printf("Enter the green value (0-255): ");
    scanf("%s", green);
    printf("Enter the blue value (0-255): ");
    scanf("%s", blue);

    int r = atoi(red);
    int g = atoi(green);
    int b = atoi(blue);

    printf("\nThe HEX color code is: #%02X%02X%02X\n", r, g, b);
  } else if(colorChoice == 2) {
    printf("\nEnter the HEX color code (excluding #): ");
    scanf("%s", colorHex);

    char red[3] = {colorHex[0], colorHex[1], '\0'};
    char green[3] = {colorHex[2], colorHex[3], '\0'};
    char blue[3] = {colorHex[4], colorHex[5], '\0'};

    int r = (int)strtol(red, NULL, 16);
    int g = (int)strtol(green, NULL, 16);
    int b = (int)strtol(blue, NULL, 16);

    printf("\nThe RGB color code is: (%d, %d, %d)\n", r, g, b);
  } else {
    printf("\nSorry, that is not a valid option. Please try again.\n");
  }

  return 0;
}