//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numReadings = 10;
  int readings[numReadings];
  int minTemp = -20;
  int maxTemp = 50;
  int averageTemp;
  int currentTemp;

  srand(time(NULL));

  // Initialize readings array with random temperatures between minTemp and maxTemp
  for (int i = 0; i < numReadings; i++) {
    readings[i] = rand() % (maxTemp - minTemp + 1) + minTemp;
    printf("Reading %d: %d Celsius\n", i+1, readings[i]);
  }

  // Calculate average temperature
  for (int i = 0; i < numReadings; i++) {
    averageTemp += readings[i];
  }
  averageTemp /= numReadings;

  printf("\nCurrent Temperature: %d Celsius\n", averageTemp);

  // Check if temperature is too high or too low
  if (averageTemp > 30) {
    printf("CAUTION: Temperature is too high!\n");
  } else if (averageTemp < 0) {
    printf("CAUTION: Temperature is too low!\n");
  } else {
    printf("Temperature is within acceptable range.\n");
  }

  return 0;
}