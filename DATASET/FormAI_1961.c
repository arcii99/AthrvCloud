//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

int main()
{
  float celsius, fahrenheit;
  int choice;

  printf("Welcome to the temperature converter program!\n");
  printf("1. Celsius to Fahrenheit conversion\n");
  printf("2. Fahrenheit to Celsius conversion\n");
  printf("Please enter your choice(1/2):\n");
  scanf("%d", &choice);

  if(choice == 1)
  {
    printf("Enter temperature in Celsius:\n");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("%.2f degrees Celsius equals to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
  }
  else if(choice == 2)
  {
    printf("Enter temperature in Fahrenheit:\n");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) / 1.8;

    printf("%.2f degrees Fahrenheit equals to %.2f degrees Celsius\n", fahrenheit, celsius);
  }
  else
  {
    printf("Invalid choice entered!");
  }

  return 0;
}