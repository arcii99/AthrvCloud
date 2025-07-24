//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define constants for the traffic light states
#define STATE_GREEN 0
#define STATE_YELLOW 1
#define STATE_RED 2

// Define constants for the traffic light timers
#define TIME_GREEN 10
#define TIME_YELLOW 3
#define TIME_RED 15

int main() {
  // Initialize the traffic light variables
  int state = STATE_GREEN;
  int timer = TIME_GREEN;
  
  // Loop indefinitely
  while(1) {
    // Output the current state of the traffic light
    switch(state) {
      case STATE_GREEN:
        printf("GREEN\n");
        break;
      case STATE_YELLOW:
        printf("YELLOW\n");
        break;
      case STATE_RED:
        printf("RED\n");
        break;
    }
    
    // Decrement the timer
    timer--;
    
    // Check if the timer has reached 0
    if(timer == 0) {
      // Reset the timer and switch to the next state
      switch(state) {
        case STATE_GREEN:
          state = STATE_YELLOW;
          timer = TIME_YELLOW;
          break;
        case STATE_YELLOW:
          state = STATE_RED;
          timer = TIME_RED;
          break;
        case STATE_RED:
          state = STATE_GREEN;
          timer = TIME_GREEN;
          break;
      }
    }
  }
  
  // We never get here, but return 0 to satisfy the compiler
  return 0;
}