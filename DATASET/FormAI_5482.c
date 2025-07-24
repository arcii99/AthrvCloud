//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   // Declare variables
   int temperature, humidity, motion;
   char light, fan, door;
   
   // Set initial values
   temperature = 25;
   humidity = 50;
   motion = 0;
   light = 'O';
   fan = 'O';
   door = 'C';

   // Print current status
   printf("Current temperature: %d degrees Celsius\n", temperature);
   printf("Current humidity: %d%%\n", humidity);
   printf("Motion detection status: %d\n", motion);
   printf("Light status: %c\n", light);
   printf("Fan status: %c\n", fan);
   printf("Door status: %c\n\n", door);

   // Loop through time
   for(int i = 0; i < 24; i++)
   {
      // Generate random values for temperature and humidity
      srand(time(NULL));
      temperature = rand() % 31;
      humidity = rand() % 101;

      // Check motion detection
      if(rand() % 2 == 0)
      {
         motion = 1;
      }
      else
      {
         motion = 0;
      }

      // Control lights
      if(motion == 1)
      {
         light = 'I';
      }
      else
      {
         light = 'O';
      }

      // Control fan
      if(temperature > 30 && humidity > 60)
      {
         fan = 'I';
      }
      else
      {
         fan = 'O';
      }

      // Control door
      if(rand() % 2 == 0)
      {
         door = 'C';
      }
      else
      {
         door = 'O';
      }

      // Print current status
      printf("Time: %d:00\n", i);
      printf("Current temperature: %d degrees Celsius\n", temperature);
      printf("Current humidity: %d%%\n", humidity);
      printf("Motion detection status: %d\n", motion);
      printf("Light status: %c\n", light);
      printf("Fan status: %c\n", fan);
      printf("Door status: %c\n\n", door);
   }

   return 0;
}