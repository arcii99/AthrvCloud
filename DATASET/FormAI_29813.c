//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // Initialize seed for random number generator

  int trafficFlow[24];
  int i;
  int totalFlow = 0;

  // Generate random traffic volumes, between 100 and 1000
  for (i = 0; i < 24; i++) {
    trafficFlow[i] = rand() % 901 + 100; // Generate number between 100 and 1000
    totalFlow += trafficFlow[i];
  }

  printf("Hour\tTraffic Volume\n");

  // Print traffic volumes for each hour
  for (i = 0; i < 24; i++) {
    printf("%d\t%d\n", i, trafficFlow[i]);
  }

  printf("Total traffic volume for the day: %d\n", totalFlow);

  return 0;
}