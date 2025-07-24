//FormAI DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature = 0;
  int humidity = 0;

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random temperature between -10 and 40 degrees Celsius
  temperature = rand() % 51 - 10;

  // Generate a random humidity between 0% and 100%
  humidity = rand() % 101;

  printf("Current temperature: %d degrees Celsius\n", temperature);
  printf("Current humidity: %d%%\n", humidity);

  // Determine weather conditions based on temperature and humidity
  if (temperature <= 0) {
    printf("It's very cold outside.\n");
    if (humidity < 40) {
      printf("The air is very dry.\n");
    } else if (humidity >= 40 && humidity < 80) {
      printf("The air is moderately humid.\n");
    } else {
      printf("The air is very humid.\n");
    }
  } else if (temperature > 0 && temperature <= 10) {
    printf("It's quite cold outside.\n");
    if (humidity < 40) {
      printf("The air is very dry.\n");
    } else if (humidity >= 40 && humidity < 80) {
      printf("The air is moderately humid.\n");
    } else {
      printf("The air is very humid.\n");
    }
  } else if (temperature > 10 && temperature <= 20) {
    printf("It's mild outside.\n");
    if (humidity < 40) {
      printf("The air is very dry.\n");
    } else if (humidity >= 40 && humidity < 80) {
      printf("The air is moderately humid.\n");
    } else {
      printf("The air is very humid.\n");
    }
  } else if (temperature > 20 && temperature <= 30) {
    printf("It's warm outside.\n");
    if (humidity < 40) {
      printf("The air is very dry.\n");
    } else if (humidity >= 40 && humidity < 80) {
      printf("The air is moderately humid.\n");
    } else {
      printf("The air is very humid.\n");
    }
  } else {
    printf("It's very hot outside.\n");
    if (humidity < 40) {
      printf("The air is very dry.\n");
    } else if (humidity >= 40 && humidity < 80) {
      printf("The air is moderately humid.\n");
    } else {
      printf("The air is very humid.\n");
    }
  }

  return 0;
}