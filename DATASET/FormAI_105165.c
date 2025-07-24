//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Constants for temperature and weather conditions
  const int MIN_TEMP = -10;
  const int MAX_TEMP = 40;
  const int SUNNY_THRESHOLD = 25;

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random temperature between MIN_TEMP and MAX_TEMP
  int temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;

  // Determine the weather condition based on temperature
  char* condition;
  if (temperature < 0) {
    condition = "Freezing";
  } else if (temperature < 10) {
    condition = "Cold";
  } else if (temperature < 20) {
    condition = "Cool";
  } else if (temperature < 25) {
    condition = "Mild";
  } else if (temperature < 30) {
    condition = "Warm";
  } else if (temperature < 35) {
    condition = "Hot";
  } else {
    condition = "Scorching";
  }

  // Determine whether it is sunny or not based on temperature
  int isSunny = (temperature >= SUNNY_THRESHOLD);

  // Print the temperature and weather condition
  printf("The current temperature is %d degrees Celsius.\n", temperature);
  printf("The weather condition is %s.\n", condition);

  // If it is sunny, print a message about wearing sunscreen
  if (isSunny) {
    printf("It is sunny outside, so make sure to wear sunscreen!\n");
  }

  return 0;
}