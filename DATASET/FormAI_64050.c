//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator

  int numDays = 14; // number of days to simulate
  float temperatures[numDays]; // array to store daily temperatures

  float maxTemp = 30.5; // maximum temperature in Celsius
  float minTemp = -10.0; // minimum temperature in Celsius
  float tempRange = maxTemp - minTemp; // temperature range in Celsius

  float previousTemperature = 20.0; // starting temperature in Celsius

  for(int i = 0; i < numDays; i++) {
    // generate a random temperature change between -2.5C and 2.5C
    float tempChange = ((float)rand()/(float)(RAND_MAX)) * tempRange - tempRange/2.0;
    
    // calculate the new temperature for the day
    float newTemperature = previousTemperature + tempChange;

    // check if the new temperature is within bounds, and adjust if necessary
    if(newTemperature > maxTemp) {
      newTemperature = maxTemp - (newTemperature - maxTemp);
    } else if(newTemperature < minTemp) {
      newTemperature = minTemp - (newTemperature - minTemp);
    }

    // add the new temperature to the array
    temperatures[i] = newTemperature;

    // update previous temperature for the next iteration
    previousTemperature = newTemperature;
  }

  // display the results
  printf("14 Day Weather Simulation\n\n");
  printf("Day\tTemperature (C)\n");
  printf("--------------------\n");
  for(int i = 0; i < numDays; i++) {
    printf("%d\t%.2f\n", i+1, temperatures[i]);
  }

  return 0;
}