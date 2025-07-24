//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>

int main() {
  // Initialize elevator variables
  int current_floor = 1;
  int next_floor = 0;
  int direction = 1; // 1 for up, -1 for down

  printf("Welcome to the Mind-Bending Elevator Simulation!\n");
  printf("You are currently on the 1st floor.\n");

  while (1) {
    // Get input from user
    printf("\nEnter the floor you would like to go to: ");
    scanf("%d", &next_floor);

    // Handle invalid input
    if (next_floor < 1 || next_floor > 10) {
      printf("Invalid floor number. Please try again.\n");
      continue;
    }
    
    // Calculate the direction the elevator needs to move
    int move_direction = next_floor > current_floor ? 1 : -1;

    // Check if the elevator needs to change direction
    if (move_direction != direction) {
      direction *= -1;
      printf("The elevator has changed direction!\n");
    }

    // Move the elevator to the desired floor
    while (current_floor != next_floor) {
      current_floor += direction;
      printf("The elevator is now on the %d floor.\n", current_floor);
    }

    // Open the doors and wait for a few seconds
    printf("Ding! The elevator has arrived on the %d floor.\n", current_floor);
    printf("The doors are opening...\n");
    sleep(3);
    printf("The doors are closing...\n");

    // Reset next floor variable
    next_floor = 0;
  }

  return 0;
}