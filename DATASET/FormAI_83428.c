//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: careful
// C Traffic Light Controller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the pins connected to the traffic lights
#define RED_LIGHT_PIN 1
#define YELLOW_LIGHT_PIN 2
#define GREEN_LIGHT_PIN 3

// Define the durations of each light (in seconds)
#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 15

// Define the total run time of the program (in seconds)
#define TOTAL_RUN_TIME 60

// Function declarations
void turnOnRedLight();
void turnOnYellowLight();
void turnOnGreenLight();

int main(void) {
  // Set the random seed for the random function
  srand(time(NULL));

  // Initialize the traffic light controller
  int currentTime = 0;
  int redLightEndTime = RED_LIGHT_DURATION;
  int yellowLightEndTime = redLightEndTime + YELLOW_LIGHT_DURATION;
  int greenLightEndTime = yellowLightEndTime + GREEN_LIGHT_DURATION;

  // Run the controller for the set time
  while (currentTime <= TOTAL_RUN_TIME) {
    // Check which light should be on and turn it on
    if (currentTime < redLightEndTime) {
      turnOnRedLight();
    } else if (currentTime < yellowLightEndTime) {
      turnOnYellowLight();
    } else if (currentTime < greenLightEndTime) {
      turnOnGreenLight();
    } else {
      // Cycle the lights and reset the end times
      int randomDelay = rand() % 6 + 5; // Generate a random delay in seconds between 5 and 10
      redLightEndTime = currentTime + randomDelay;
      yellowLightEndTime = redLightEndTime + YELLOW_LIGHT_DURATION;
      greenLightEndTime = yellowLightEndTime + GREEN_LIGHT_DURATION;
    }

    // Wait one second before checking the lights again
    sleep(1);
    currentTime++;
  }

  return 0;
}

// Function definitions
void turnOnRedLight() {
  printf("Red Light is On\n");
  // Turn on the red light pin and turn off the others
  // Your code goes here...
}

void turnOnYellowLight() {
  printf("Yellow Light is On\n");
  // Turn on the yellow light pin and turn off the others
  // Your code goes here...
}

void turnOnGreenLight() {
  printf("Green Light is On\n");
  // Turn on the green light pin and turn off the others
  // Your code goes here...
}