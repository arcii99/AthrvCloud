//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  int current_state = 0; // starting state
  int time_elapsed = 0; // track time elapsed
  bool is_green = false; // initialize green signal to false
  
  printf("Welcome to the Traffic Light Controller program!\n\n");

  while (time_elapsed < 60) { // run for 60 seconds
    
    // switch statement to determine current state and signal lengths
    switch(current_state) {
      case 0:
        printf("Red light is on for 15 seconds.\n");
        sleep(15);
        current_state = 1;
        break;
      case 1:
        printf("Red and yellow lights are on for 3 seconds.\n");
        sleep(3);
        current_state = 2;
        break;
      case 2:
        printf("Green light is on for 20 seconds.\n");
        is_green = true;
        sleep(20);
        current_state = 3;
        break;
      case 3:
        if (is_green) { // if previously green, switch to yellow for 3 seconds
          printf("Green and yellow lights are on for 3 seconds.\n");
          is_green = false;
          sleep(3);
        }
        else { // if previously not green, switch to red for 10 seconds
          printf("Yellow light is on for 2 seconds.\n");
          current_state = 0;
          time_elapsed += 10; // add 10 seconds to time elapsed since the lights will start back at state 0
          break;
        }
    }
    
    time_elapsed += (is_green) ? 20 : 3; // add appropriate time elapsed depending on signal length
  }

  printf("\nEnd of program.\n");
  return 0;
}