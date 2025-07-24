//FormAI DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>

int main() {

  float celsius, fahrenheit;

  printf("Welcome to Temperature Converter!\n");

  printf("Please enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

  printf("Would you like to convert another temperature? (Y/N) ");
  char choice;
  scanf(" %c", &choice);

  while (choice == 'Y' || choice == 'y') {

    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    printf("Would you like to convert another temperature? (Y/N) ");
    scanf(" %c", &choice);
  }

  printf("Thank you for using Temperature Converter! Have a nice day.\n");

  return 0;
}