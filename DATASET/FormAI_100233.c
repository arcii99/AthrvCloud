//FormAI DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // set seed for randomization

   // randomly generates initial temperature, wind speed, and weather condition
   int temp = rand() % 100;
   int windSpeed = rand() % 30;
   int weather = rand() % 3; // 0 for sunny, 1 for cloudy, and 2 for rainy

   printf("WELCOME TO WEATHER SIMULATION!\n\n");

   int i;
   for (i = 0; i < 5; i++) { // simulate weather for 5 days
      // update weather conditions
      int change = rand() % 5 - 2; // randomly changes temperature and wind speed
      temp += change;
      windSpeed += change;

      // prints weather conditions for the day
      printf("DAY %d:\n", i + 1);
      switch(weather) {
         case 0:
            printf("Sunny with a temperature of %d degrees and %d mph wind speed.\n", temp, windSpeed);
            break;
         case 1:
            printf("Cloudy with a temperature of %d degrees and %d mph wind speed.\n", temp, windSpeed);
            break;
         case 2:
            printf("Rainy with a temperature of %d degrees and %d mph wind speed.\n", temp, windSpeed);
            break;
         default:
            printf("Unknown weather condition.\n");
      }

      // updates weather condition for next day
      if (temp >= 80 && weather != 2) {
         weather = 0; // sunny if temperature is above 80 degrees and not currently raining
      } else if (temp <= 60 && weather != 0) {
         weather = 2; // rainy if temperature is below 60 degrees and not currently sunny
      } else {
         weather = 1; // otherwise, cloudy
      }

      printf("\n");
   }

   printf("THANK YOU FOR USING WEATHER SIMULATION!\n");

   return 0;
}