//FormAI DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare variables for temperature and wind speed
  int temp, windSpeed;
  
  // Set the seed for the random number generator
  srand(time(0));
  
  // Generate a random temperature between -20 and 40 degrees Celsius
  temp = rand() % 61 - 20;
  
  // Generate a random wind speed between 0 and 30 km/h
  windSpeed = rand() % 31;

  // Print the current temperature and wind speed
  printf("Current temperature: %d degrees Celsius\n", temp);
  printf("Current wind speed: %d km/h\n", windSpeed);
  
  // Check the temperature and wind speed to simulate weather conditions
  if (temp < 0) {
    printf("It's freezing outside!\n");
    if (windSpeed > 20) {
      printf("Watch out for icy road conditions!\n");
    }
  } else if (temp < 10) {
    printf("It's quite cold, don't forget your jacket!\n");
    if (windSpeed > 10) {
      printf("It's a bit windy, so hold onto your hat!\n");
    }
  } else if (temp < 20) {
    printf("It's a nice day today!\n");
    if (windSpeed > 5) {
      printf("Just a light breeze, nothing too crazy.\n");
    }
  } else {
    printf("It's pretty hot outside!\n");
    if (windSpeed > 15) {
      printf("Be sure to stay hydrated and find some shade!\n");
    }
  }

  return 0;
}