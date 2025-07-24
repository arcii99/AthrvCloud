//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0)); // set seed for random number generator
  
  int battery_life = 100; // initialize battery life to 100%
  int signal_strength = 5; // initialize signal strength to the maximum
  
  printf("Welcome to the Remote Control Vehicle Simulation\n");
  printf("----------------------------------------------\n\n");

  while (battery_life > 0) {

    // simulate signal interference by lowering the signal strength randomly
    signal_strength -= rand() % 3;

    // if the signal strength goes below 0, reset it to the maximum value
    if (signal_strength < 0) {
      signal_strength = 5;
    }

    printf("Battery Life: %d%%\n", battery_life);
    printf("Signal Strength: %d/5\n\n", signal_strength);

    if (signal_strength > 2) {
      printf("Vehicle is moving forward\n");
    } else {
      printf("Lost signal - vehicle has stopped\n");
    }

    printf("----------------------------------------------\n");

    battery_life -= rand() % 10; // simulate battery drain
  }

  printf("\nBattery depleted - simulation over\n\n");

  return 0;
}