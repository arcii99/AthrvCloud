//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Seed the random number generator with the current time
  srand(time(NULL));
  
  // Create variables for temperature, humidity, and precipitation
  int temperature = rand() % 61 - 20; // Random temperature between -20 and 40 Celsius
  int humidity = rand() % 71 + 30; // Random humidity between 30 and 100 percent
  int precipitation = rand() % 101; // Random precipitation percentage
  
  // Check if it's raining
  if (precipitation > 50) {
    printf("It's raining!\n");
  } else {
    printf("It's not raining.\n");
  }
  
  // Check if it's hot or cold
  if (temperature > 30) {
    printf("It's hot outside.\n");
  } else if (temperature < 10) {
    printf("It's cold outside.\n");
  } else {
    printf("It's a nice day outside.\n");
  }
  
  // Check if it's humid
  if (humidity > 70) {
    printf("It's humid outside.\n");
  } else {
    printf("It's not very humid outside.\n");
  }
  
  // Print the current weather conditions
  printf("Current weather conditions:\n");
  printf("Temperature: %d Celsius\n", temperature);
  printf("Humidity: %d percent\n", humidity);
  printf("Precipitation: %d percent\n", precipitation);

  return 0;
}