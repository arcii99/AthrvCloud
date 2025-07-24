//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Vehicle variables
  int speed = 0;
  int direction = 0;

  // Remote control variables
  int battery = 100;
  int signal_strength = 100;

  // Simulation loop
  while (1) {
    // Generate random speed and direction for the vehicle
    srand(time(NULL));
    speed = rand() % 101;
    direction = rand() % 360;

    // Show current vehicle data
    printf("Vehicle speed: %d mph\n", speed);
    printf("Vehicle direction: %d degrees\n", direction);

    // Update battery and signal_strength
    battery--;
    signal_strength--;

    // Check if battery or signal_strength is low
    if (battery <= 10) {
      printf("Battery low! Please replace the batteries.\n");
      break;
    }
    if (signal_strength <= 10) {
      printf("Signal strength low! Please move closer to the vehicle.\n");
      break;
    }

    // Wait for 1 second before next simulation loop
    printf("Simulating next second...\n\n");
    sleep(1);
  }

  return 0;
}