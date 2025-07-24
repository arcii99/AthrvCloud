//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  printf("\nConverting temperature from Celsius to Fahrenheit...\n\n");

  printf("Temperature in Celsius: %.2f\n", celsius);
  printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

  printf("\nBut wait...this is a post-apocalyptic world.\n\n");
  printf("The temperature units we knew no longer exist.\n");
  printf("We now measure temperature in units of radiation.\n\n");

  float radiation;
  radiation = fahrenheit * 100.0;

  printf("Converting temperature from Fahrenheit to radiation...\n\n");

  printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
  printf("Temperature in radiation: %.2f\n", radiation);

  printf("\nThere you have it. Stay safe in this apocalyptic world!\n");

  return 0;
}