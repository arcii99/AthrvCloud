//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>

// function declaration
double convertToFahrenheit(double celsius);

int main() {
   double celsius, fahrenheit;

   printf("Enter temperature in Celsius: ");
   scanf("%lf", &celsius);

   // function call
   fahrenheit = convertToFahrenheit(celsius);

   printf("%.2lf Celsius = %.2lf Fahrenheit", celsius, fahrenheit);

   return 0;
}

// function definition
double convertToFahrenheit(double celsius) {
   double fahrenheit;

   fahrenheit = (celsius * 1.8) + 32;

   return fahrenheit;
}