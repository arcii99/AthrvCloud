//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 10 // Maximum number of years simulated

int main() {
  int years;
  float temperature[MAX_YEARS][12]; // 2D array to store temperature data

  srand(time(NULL)); // Initialize random number generator

  // Loop through each year
  for (years = 0; years < MAX_YEARS; years++) {
    printf("Year %d\n", years + 1);

    // Loop through each month
    for (int month = 0; month < 12; month++) {
      // Generate a random temperature between -10 and 40 degrees Celsius
      float temp = (rand() % 50) - 10;

      // Print the temperature for the current month
      printf("Month %d: %.1f degrees Celsius\n", month + 1, temp);

      temperature[years][month] = temp; // Store temperature data in array
    }

    printf("\n");
  }

  // Find the average temperature for each year
  printf("Average temperatures:\n");
  for (years = 0; years < MAX_YEARS; years++) {
    float avgTemp = 0;

    // Loop through each month and add the temperature to the total
    for (int month = 0; month < 12; month++) {
      avgTemp += temperature[years][month];
    }

    avgTemp /= 12; // Divide by number of months to get average

    printf("Year %d: %.1f degrees Celsius\n", years + 1, avgTemp);
  }

  return 0;
}