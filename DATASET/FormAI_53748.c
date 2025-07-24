//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the C Color Code Converter Program!\n");

  char colorCode[7];
  printf("Please enter a HEX color code (e.g. #FF6347): ");
  scanf("%s", colorCode);

  int red = 0, green = 0, blue = 0;
  sscanf(colorCode, "#%02x%02x%02x", &red, &green, &blue);

  printf("\n");
  printf("The color represented by %s is:\n", colorCode);
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  printf("\n");
  printf("Would you like to convert this color to RGB(A)?\n");
  printf("Type 'Y' for Yes or 'N' for No: ");

  char choice;
  scanf(" %c", &choice);

  if (choice == 'Y' || choice == 'y') {
    int alpha = 255;
    printf("\nWhat opacity would you like? (0-255): ");
    scanf("%d", &alpha);

    printf("\n");
    printf("The color represented by %s is:\n", colorCode);
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    printf("Alpha: %d\n", alpha);
  }

  printf("\nThank you for using the C Color Code Converter Program. Have a colorful day!\n");

  return 0;
}