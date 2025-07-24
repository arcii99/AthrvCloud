//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>

int main() {
   float temp, max_temp = -273.15, min_temp = 1000.0;
   int count = 0;
   
   while (count < 7) {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temp);

      if (temp < -273.15) {
         printf("Invalid temperature input!\n");
         continue;
      }

      if (temp > max_temp) {
         max_temp = temp;
      }

      if (temp < min_temp) {
         min_temp = temp;
      }

      count++;
   }

   printf("\nThe maximum temperature is %.2f degrees Celsius.\n", max_temp);
   printf("The minimum temperature is %.2f degrees Celsius.\n", min_temp);
   
   return 0;
}