//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int temperature = rand() % 51 - 20; // generate random temperature between -20°C and 30°C
  char sky[4][10] = {"Sunny", "Cloudy", "Rainy", "Stormy"}; // array of sky conditions
  int condition = rand() % 4; // randomly select a sky condition
  printf("Today's weather: %s, %d°C\n", sky[condition], temperature);

  // simulate weather changes over time
  for (int i = 1; i <= 7; i++) {
    int temp_diff = rand() % (10 + i) - 5; // generate random temperature difference for the day
    temperature += temp_diff;
    if (temperature > 30) {
      temperature = 30;
    } else if (temperature < -20) {
      temperature = -20;
    }
    int new_condition = condition;
    if (condition == 0 && temp_diff >= 5) {
      new_condition = 1; // sunny to cloudy
    } else if (condition == 1 && (temp_diff <= -5 || temperature <= 0)) {
      new_condition = 2; // cloudy to rainy
    } else if (condition == 2 && temp_diff <= -5) {
      new_condition = 3; // rainy to stormy
    } else if (condition == 3 && temp_diff >= 5) {
      new_condition = 2; // stormy to rainy
    }
    if (new_condition != condition) {
      condition = new_condition;
      printf("Day %d: %s, %d°C\n", i, sky[condition], temperature);
    } else {
      printf("Day %d: No change, %d°C\n", i, temperature);
    }
  }
  return 0;
}