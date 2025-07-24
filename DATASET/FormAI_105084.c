//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL));
   int temperature, humidity, cloudiness, wind_speed, pressure, storm_chance;

   for(int i = 0; i < 7; i++)
   {
        temperature = rand() % 40 - 10;
        humidity = rand() % 100;
        cloudiness = rand() % 101;
        wind_speed = rand() % 61;
        pressure = rand() % 1001 + 900;
        storm_chance = 0;

        if(cloudiness >= 50)
        {
            storm_chance = rand() % 101;
        }

        printf("Day %d:\n", i+1);
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Cloudiness: %d%%\n", cloudiness);
        printf("Wind Speed: %d km/h\n", wind_speed);
        printf("Pressure: %d hPa\n", pressure);

        if(storm_chance > 0)
        {
            printf("Attention! There is a %d%% chance of a storm today.\n", storm_chance);
        }

        printf("\n");
   }

   return 0;
}