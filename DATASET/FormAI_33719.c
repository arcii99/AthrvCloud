//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   srand(time(NULL)); // Randomize the seed for generating random numbers
   int temperature = rand() % (50 + 1 - (-10)) - 10; // Generate a random temperature between -10 to 50 Celsius
   int windSpeed = rand() % (100 + 1 - 1) + 1; // Generate a random wind speed between 1 to 100 km/h
   int cloudCover = rand() % (100 + 1 - 0); // Generate a random percentage of cloud cover between 0 to 100%
   int precipitation = rand() % 2; // Generate either 0 (no precipitation) or 1 (precipitation)

   printf("Current weather conditions:\n");
   printf("Temperature: %d C\n", temperature);
   printf("Wind speed: %d km/h\n", windSpeed);
   printf("Cloud cover: %d%%\n", cloudCover);
   printf("Precipitation: %s\n", (precipitation == 1) ? "Yes" : "No");

   // Determine the weather condition
   if (precipitation == 1) { // If it is raining or snowing
      if (temperature >= 0) { // If it is above freezing
         printf("It is raining with a temperature of %d C.\n", temperature);
      } else { // If it is below freezing
         printf("It is snowing with a temperature of %d C.\n", temperature);
      }
      // Determine the intensity of precipitation
      if (cloudCover >= 75) {
         printf("The precipitation is heavy.\n");
      } else if (cloudCover < 75 && cloudCover >= 50) {
         printf("The precipitation is moderate.\n");
      } else {
         printf("The precipitation is light.\n");
      }
   } else { // If there is no precipitation
      if (temperature >= 30) { // If it is hot
         printf("It is hot with a temperature of %d C.\n", temperature);
      } else if (temperature < 30 && temperature >= 20) { // If it is warm
         printf("It is warm with a temperature of %d C.\n", temperature);
      } else if (temperature < 20 && temperature >= 10) { // If it is cool
         printf("It is cool with a temperature of %d C.\n", temperature);
      } else { // If it is cold
         printf("It is cold with a temperature of %d C.\n", temperature);
      }
      // Determine the wind condition
      if (windSpeed >= 75) {
         printf("The wind is strong.\n");
      } else if (windSpeed < 75 && windSpeed >= 50) {
         printf("The wind is moderate.\n");
      } else {
         printf("The wind is light.\n");
      }
   }

   return 0;
}