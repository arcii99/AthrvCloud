//FormAI DATASET v1.0 Category: Weather simulation ; Style: portable
/* Weather Simulation Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random number generator

   /* Define variables for weather simulation */
   int weather, temperature, humidity;
   char weather_str[10];

   /* Generate random weather conditions */
   weather = rand() % 3;
   if (weather == 0) {
      strcpy(weather_str, "Sunny");
      temperature = rand() % 20 + 25; // temperature between 25-45 degrees Celsius
      humidity = rand() % 10 + 50; // humidity between 50-60%
   }
   else if (weather == 1) {
      strcpy(weather_str, "Cloudy");
      temperature = rand() % 10 + 20; // temperature between 20-30 degrees Celsius
      humidity = rand() % 20 + 70; // humidity between 70-90%
   }
   else {
      strcpy(weather_str, "Rainy");
      temperature = rand() % 5 + 15; // temperature between 15-20 degrees Celsius
      humidity = rand() % 30 + 80; // humidity between 80-100%
   }

   /* Display weather conditions */
   printf("Current weather: %s\n", weather_str);
   printf("Temperature: %dC\n", temperature);
   printf("Humidity: %d%%\n", humidity);

   return 0;
}