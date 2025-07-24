//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
/*
A simple C Unit converter program by [Your Name]
This program converts kilometers to miles, pounds to kilograms, and Fahrenheit to Celsius
*/

#include <stdio.h>

int main(void) {
  float km, miles;
  float lbs, kgs;
  float fahr, cels;

  // Conversion from kilometers to miles
  printf("Enter value in kilometers: ");
  scanf("%f", &km);
  miles = km / 1.609;
  printf("%.2f kilometers is equal to %.2f miles\n", km, miles);

  // Conversion from pounds to kilograms
  printf("Enter value in pounds: ");
  scanf("%f", &lbs);
  kgs = lbs / 2.2046;
  printf("%.2f pounds is equal to %.2f kilograms\n", lbs, kgs);

  // Conversion from Fahrenheit to Celsius
  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahr);
  cels = (fahr - 32) * 5/9;
  printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahr, cels);

  return 0;
}