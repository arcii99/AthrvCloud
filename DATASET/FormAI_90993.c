//FormAI DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
   float celsius, fahrenheit;

   printf("Enter temperature in Celsius: ");
   scanf("%f", &celsius);

   fahrenheit = (celsius * 9/5) + 32;

   printf("\nTemperature in Fahrenheit: %.2f°F\n", fahrenheit);

   if (fahrenheit > 100) {
       printf("Wow, it's really hot outside! Don't forget to stay hydrated!\n");
   } else if (fahrenheit > 80 && fahrenheit <= 100) {
       printf("It's a bit warm today, make sure you wear sunscreen if you're going outside.\n");
   } else if (fahrenheit > 60 && fahrenheit <= 80) {
       printf("It's a comfortable temperature today, enjoy the weather!\n");
   } else {
       printf("It's a bit chilly today, don't forget to bring a jacket.\n");
   }

   return 0;
}