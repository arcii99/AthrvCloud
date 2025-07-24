//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // Seed the random generator

  int temperature = 70; // Starting temperature
  int humidity = 50; // Starting humidity
  int pressure = 1013; // Starting pressure

  printf("Welcome to the Weather Simulation Program!\n");

  // Loop through 24 hours
  for (int hour = 0; hour < 24; hour++) {
    printf("Hour %d:\n", hour);
    
    // Calculate temperature change
    int temperature_change = (rand() % 21) - 10;
    temperature += temperature_change;
    printf("Temperature: %d\n", temperature);

    // Calculate humidity change
    int humidity_change = (rand() % 11) - 5;
    humidity += humidity_change;
    printf("Humidity: %d\n", humidity);

    // Calculate pressure change
    int pressure_change = (rand() % 31) - 15;
    pressure += pressure_change;
    printf("Pressure: %d\n", pressure);

    printf("\n");
  }

  printf("Thank you for using the Weather Simulation Program!\n");

  return 0;
}