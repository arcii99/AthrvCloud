//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main() {
  // initialize traffic light state to red
  int state = RED;

  // seed random number generator
  srand(time(NULL));

  // loop infinitely
  while (1) {
    // print current state
    printf("Current state: ");

    switch(state) {
      case GREEN:
        printf("GREEN\n");
        break;

      case YELLOW:
        printf("YELLOW\n");
        break;

      case RED:
        printf("RED\n");
        break;
    }

    // delay for a random time between 1 and 5 seconds
    int delay = rand() % 5 + 1;
    printf("Delay for %d seconds\n\n", delay);
    sleep(delay);

    // update traffic light state based on current state
    switch(state) {
      case GREEN:
        state = YELLOW;
        break;

      case YELLOW:
        state = RED;
        break;

      case RED:
        state = GREEN;
        break;
    }
  }

  return 0;
}