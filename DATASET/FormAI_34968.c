//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
// Welcome to the Happy Temperature Converter!

#include <stdio.h>

int main() {
  printf("Hello and welcome to the Happy Temperature Converter!\n");
  printf("Please enter the temperature in Celsius: ");

  double celsius;
  scanf("%lf", &celsius);

  double fahrenheit = (celsius * 9 / 5) + 32;

  printf("The temperature you entered in Celsius is %.2f degrees Celsius.\n", celsius);
  printf("The temperature in Fahrenheit is %.2f degrees Fahrenheit!\n", fahrenheit);
  printf("Isn't that just amazing? You've successfully converted Celsius to Fahrenheit with ease!\n");

  return 0;
}