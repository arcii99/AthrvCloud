//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  int red_state = 1; // Red light is initially on
  int yellow_state = 0;
  int green_state = 0;
  int next_state;

  while(1) { // Loop forever
    // Print the current state of the traffic light
    if(red_state)
        printf("RED\n");
    else if(yellow_state)
        printf("YELLOW\n");
    else
        printf("GREEN\n");

    // Determine the next state of the traffic light based on the current state
    if(red_state) {
        next_state = rand() % 2; // Randomly choose between yellow and green
        if(next_state == 0) {
            red_state = 0;
            yellow_state = 1;
        }
        else {
            red_state = 0;
            green_state = 1;
        }
    }
    else if(yellow_state) {
        next_state = 1; // Always go to red from yellow
        yellow_state = 0;
        red_state = 1;
    }
    else {
        next_state = rand() % 2; // Randomly choose between yellow and red
        if(next_state == 0) {
            green_state = 0;
            yellow_state = 1;
        }
        else {
            green_state = 0;
            red_state = 1;
        }
    }

    // Wait for a period of time before switching to the next state
    if(red_state || yellow_state)
        sleep(2); // Wait for 2 seconds
    else
        sleep(5); // Wait for 5 seconds
  }

  return 0;
}