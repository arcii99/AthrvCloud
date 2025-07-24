//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main()
{
  float celsius, fahrenheit;
  int choice;
  printf("Temperature Converter\n");
  printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nEnter your choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f Celsius is %.2f Fahrenheit", celsius, fahrenheit);
    break;
    
  case 2:
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) / 1.8;
    printf("%.2f Fahrenheit is %.2f Celsius", fahrenheit, celsius);
    break;
    
  default:
    printf("Invalid choice");
    break;
  }
  return 0;
}