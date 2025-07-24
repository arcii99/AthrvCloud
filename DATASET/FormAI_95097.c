//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for our weather simulation
#define TEMPERATURE_RANGE 100
#define CHANCE_OF_RAIN 50
#define CHANCE_OF_SNOW 20

int main(void) {
  int temperature, chance_of_rain, chance_of_snow;
  char weather[10];
  
  srand(time(NULL));  // Seed random number generator with current time
  
  // Choose a random starting temperature
  temperature = rand() % TEMPERATURE_RANGE;
  
  printf("The current temperature is %d degrees Fahrenheit.\n\n", temperature);
  
  // Loop for 7 days
  for (int i = 0; i < 7; i++) {
    
    // Randomly determine the chance of rain and snow
    chance_of_rain = rand() % 100;
    chance_of_snow = rand() % 100;
    
    // Determine the weather based on the current temperature and chance of rain and snow
    if (temperature >= 80) {
      strcpy(weather, "hot");
    } else if (temperature >= 60) {
      if (chance_of_rain < CHANCE_OF_RAIN) {
        strcpy(weather, "rainy");
      } else {
        strcpy(weather, "sunny");
      }
    } else if (temperature >= 40) {
      if (chance_of_snow < CHANCE_OF_SNOW) {
        strcpy(weather, " snowy");
      } else {
        strcpy(weather, "cloudy");
      }
    } else {
      strcpy(weather, "cold");
    }
    
    // Simulate a temperature change for the day
    temperature += (rand() % 11) - 5;
    
    // Ensure the temperature stays between 0 and 100
    if (temperature < 0) {
      temperature = 0;
    } else if (temperature > 100) {
      temperature = 100;
    }
    
    // Print out the weather for the day
    printf("Day %d: The weather is %s and the temperature is %d degrees Fahrenheit.\n", i+1, weather, temperature);
  }
  
  return 0;
}