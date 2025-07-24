//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   // Initializing the random seed
   srand(time(NULL));

   // Generating random weather values
   int temperature = rand() % 101 - 50; // Temperature ranges from -50 to 50
   int humidity = rand() % 101; // Humidity ranges from 0 to 100
   int wind_speed = rand() % 101; // Wind speed ranges from 0 to 100
   int precipitation = rand() % 101; // Precipitation ranges from 0 to 100
   
   // Determining weather conditions based on generated values
   char* condition;
   if (temperature >= 30 && humidity >= 70 && precipitation >= 50) {
      condition = "Thunderstorms";
   } else if (temperature >= 20 && humidity >= 60 && precipitation >= 40) {
      condition = "Rainy";
   } else if (temperature >= 15 && humidity >= 50 && precipitation >= 30) {
      condition = "Cloudy";
   } else if (temperature >= 10 && humidity >= 40 && wind_speed >= 60) {
      condition = "Windy";
   } else {
      condition = "Sunny";
   }
   
   // Outputting the weather simulation
   printf("Today's weather simulation:\n");
   printf("Temperature: %d degrees Celsius\n", temperature);
   printf("Humidity: %d percent\n", humidity);
   printf("Wind speed: %d km/h\n", wind_speed);
   printf("Precipitation: %d percent\n", precipitation);
   printf("Condition: %s\n", condition);
   
   return 0;
}