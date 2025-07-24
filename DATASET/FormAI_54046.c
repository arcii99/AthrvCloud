//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int speed = 0, direction = 0;
  // define the speed and direction variables
  
  while(1) {
    printf("Enter speed (0-100): ");
    scanf("%d", &speed); // get user input for speed
    
    if(speed < 0 || speed > 100) { // check if speed input is within range
      printf("Invalid speed input\n");
      continue; // start the loop over again
    }
    
    printf("Enter direction (0-360): ");
    scanf("%d", &direction); // get user input for direction
    
    if(direction < 0 || direction > 360) { // check if direction input is within range
      printf("Invalid direction input\n");
      continue; // start the loop over again
    }
    
    // generate a random distance to simulate the vehicle moving
    srand(time(NULL));
    int distance = rand() % 100 + 1;
    
    printf("Vehicle moved %d meters at speed %d in direction %d degrees\n", distance, speed, direction);
  }
  
  return 0;
}