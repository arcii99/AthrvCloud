//FormAI DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Initialize random seed

   const int MIN_TEMP = -30;
   const int MAX_TEMP = 40;
   const int NUM_DAYS = 7;
   const int NUM_HOURS_PER_DAY = 24;

   int temperatures[NUM_DAYS][NUM_HOURS_PER_DAY];

   // Generate temperatures for the week
   for (int day = 0; day < NUM_DAYS; day++) {
      for (int hour = 0; hour < NUM_HOURS_PER_DAY; hour++) {
         temperatures[day][hour] = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
      }
   }

   // Display the temperatures
   printf("Weather Simulation for the Week\n");
   printf("-------------------------------\n");
   printf(" Day  | Hour | Temperature\n");
   printf("-------------------------------\n");

   for (int day = 0; day < NUM_DAYS; day++) {
      for (int hour = 0; hour < NUM_HOURS_PER_DAY; hour++) {
         printf("%3d   | %3d  | %3d\n", day+1, hour, temperatures[day][hour]);
      }
   }

   return 0;
}