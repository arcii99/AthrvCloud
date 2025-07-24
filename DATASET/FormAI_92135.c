//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {

   int celsius;
   float fahrenheit;
   printf("Enter temperature in Celsius: ");
   scanf("%d", &celsius);

   // Calculate Fahrenheit temperature
   fahrenheit = (celsius * 9.0/5.0) + 32;

   // Display temperature in both Celsius and Fahrenheit
   printf("\nTemperature in Celsius    : %d C", celsius);
   printf("\nTemperature in Fahrenheit : %.2f F", fahrenheit);

   // Check if temperature is above or below freezing point
   if (celsius <= 0) {
      printf("\n\nWarning: It's freezing point! Please wear warm clothes.\n");
   }
   else if (celsius >= 100) {
      printf("\n\nWarning: It's boiling point! Please be cautious.\n");
   }
   else {
      printf("\n\nTemperature is normal. Enjoy your day!\n");
   }

   return 0;
}