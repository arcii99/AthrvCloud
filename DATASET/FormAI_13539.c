//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   char userResponse;
   float currentTemp, targetTemp, tempThreshold;
   srand(time(0)); // Initializing random number generator
   currentTemp = ((float)rand() / (float)(RAND_MAX)) * 20 + 10; // Generating random initial temperature

   printf("Welcome to the Ultra-Precise Temperature Monitor!\n");
   printf("Current temperature is %.2f degrees Celsius\n", currentTemp);
   printf("Please enter your target temperature: ");
   scanf("%f", &targetTemp);
   printf("Please enter your temperature threshold: ");
   scanf("%f", &tempThreshold);
   printf("Monitoring temperature...\n");

   while (1) {
      if (currentTemp >= targetTemp + tempThreshold) {
         printf("WARNING: Temperature too high! Current temperature is %.2f degrees Celsius\n", currentTemp);
         printf("Please enter 'c' to continue monitoring, or 'q' to quit: ");
         scanf(" %c", &userResponse);
         if (userResponse == 'q') {
            printf("Quitting monitoring system...\n");
            break;
         }
      }
      else if (currentTemp <= targetTemp - tempThreshold) {
         printf("WARNING: Temperature too low! Current temperature is %.2f degrees Celsius\n", currentTemp);
         printf("Please enter 'c' to continue monitoring, or 'q' to quit: ");
         scanf(" %c", &userResponse);
         if (userResponse == 'q') {
            printf("Quitting monitoring system...\n");
            break;
         }
      } else {
         printf("Temperature is within desired range. Current temperature is %.2f degrees Celsius\n", currentTemp);
      }
      currentTemp += ((float)rand() / (float)(RAND_MAX)) * 2 - 1; // Generating random temperature change within range of -1 to 1
   }
   return 0;
}