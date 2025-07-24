//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main(void) {
  float celsius, fahrenheit;
  char choice;

  printf("Enter 'C' to convert Celsius to Fahrenheit or 'F' to convert Fahrenheit to Celsius: ");
  scanf("%c", &choice);
  
  if (choice == 'C' || choice == 'c') {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
  } else if (choice == 'F' || choice == 'f') {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
  } else {
    printf("Invalid choice!");
  }

  return 0;
}