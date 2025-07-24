//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random seed
   double temperature = ((double)rand()/(double)RAND_MAX) * 50; // generate temperature between 0 and 50 degrees Celsius 
   int humidity = rand() % 100; // generate humidity between 0 and 100%
   char* weather = NULL; // initialize weather string

   if (temperature < 0) { // if temperature is below freezing
      weather = "Snowy"; // set weather to Snowy
   } else if (temperature >= 0 && temperature < 10 && humidity < 50) { // if temperature is between 0 and 10 degrees Celsius and humidity is less than 50%
      weather = "Sunny"; // set weather to Sunny
   } else if (temperature >= 0 && temperature < 10 && humidity >= 50) { // if temperature is between 0 and 10 degrees Celsius and humidity is 50% or greater
      weather = "Foggy"; // set weather to Foggy
   } else if (temperature >= 10 && temperature < 20 && humidity < 50) { // if temperature is between 10 and 20 degrees Celsius and humidity is less than 50%
      weather = "Partly Cloudy"; // set weather to Partly Cloudy
   } else if (temperature >= 10 && temperature < 20 && humidity >= 50) { // if temperature is between 10 and 20 degrees Celsius and humidity is 50% or greater
      weather = "Rainy"; // set weather to Rainy
   } else if (temperature >= 20 && temperature < 30 && humidity < 50) { // if temperature is between 20 and 30 degrees Celsius and humidity is less than 50%
      weather = "Clear"; // set weather to Clear
   } else if (temperature >= 20 && temperature < 30 && humidity >= 50) { // if temperature is between 20 and 30 degrees Celsius and humidity is 50% or greater
      weather = "Thunderstorms"; // set weather to Thunderstorms
   } else if (temperature >= 30 && temperature < 40) { // if temperature is between 30 and 40 degrees Celsius
      weather = "Hot"; // set weather to Hot
   } else if (temperature >= 40 && temperature <= 50) { // if temperature is between 40 and 50 degrees Celsius
      weather = "Scorching"; // set weather to Scorching
   }

   printf("Temperature: %.2f degrees Celsius\n", temperature); // print temperature
   printf("Humidity: %d%%\n", humidity); // print humidity
   printf("Weather: %s\n", weather); // print weather
  
   return 0;
}