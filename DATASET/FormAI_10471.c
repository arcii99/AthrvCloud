//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

int main() {
   float celsius, fahrenheit;

   printf("\nPlease enter the temperature in Celsius: ");
   scanf("%f", &celsius);

   fahrenheit = (celsius * 9 / 5) + 32;

   printf("\n%.2f Celsius is equivalent to %.2f Fahrenheit", celsius, fahrenheit);

   float meter, kilometer, centimeter, millimeter;

   printf("\n\nPlease enter the length in meters: ");
   scanf("%f", &meter);

   kilometer = meter / 1000;
   centimeter = meter * 100;
   millimeter = meter * 1000;

   printf("\n%.2f meters is equivalent to:\n%.2f kilometers\n%.2f centimeters\n%.2f millimeters", meter, kilometer, centimeter, millimeter);

   float hours, minutes, seconds;

   printf("\n\nPlease enter the time duration in hours: ");
   scanf("%f", &hours);

   minutes = hours * 60;
   seconds = hours * 60 * 60;

   printf("\n%.2f hours is equivalent to:\n%.2f minutes\n%.2f seconds", hours, minutes, seconds);

   return 0;
}