//FormAI DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>

int main() {
  float temperature;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &temperature);

  if(temperature <= -273.15) {
    printf("Temperature is invalid. Absolute zero is -273.15C\n");
  } else {
    float fahrenheit = (temperature * 1.8) + 32;
    float kelvin = temperature + 273.15;
    printf("Temperature in Fahrenheit: %.2fF\n", fahrenheit);
    printf("Temperature in Kelvin: %.2fK\n", kelvin);
  }

  return 0;
}