//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
  double fahrenheit, celsius;
  int option;

  printf("Temperature Converter\n");
  printf("=====================\n\n");
  printf("Options:\n");
  printf("1.Convert Fahrenheit to Celsius\n");
  printf("2.Convert Celsius to Fahrenheit\n\n");
  printf("Enter an option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("\nEnter temperature in Fahrenheit: ");
      scanf("%lf", &fahrenheit);
      celsius = (fahrenheit - 32) * 5.0 / 9.0;
      printf("\n%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
      break;
    case 2:
      printf("\nEnter temperature in Celsius: ");
      scanf("%lf", &celsius);
      fahrenheit = (celsius * 9.0 / 5.0) + 32;
      printf("\n%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
      break;
    default:
      printf("\nInvalid option selected. Exiting...\n");
      break;
  }

  printf("\nThank you for using Temperature Converter.\n");

  return 0;
}