//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  
  int traffic[10]; // This array will store the number of cars at each point in the road
  int i, j;
  
  // Initialize traffic array randomly
  for (i = 0; i < 10; i++) {
    traffic[i] = rand() % 20;
  }
  
  // Print starting traffic conditions
  printf("Starting Traffic:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", traffic[i]);
  }
  printf("\n");
  
  // Simulate traffic flow for 10 time steps
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      // Attempt to move a car from the current position to the next position
      if (traffic[j] > 0 && j < 9 && traffic[j+1] < 20) {
        traffic[j]--;
        traffic[j+1]++;
      }
    }
    
    // Print current traffic conditions
    printf("Time Step %d:\n", i+1);
    for (j = 0; j < 10; j++) {
      printf("%d ", traffic[j]);
    }
    printf("\n");
  }
  
  return 0;
}