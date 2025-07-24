//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature, humidity, pressure, wind_speed, air_quality;

   srand(time(0)); // Get a new seed for the random number generator

   printf("Welcome to your weather simulation program!\n");

   while (1) {
      temperature = rand() % 100 - 50; // Generate a random temperature between -50 and 50 degrees Celsius
      humidity = rand() % 101; // Generate a random humidity percentage
      pressure = rand() % 1013 + 900; // Generate a random pressure between 900 and 2013 hPa
      wind_speed = rand() % 101; // Generate a random wind speed
      air_quality = rand() % 6 + 1; // Generate a random air quality index between 1 and 6

      printf("Current weather conditions:\n");
      printf("Temperature: %d degrees Celsius\n", temperature);
      printf("Humidity: %d%%\n", humidity);
      printf("Pressure: %d hPa\n", pressure);
      printf("Wind speed: %d km/h\n", wind_speed);
      printf("Air quality: %d\n", air_quality);

      if (temperature > 30 && humidity > 60 && air_quality < 3) {
         printf("WARNING: It is very hot and humid with poor air quality.\n");
      }
      else if (temperature > 30 && humidity > 60) {
         printf("WARNING: It is very hot and humid.\n");
      }
      else if (temperature < -20) {
         printf("WARNING: It is very cold outside.\n");
      }
      else {
         printf("Conditions are normal.\n");
      }

      // Wait for 5 seconds before generating new weather conditions
      printf("\n");
      clock_t start_time = clock();
      while (((double) (clock() - start_time) / CLOCKS_PER_SEC) < 5) {}
   }

   return 0;
}