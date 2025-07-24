//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEVEL 3 // Maximum altitude level
#define MIN_TEMP -10 // Minimum temperature in celsius
#define MAX_TEMP 30 // Maximum temperature in celsius

void weather_report(int day, int altitude, int temperature);

int main()
{
  srand(time(0)); // To generate random numbers
  
  int days = 7; // Number of days to simulate weather for
  int altitude = 0; // Starting altitude
  
  // Simulating weather for each day
  for(int i=1; i<=days; i++)
  {
    printf("Day %d\n", i);
    weather_report(i, altitude, rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP); // Generating random temperature
    altitude += rand() % (MAX_LEVEL + 1); // Moving to a random altitude level
  }
  
  return 0;
}

void weather_report(int day, int altitude, int temperature)
{
  // Checking if the altitude is within bounds
  if(altitude >=0 && altitude <= MAX_LEVEL)
  {
    printf(" - Altitude: %d\n", altitude);
    printf(" - Temperature: %dC\n", temperature);
    
    // Recursively calling weather_report for lower altitude levels
    if(altitude > 0)
    {
      printf(" *** Going lower...\n");
      weather_report(day, altitude - 1, temperature - 3); // Decreasing temperature as altitude decreases
    }
    
    // Recursively calling weather_report for higher altitude levels
    if(altitude < MAX_LEVEL)
    {
      printf(" *** Going higher...\n");
      weather_report(day, altitude + 1, temperature + 2); // Increasing temperature as altitude increases
    }
  }
  else
  {
    printf(" - UNSAFE ALTITUDE LEVEL\n"); // Displaying error message if altitude is not within bounds
  }
}