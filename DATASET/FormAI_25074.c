//FormAI DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

int main() {
  float fahrenheit, celsius;

  printf("Hello there! I am a curious temperature converter bot.\n");
  printf("I can help you convert temperatures from Fahrenheit to Celsius and vice versa.\n");

  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  // Conversion formula for Fahrenheit to Celsius
  celsius = (fahrenheit - 32) / 1.8;

  printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);

  printf("Now, let's try converting from Celsius to Fahrenheit.\n");

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Conversion formula for Celsius to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;

  printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

  printf("Thanks for using my temperature converter program. Have a nice day!\n");

  return 0;
}