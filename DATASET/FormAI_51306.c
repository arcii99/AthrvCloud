//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature[24];
  srand(time(NULL)); // set seed for random number generator
  
  // generate random temperatures for each hour of the day
  for (int i = 0; i < 24; i++) {
    temperature[i] = rand() % 41 - 10; // random number between -10 to 30 Celsius degrees
  }
  
  // print out temperature report
  printf("Temperature Report\n");
  printf("==================\n");
  for (int i = 0; i < 24; i++) {
    printf("Hour %d:\t %d Celsius degrees\n", i+1, temperature[i]);
  }
  
  // determine average temperature
  int sum = 0;
  for (int i = 0; i < 24; i++) {
    sum += temperature[i];
  }
  int average = sum / 24;
  
  // print out average temperature
  printf("\nAverage Temperature: %d Celsius degrees\n", average);
  
  // determine highest and lowest temperature
  int highest = temperature[0];
  int lowest = temperature[0];
  for (int i = 1; i < 24; i++) {
    if (temperature[i] > highest) {
      highest = temperature[i];
    }
    if (temperature[i] < lowest) {
      lowest = temperature[i];
    }
  }
  
  // print out highest and lowest temperature
  printf("\nHighest Temperature: %d Celsius degrees\n", highest);
  printf("Lowest Temperature: %d Celsius degrees\n", lowest);
  
  // determine if there is a heatwave or cold snap
  int countHeatWave = 0;
  int countColdSnap = 0;
  for (int i = 0; i < 24; i++) {
    if (temperature[i] >= 30) {
      countHeatWave++;
    }
    if (temperature[i] <= -5) {
      countColdSnap++;
    }
  }
  
  // print out heatwave and coldsnap results
  if (countHeatWave >= 3) {
    printf("\nHeatwave Alert! Temperature is above 30 Celsius degrees for %d hours\n", countHeatWave);
  } else {
    printf("\nNo Heatwave Alert\n");
  }
  
  if (countColdSnap >= 3) {
    printf("Coldsnap Alert! Temperature is below -5 Celsius degrees for %d hours\n", countColdSnap);
  } else {
    printf("No Coldsnap Alert\n");
  }
  
  return 0;
}