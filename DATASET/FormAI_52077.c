//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE -20

int main() {
  srand(time(NULL)); // seed random number generator with current time

  float temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE; // generate a random temperature within the range

  int humidity = rand() % 101; // generate a random humidity level from 0 to 100

  int windy = rand() % 2; // determine if it's windy (0 or 1)

  int cloudy = rand() % 2; // determine if it's cloudy (0 or 1)

  printf("Current weather simulation:\n\n");

  printf("Temperature: %.2f degrees Celsius\n", temperature);

  if (temperature <= 0) {
    printf("Freezing temperatures! Make sure to bundle up.\n");
  } else if (temperature < 10) {
    printf("Chilly temperatures. Bring a light jacket.\n");
  } else if (temperature < 20) {
    printf("Mild temperatures. A sweater should suffice.\n");
  } else if (temperature < 30) {
    printf("Warm temperatures. T-shirt weather!\n");
  } else {
    printf("Hot temperatures! Stay hydrated.\n");
  }

  printf("Humidity: %d%%\n", humidity);

  if (humidity < 30) {
    printf("Dry conditions today.\n");
  } else if (humidity < 60) {
    printf("Average humidity levels. Nothing out of the ordinary.\n");
  } else {
    printf("High humidity levels today! Be prepared to feel sticky.\n");
  }

  if (windy) {
    printf("Windy conditions today. Hold on to your hats!\n");
  } else {
    printf("Calm winds today.\n");
  }

  if (cloudy) {
    printf("Cloudy skies today. Might want to bring an umbrella.\n");
  } else {
    printf("Clear skies today. Have a great day outdoors!\n");
  }

  return 0;
}