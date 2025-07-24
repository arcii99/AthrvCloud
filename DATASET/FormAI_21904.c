//FormAI DATASET v1.0 Category: Weather simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMPERATURE_RANGE 50
#define PRECIPITATION_RANGE 100

int main(void) {
  // Seed random number generator with current time
  srand(time(NULL));

  int temperature = 70; // Starting temperature (degrees Fahrenheit)
  int precipitation = 0; // Starting precipitation (percent chance of rain)

  // Print starting conditions
  printf("Temperature: %d F\n", temperature);
  printf("Precipitation: %d%% chance of rain\n", precipitation);

  // Simulate 7 days of weather
  for (int i = 1; i <= 7; i++) {
    // Randomly adjust temperature
    int temperature_change = rand() % TEMPERATURE_RANGE - (TEMPERATURE_RANGE / 2);
    temperature += temperature_change;

    // Randomly adjust precipitation
    int precipitation_change = rand() % PRECIPITATION_RANGE;
    precipitation = precipitation_change;

    // Print daily conditions
    printf("\nDay %d:\n", i);
    printf("Temperature: %d F (%s%d)\n", temperature, temperature_change > 0 ? "+" : "", temperature_change);
    printf("Precipitation: %d%% chance of rain (%s%d%%)\n", precipitation, precipitation_change > 50 ? "+" : "", precipitation_change);

    // Determine weather forecast
    printf("Forecast: ");
    if (temperature > 80 && precipitation >= 50) {
      printf("Hot with a chance of thunderstorms");
    } else if (temperature > 80) {
      printf("Hot and dry");
    } else if (temperature > 70 && precipitation >= 50) {
      printf("Warm with a chance of rain");
    } else if (temperature > 70) {
      printf("Warm and humid");
    } else if (temperature > 60 && precipitation >= 50) {
      printf("Cool with a chance of rain");
    } else if (temperature > 60) {
      printf("Cool and breezy");
    } else {
      printf("Cold and frosty");
    }
  }

  return 0;
}