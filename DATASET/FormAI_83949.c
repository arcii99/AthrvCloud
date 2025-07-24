//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

int main()
{
  float celsius, fahrenheit;
  int choice;

  printf("Enter 1 to convert Celsius to Fahrenheit\n");
  printf("Enter 2 to convert Fahrenheit to Celsius\n");
  scanf("%d", &choice);

  if(choice == 1)
  {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
  }
  else if(choice == 2)
  {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
  }
  else
  {
    printf("Invalid choice");
  }
  
  return 0;
}