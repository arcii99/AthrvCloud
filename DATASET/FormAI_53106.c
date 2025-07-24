//FormAI DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  
  printf("Please enter the temperature in Celsius: ");
  scanf("%f", &celsius);
  
  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9/5) + 32;
  
  printf("\n%.2f degrees Celsius equals %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
  
  return 0;
}