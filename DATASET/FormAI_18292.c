//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

void main() {
  float celsius, fahrenheit, meters, feet, kilometers, miles;

  // Celsius to Fahrenheit
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);
  fahrenheit = (celsius * 9/5) + 32;
  printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

  // Meters to Feet
  printf("Enter distance in meters: ");
  scanf("%f", &meters);
  feet = meters * 3.2808;
  printf("%.2f meters is equal to %.2f feet.\n", meters, feet);

  // Kilometers to Miles
  printf("Enter distance in kilometers: ");
  scanf("%f", &kilometers);
  miles = kilometers * 0.621371;
  printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
}