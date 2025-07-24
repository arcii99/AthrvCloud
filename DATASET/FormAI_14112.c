//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // The traffic light controller program!
  printf("Welcome to the traffic light controller program!\n");

  srand(time(NULL)); // seed random number generator with current time

  int greenTime = 10; // set green light time to 10 seconds
  int yellowTime = 3; // set yellow light time to 3 seconds
  int redTime = 15; // set red light time to 15 seconds

  int totalTime = greenTime + yellowTime + redTime; // calculate total cycle time

  // initialize counters for each light
  int greenCount = 0;
  int yellowCount = 0;
  int redCount = 0;

  // initialize start time to current time
  time_t startTime = time(NULL);

  // loop until user stops program
  while (1) {
    // calculate how much time has passed since last cycle
    time_t currentTime = time(NULL);
    int elapsedTime = currentTime - startTime;

    // calculate which light should be on based on the current time
    int cycleTime = elapsedTime % totalTime;
    if (cycleTime < greenTime) {
      printf("Green Light is on!\n");
      greenCount++;
    } else if (cycleTime < greenTime + yellowTime) {
      printf("Yellow Light is on!\n");
      yellowCount++;
    } else {
      printf("Red Light is on!\n");
      redCount++;
    }

    // wait one second
    sleep(1);
  }

  return 0;
}