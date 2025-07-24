//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>

int main() {
  int choice, input;
  float output;
  printf("Welcome to the brave Unit Converter!\n");

  while(choice != 4) {
    printf("\nWhat Conversion would you like to perform?\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Inches to Centimeters\n");
    printf("3. Convert Miles to Kilometers\n");
    printf("4. Quit the program\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the temperature in Celsius: ");
        scanf("%d", &input);
        output = (input * 9/5) + 32;
        printf("%d Celsius is equal to %.2f Fahrenheit.\n", input, output);
        break;
      case 2:
        printf("Enter the length in Inches: ");
        scanf("%d", &input);
        output = input * 2.54;
        printf("%d Inches is equal to %.2f Centimeters.\n", input, output);
        break;
      case 3:
        printf("Enter the distance in Miles: ");
        scanf("%d", &input);
        output = input * 1.609;
        printf("%d Miles is equal to %.2f Kilometers.\n", input, output);
        break;
      case 4:
        printf("Thank you for using the brave Unit Converter!\n");
        break;
      default:
        printf("Invalid input, please choose again.\n");
    }
  }

  return 0;
}