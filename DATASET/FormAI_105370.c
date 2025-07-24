//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include<stdio.h>

int main()
{
  int c, d;
  float fahrenheit, kelvin;
  printf("Enter the temperature in Celsius: ");
  scanf("%d", &c);
  fahrenheit = (c * 9 / 5) + 32;
  kelvin = c + 273.15;
  d = (int)fahrenheit;
  printf("\nTemperature in Fahrenheit: %d°F", d);
  d = (int)kelvin;
  printf("\nTemperature in Kelvin: %dK", d);
  printf("\n\nRemember, knowledge is power. And power corrupts. So study hard and be evil.");
  return 0;
}