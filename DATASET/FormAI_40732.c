//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>

float c_to_f(float celsius)
{
  float fahrenheit = (celsius * 9/5) + 32;
  return fahrenheit;
}

float c_to_k(float celsius)
{
  float kelvin = celsius + 273.15;
  return kelvin;
}

int main()
{
  float celsius;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);
  
  printf("\nTemperature in Fahrenheit: %.2f", c_to_f(celsius));
  printf("\nTemperature in Kelvin: %.2f", c_to_k(celsius));
  
  return 0;
}