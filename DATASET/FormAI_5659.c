//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>

int main() {
   int temp;
   printf("Enter a temperature in Celsius: ");
   scanf("%d", &temp);
   
   if(temp < -273.15) {
      printf("Temperature entered is invalid as it is below absolute zero.\n");
   } else {
      // conversion to Fahrenheit
      float f_temp = temp * 9 / 5 + 32;
      printf("Temperature in Celsius: %d\n", temp);
      printf("Temperature in Fahrenheit: %.2f\n", f_temp);

      // categorizing temperature
      if(f_temp < 0) {
         printf("EXTREMELY COLD weather.\n");
      } else if(f_temp >= 0 && f_temp < 32) {
         printf("VERY COLD weather.\n");
      } else if(f_temp >= 32 && f_temp < 50) {
         printf("COLD weather.\n");
      } else if(f_temp >= 50 && f_temp < 75) {
         printf("MILD weather.\n");
      } else if(f_temp >= 75 && f_temp < 90) {
         printf("WARM weather.\n");
      } else if(f_temp >= 90 && f_temp < 100) {
         printf("HOT weather.\n");
      } else if(f_temp >= 100) {
         printf("EXTREMELY HOT weather.\n");
      }
   }

   return 0;
}