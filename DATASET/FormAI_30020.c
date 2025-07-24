//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the states of the traffic light
typedef enum {RED, GREEN, YELLOW} State;

// Function prototypes
void turn_on(State light);
void change_light(State *current_light);

// Main function
int main() {
  State light = RED;
  int time = 0;
  
  while (1) {
    // Display the current state of the light
    printf("Current light: ");
    turn_on(light);
    printf("\n");
    
    // Wait for 5 seconds
    sleep(5);
    
    // Change the state of the light
    change_light(&light);
    
    // Increment the time
    time += 5;
    
    // Display the time elapsed
    printf("Time elapsed: %d seconds\n\n", time);
  }
  
  return 0;
}

// Function to turn on the specified light
void turn_on(State light) {
  switch (light) {
    case RED:
      printf("RED");
      break;
    case GREEN:
      printf("GREEN");
      break;
    case YELLOW:
      printf("YELLOW");
      break;
    default:
      printf("Invalid state");
      break;
  }
}

// Function to change the state of the light
void change_light(State *current_light) {
  switch (*current_light) {
    case RED:
      *current_light = GREEN;
      break;
    case GREEN:
      *current_light = YELLOW;
      break;
    case YELLOW:
      *current_light = RED;
      break;
    default:
      printf("Invalid state");
      break;
  }
}