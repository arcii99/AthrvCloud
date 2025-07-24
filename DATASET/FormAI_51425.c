//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  
  int green_timer = rand() % 120 + 60; // Random time between 60-180 seconds for green light
  int yellow_timer = 5; // Fixed 5 seconds for yellow light
  int red_timer = 10; // Fixed 10 seconds for red light
  
  int current_light = 0; // 0 for red, 1 for green, 2 for yellow
  int time_left = red_timer; // Start with red light
  
  printf("Traffic Light Controller\n");

  while (1) { // Loop forever
    if (time_left == 0) { // Time for current light is up
      switch (current_light) {
        case 0: // Red light just finished
          current_light = 1; // Switch to green light
          time_left = green_timer;
          printf("Green light for %d seconds\n", green_timer);
          break;
        case 1: // Green light just finished
          current_light = 2; // Switch to yellow light
          time_left = yellow_timer;
          printf("Yellow light for %d seconds\n", yellow_timer);
          break;
        case 2: // Yellow light just finished
          current_light = 0; // Switch to red light
          time_left = red_timer;
          printf("Red light for %d seconds\n", red_timer);
          break;
      }
    }
    time_left--; // Decrement time for current light
  }
  
  return 0;
}