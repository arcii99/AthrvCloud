//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define HOURS 24
#define MAX_TEMPERATURE 100
#define MAX_PRECIPITATION 10

int main(void) {
  srand(time(NULL)); // Seed random temperature and precipitation values

  // Initialize arrays for temperature and precipitation values
  int temps[DAYS][HOURS];
  int precip[DAYS][HOURS];

  // Generate temperature and precipitation values for each day and hour
  for (int i = 0; i < DAYS; i++) {
    for (int j = 0; j < HOURS; j++) {
      temps[i][j] = rand() % MAX_TEMPERATURE;
      precip[i][j] = rand() % MAX_PRECIPITATION;
    }
  }

  // Display temperature and precipitation values for each day and hour
  for (int i = 0; i < DAYS; i++) {
    printf("\nDay %d:\n", i+1);
    for (int j = 0; j < HOURS; j++) {
      printf("Hour %d: Temperature: %d degrees Fahrenheit | Precipitation: %d inches\n", j+1, temps[i][j], precip[i][j]);
    }
  }

  return 0;
}