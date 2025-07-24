//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, j, k;

  srand(time(NULL)); // seeds random number generator with time

  int temperature[7]; // array to hold temperatures for the week
  int precipitation[7]; // array to hold precipitation amounts for the week

  printf("Welcome to the Weekly Weather Simulator!\n\n");

  // loop through each day of the week to randomly generate temperatures and precipitation
  for(i = 0; i < 7; i++) {
    temperature[i] = (rand() % 30) + 50; // generates temperature between 50 and 80 degrees Fahrenheit
    precipitation[i] = (rand() % 100); // generates precipitation amount between 0 and 99 inches
  }

  // print out the weather forecast for the week
  printf("Weekly Weather Forecast:\n");
  printf("-------------------------\n");

  for(j = 0; j < 7; j++) {
    printf("Day %d: ", j+1); // j+1 used for clarity in presenting day number

    // print out temperature string
    if(temperature[j] > 70) {
      printf("Hot ");
    } else if (temperature[j] > 55) {
      printf("Mild ");
    } else {
      printf("Cold ");
    }

    // print out precipitation string
    if(precipitation[j] > 50) {
      printf("with heavy rain.\n");
    } else if(precipitation[j] > 25) {
      printf("with light rain.\n");
    } else {
      printf("with no rain.\n");
    }
  }

  return 0;
}