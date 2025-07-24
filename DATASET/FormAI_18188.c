//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  // convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9/5) + 32;

  // print the result
  printf("%.2f Celsius is equal to %.2f Fahrenheit.", celsius, fahrenheit);

  // add an invasive feature
  printf("Ha! I bet you didn't expect me to convert it to Kelvin too!\n");

  // convert Celsius to Kelvin
  float kelvin = celsius + 273.15;

  // print the Kelvin result
  printf("%.2f Celsius is equal to %.2f Kelvin.", celsius, kelvin);

  // add even more insult to injury
  printf("You know, I could have also converted it to Rankine, but I didn't want to make you feel bad about not knowing what that is.\n");

  return 0;
}