//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  // Define variables for weather simulation
  int temperature, humidity, wind_speed, precipitation_chance;
  
  // Set seed for random number generation
  srand(time(0));
  
  // Generate random values for weather variables
  temperature = rand() % 41 - 20; // Temperature between -20 and 20 Celsius
  humidity = rand() % 101; // Humidity between 0 and 100%
  wind_speed = rand() % 51; // Wind speed between 0 and 50 km/h
  precipitation_chance = rand() % 101; // Precipitation chance between 0 and 100%
  
  // Print out weather report
  printf("Today's weather report:\n");
  printf("Temperature: %d Celsius\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind speed: %d km/h\n", wind_speed);
  
  // Determine precipitation status based on chance of precipitation
  if(precipitation_chance >= 50) {
    printf("Chance of precipitation: %d%% - It's going to rain today!\n", precipitation_chance);
  } else {
    printf("Chance of precipitation: %d%% - Looks like it will be a dry day.\n", precipitation_chance);
  }
  
  return 0; 
}