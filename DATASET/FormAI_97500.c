//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main()
{
  float tempCelsius, tempFahrenheit;
  int choice;

  printf("Welcome to the Unit Converter!\n");
  printf("Select the conversion you'd like to make:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("\nEnter the temperature in Celsius: ");
      scanf("%f", &tempCelsius);
      tempFahrenheit = (tempCelsius * (9.0/5.0)) + 32.0;
      printf("%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.\n", tempCelsius, tempFahrenheit);
      break;
    
    case 2:
      printf("\nEnter the temperature in Fahrenheit: ");
      scanf("%f", &tempFahrenheit);
      tempCelsius = (tempFahrenheit - 32.0) * (5.0/9.0);
      printf("%.1f degrees Fahrenheit is equal to %.1f degrees Celsius.\n", tempFahrenheit, tempCelsius);
      break;
    
    default:
      printf("\nInvalid choice. Please choose option 1 or 2.\n");
  }

  return 0;
}