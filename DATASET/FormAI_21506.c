//FormAI DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int hour = 0;
  int temp = 0;
  int humidity = 0;
  int pressure = 0;
  srand(time(NULL));

  printf("Welcome to the Weather Simulator!\n\n");

  // Generate random data every hour for 24 hours
  for (hour = 0; hour < 24; hour++) {

    // Generate temperature between -20 and 40 degrees Celsius
    temp = rand() % 61 - 20;

    // Generate humidity between 0 and 100 percent
    humidity = rand() % 101;

    // Generate pressure between 900 and 1100 millibars
    pressure = rand() % 201 + 900;

    // Output the current weather data
    printf("Hour %d - Temperature: %dC - Humidity: %d%% - Pressure: %dmb\n", hour+1, temp, humidity, pressure);
  }

  printf("\nThank you for using the Weather Simulator!\n");

  return 0;
}