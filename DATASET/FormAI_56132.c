//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));
  
  // Set up the remote control vehicle
  int x = 0;
  int y = 0;
  
  // Start the simulation loop
  while (1) {
    // Generate a random command
    int command = rand() % 4;
    
    // Apply the command to the vehicle's position
    switch(command) {
      case 0:
        printf("Moving forward\n");
        y++;
        break;
      case 1:
        printf("Moving backward\n");
        y--;
        break;
      case 2:
        printf("Turning left\n");
        x--;
        break;
      case 3:
        printf("Turning right\n");
        x++;
        break;
    }
    
    // Check if the vehicle has reached the edge of the simulation area
    if (x < 0 || x > 10 || y < 0 || y > 10) {
      printf("Vehicle has reached the edge of the simulation area. Stopping.\n");
      break;
    }
    
    // Wait for a short period of time before generating the next command
    printf("Current position: (%d, %d)\n", x, y);
    printf("Waiting for 1 second...\n");
    sleep(1);
  }
  
  return 0;
}