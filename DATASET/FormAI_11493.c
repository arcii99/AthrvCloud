//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature, humidity, pressure, windspeed;
   int i;

   // Seed the random number generator
   srand(time(NULL));

   printf("Weather Simulation Program\n\n");

   // Generate 7-day forecast
   for (i = 1; i <= 7; i++) {
      temperature = rand() % 50 + 50;  // Temperature between 50 and 100 degrees
      humidity = rand() % 50 + 50;     // Humidity between 50 and 100 percent
      pressure = rand() % 101 + 900;   // Pressure between 900 and 1000 millibars
      windspeed = rand() % 51;         // Windspeed between 0 and 50 mph

      printf("Day %d:\n", i);
      printf("Temperature: %d degrees F\n", temperature);
      printf("Humidity: %d%%\n", humidity);
      printf("Pressure: %d millibars\n", pressure);
      printf("Windspeed: %d mph\n", windspeed);
      printf("\n");
   }

   // Wait for user to exit program
   printf("Press enter to exit program...");
   getchar();

   return 0;
}