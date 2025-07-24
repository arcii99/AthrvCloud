//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define constants for drone movements
#define FORWARD 'W'
#define BACKWARD 'S'
#define LEFT 'A'
#define RIGHT 'D'
#define UP 'U'
#define DOWN 'E'
#define STOP 'P'

int main(){
  char movement; // User input to control drone movements
  int i = 0; // Counter for number of movements

  printf("Drone Remote Control\n\n");

  // Start a loop until user enters 'P' to stop the drone
  do {
    printf("Enter movement command ('W' for forward, 'S' for backward, 'A' for left, 'D' for right, 'U' for up, 'E' for down, 'P' to stop): ");
    scanf(" %c", &movement);

    // Check if movement command is valid
    if(movement != FORWARD && movement != BACKWARD && movement != LEFT && movement != RIGHT && movement != UP && movement != DOWN && movement != STOP) {
      printf("Invalid input. Try again.\n");
    } else {
      printf("Drone moves %c\n", movement);
      i++;
    }
  } while(movement != STOP);

  printf("\nDrone stopped. Total number of movements: %d\n", i);

  return 0;
}