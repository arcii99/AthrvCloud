//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to set the initial status of the traffic lights
void initializeLights(int *lights) {
  lights[0] = 1; // Green for North-South
  lights[1] = 0; // Red for East-West
}

int main() {
  int lights[2] = {0}; // Initialize the traffic lights
  int timeCounter = 0; // Initialize the time counter

  srand(time(NULL)); // Seed the random number generator

  initializeLights(lights); // Set initial status of traffic lights

  // Loop infinitely
  while (1) {
    timeCounter += rand() % 10 + 1; // Randomly add seconds to the time counter

    // Switch the lights if the time counter reaches a certain value
    if (timeCounter >= 30) {
      // North-South will switch to Red and East-West will switch to Green
      lights[0] = 0;
      lights[1] = 1;
      timeCounter = 0; // Reset the time counter to start again
    }
    else if (timeCounter >= 20) {
      // North-South will switch to Yellow and East-West will switch to Red
      lights[0] = 0;
      lights[1] = 0;
    }
    else {
      // North-South will switch to Green and East-West will switch to Red
      lights[0] = 1;
      lights[1] = 0;
    }

    // Display the current status of the traffic lights
    printf("+-----------------------------------------+\n");
    printf("|        North-South   East-West          |\n");
    printf("+-----------------------------------------+\n");

    if (lights[0] == 1) {
      printf("|            Green        Red             |\n");
    }
    else if (lights[0] == 0 && lights[1] == 1) {
      printf("|            Red          Green           |\n");
    }
    else {
      printf("|            Yellow       Red             |\n");
    }

    printf("+-----------------------------------------+\n");
    sleep(1); // Wait for 1 second before updating the traffic lights again
  }

  return 0; // End the program
}