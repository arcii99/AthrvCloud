//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature, humidity, wind_speed;
   srand(time(0)); // seed random number generator

   printf("Weather Simulation:\n");

   // randomly generate temperature between -10 and 40 degree Celsius
   temperature = rand() % 51 - 10;
   printf("Temperature: %d \u2103\n", temperature);

   // randomly generate humidity between 0 and 100 percent
   humidity = rand() % 101;
   printf("Humidity: %d%%\n", humidity);

   // randomly generate wind speed between 0 and 50 km/h
   wind_speed = rand() % 51;
   printf("Wind Speed: %d km/h\n", wind_speed);

   return 0;
}