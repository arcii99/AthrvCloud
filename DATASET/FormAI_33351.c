//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define state constants
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define button constants
#define NO_PRESS 0
#define RESET_BUTTON 1
#define EMERGENCY_BUTTON 2

// Define time constants in seconds
#define RED_TIME 10
#define YELLOW_TIME 2
#define GREEN_TIME 15

// Define global variables
int state;
int buttonPressed;
int timeRemaining;

// Define functions
void printState();
void toggleState();
void resetState();
void emergencyState();

int main() {
  // Initialize variables
  state = RED;
  buttonPressed = NO_PRESS;
  timeRemaining = RED_TIME;

  // Main loop
  while (1) {
    // Check for button input
    if (buttonPressed == RESET_BUTTON) {
      resetState();
      buttonPressed = NO_PRESS;
    }
    else if (buttonPressed == EMERGENCY_BUTTON) {
      emergencyState();
      buttonPressed = NO_PRESS;
    }

    // Update time remaining
    timeRemaining--;

    // Check if the time is up for the current state
    if (timeRemaining == 0) {
      toggleState();
    }

    // Print the current state
    printState();

    // Wait for one second
    sleep(1);
  }

  return 0;
}

void printState() {
  // Print the state to the console
  switch (state) {
    case RED:
      printf("State: RED\n");
      break;
    case YELLOW:
      printf("State: YELLOW\n");
      break;
    case GREEN:
      printf("State: GREEN\n");
      break;
  }

  // Print the time remaining to the console
  printf("Time Remaining: %d seconds\n", timeRemaining);
}

void toggleState() {
  // Toggle the state
  switch (state) {
    case RED:
      state = GREEN;
      timeRemaining = GREEN_TIME;
      break;
    case YELLOW:
      state = RED;
      timeRemaining = RED_TIME;
      break;
    case GREEN:
      state = YELLOW;
      timeRemaining = YELLOW_TIME;
      break;
  }
}

void resetState() {
  // Reset the state to RED
  state = RED;
  timeRemaining = RED_TIME;
}

void emergencyState() {
  // Set the state to YELLOW and switch back to RED after one cycle
  state = YELLOW;
  timeRemaining = YELLOW_TIME;
  toggleState();
}