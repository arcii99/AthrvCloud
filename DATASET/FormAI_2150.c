//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed random number generator with current time
  int temperature = rand() % 100; // generate random temperature between 0 and 99
  int humidity = rand() % 100; // generate random humidity between 0 and 99

  // display current weather conditions
  printf("Temperature: %d degrees Fahrenheit\n", temperature);
  printf("Humidity: %d percent\n", humidity);

  // check for extreme weather conditions
  if (temperature > 90) {
    printf("Hot weather advisory: try to stay indoors and drink plenty of fluids.\n");
  } else if (temperature < 30) {
    printf("Cold weather advisory: make sure to dress warmly and cover all exposed skin.\n");
  }

  if (humidity > 80) {
    printf("Humid weather advisory: try to avoid being outdoors for extended periods of time.\n");
  } else if (humidity < 20) {
    printf("Dry weather advisory: make sure to stay hydrated and moisturized.\n");
  }

  return 0;
}