//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  srand(time(NULL)); // Seed the random number generator
  
  int temperature = rand() % 101 - 50; // Random temperature between -50 and 50
  int clouds = rand() % 101; // Random cloud cover percentage

  printf("Today's temperature is: %d degrees Celsius\n", temperature);
  printf("Today's cloud cover is: %d percent\n", clouds);

  if (temperature <= 0) {
    printf("It's freezing outside!\n");

    if (clouds >= 50) {
      printf("It's snowing right now.\n");
    } else {
      printf("It's clear outside.\n");
    }
  } else if (temperature > 0 && temperature <= 20) {
    printf("It's a bit chilly outside.\n");

    if (clouds >= 50) {
      printf("It might rain today.\n");
    } else {
      printf("It's clear outside.\n");
    }
  } else if (temperature > 20 && temperature <= 30) {
    printf("It's a beautiful day!\n");

    if (clouds >= 50) {
      printf("It might rain later today.\n");
    } else {
      printf("It's clear outside.\n");
    }
  } else if (temperature > 30) {
    printf("It's really hot outside!\n");

    if (clouds >= 50) {
      printf("It might storm later today.\n");
    } else {
      printf("It's clear outside.\n");
    }
  }

  return 0;
}