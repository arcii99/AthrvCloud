//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature = 25;
   int humidity = 55;
   int wind_direction = 1;
   int wind_speed = 10;
   int rain_intensity = 0;
   int storm_intensity = 0;
   int total_time = 0;
   int time_increment = 5;

   printf("======== CYBERPUNK WEATHER SIMULATION ========\n\n");

   while (total_time < 1440) {
      printf("[Time: %d:00]\n", total_time / 60);
      printf("Temperature: %d °C\n", temperature);
      printf("Humidity: %d %%\n", humidity);
      printf("Wind Direction: %d\n", wind_direction);
      printf("Wind Speed: %d km/h\n", wind_speed);
      printf("Rain Intensity: %d mm/h\n", rain_intensity);
      printf("Storm Intensity: %d %%\n\n", storm_intensity);

      // Randomly generate values for temperature, humidity, and wind speed
      srand(time(NULL)); 
      int temp_change = rand() % 5;
      temperature += temp_change - 2;

      srand(time(NULL)); 
      int humid_change = rand() % 5;
      humidity += humid_change - 2;

      srand(time(NULL)); 
      int wind_change = rand() % 15;
      wind_speed += wind_change - 7;

      // Change wind direction randomly every hour
      if (total_time % 60 == 0) {
         srand(time(NULL)); 
         wind_direction = rand() % 8;
      }

      // Generate rain intensity and storm intensity based on humidity and wind speed
      rain_intensity = (humidity / 10) * (wind_speed / 20);
      storm_intensity = (humidity / 10) * (wind_speed / 10);

      // Increase storm intensity randomly every 6 hours
      if (total_time % 360 == 0) {
         srand(time(NULL)); 
         storm_intensity += rand() % 10;
      }

      // Increase rain intensity randomly every hour
      srand(time(NULL)); 
      rain_intensity += rand() % 2;

      // Reduce storm intensity randomly every 12 hours
      if (total_time % 720 == 0) {
         srand(time(NULL)); 
         storm_intensity -= rand() % 5;
      }

      total_time += time_increment;
   }

   printf("Simulation complete.\n");

   return 0;
}