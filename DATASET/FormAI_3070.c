//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define RED 0
#define GREEN 1
#define YELLOW 2

// Define states
typedef enum{
  STOPPED,
  GOING,
  WARNED
} state;

// Define default state
state currentState = STOPPED;

// Define function prototypes
void changeState(void);

// Traffic light controller
int main(void) {
  // Loop forever
  while (true) {
    // Change the state of the traffic light
    changeState();
  }
  
  return 0;
}

// Change the state of the traffic light
void changeState(void) {
  switch (currentState) {
    case STOPPED:
      printf("Green light turning on.\n");
      currentState = GOING;
      break;
    case GOING:
      printf("Yellow light turning on.\n");
      currentState = WARNED;
      break;
    case WARNED:
      printf("Red light turning on.\n");
      currentState = STOPPED;
      break;
    default:
      printf("Invalid state.\n");
      exit(1);
  }
}