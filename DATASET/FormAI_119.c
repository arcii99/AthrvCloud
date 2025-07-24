//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
  int option;
  float value, result;
  printf("Welcome to the futuristic unit converter!\n");

  do {
    printf("\nEnter an option:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Quit\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("Enter length in meters:\n");
        scanf("%f", &value);
        result = value * 3.2808;
        printf("%.2f meters is equal to %.2f feet\n", value, result);
        break;

      case 2:
        printf("Enter length in kilometers:\n");
        scanf("%f", &value);
        result = value * 0.6214;
        printf("%.2f kilometers is equal to %.2f miles\n", value, result);
        break;

      case 3:
        printf("Enter temperature in Celsius:\n");
        scanf("%f", &value);
        result = (value * (9.0 / 5.0)) + 32.0;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, result);
        break;

      case 4:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid option, please try again\n");
    }

  } while(option != 4);

  return 0;
}