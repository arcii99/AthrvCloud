//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // initialize random seed

  int temperature = -50 + (rand() % 100); // simulate temperature between -50 to 50 Celsius
  int humidity = rand() % 100; // simulate humidity percentage
  int wind_speed = rand() % 200; // simulate wind speed in km/h
  int precipitation = rand() % 100; // simulate precipitation quantity in mm
  
  printf("Futuristic Weather Simulation\n");
  printf("-----------------------------\n");
  printf("Temperature: %d Celsius\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind Speed: %d km/h\n", wind_speed);
  printf("Precipitation: %d mm\n", precipitation);

  return 0;
}