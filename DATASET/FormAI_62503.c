//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7     // maximum number of days in simulation
#define MAX_HOURS 24   // maximum number of hours in a day
#define MAX_TEMP 100   // maximum temperature
#define MIN_TEMP -100  // minimum temperature

int main() {
  int i, j;
  int weather[MAX_DAYS][MAX_HOURS];  // 2D array to store weather data
  int sumTemp, avgTemp;  // variables to calculate average temperature
  int maxTemp = MIN_TEMP, minTemp = MAX_TEMP;  // variables to store maximum and minimum temperatures
  srand(time(NULL));  // seed for random number generator
  
  // Generate weather data for each day and each hour
  for (i = 0; i < MAX_DAYS; i++) {
    printf("Day %d:\n", i+1);
    sumTemp = 0;
    for (j = 0; j < MAX_HOURS; j++) {
      weather[i][j] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;  // generate random temperature between min and max
      printf("Hour %d: %d\n", j+1, weather[i][j]);
      sumTemp += weather[i][j];
      if (weather[i][j] > maxTemp) maxTemp = weather[i][j];
      if (weather[i][j] < minTemp) minTemp = weather[i][j];
    }
    avgTemp = sumTemp / MAX_HOURS;
    printf("Average temperature for day %d: %d\n\n", i+1, avgTemp);
  }
  
  // Print overall statistics
  printf("Overall statistics:\n");
  printf("Maximum temperature: %d\n", maxTemp);
  printf("Minimum temperature: %d\n", minTemp);
  
  return 0;
}