//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>

// Define available commands for the drone
typedef enum {
  TAKEOFF,
  LAND,
  UP,
  DOWN,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  ROTATE_LEFT,
  ROTATE_RIGHT,
  STOP
} DroneCommand;

// Function to execute the drone command
void executeCommand(DroneCommand command, int value) {
  printf("Executing command: ");

  switch (command) {
    case TAKEOFF:
      printf("Takeoff\n");
      break;
    case LAND:
      printf("Land\n");
      break;
    case UP:
      printf("Go Up %d meters\n", value);
      break;
    case DOWN:
      printf("Go Down %d meters\n", value);
      break;
    case FORWARD:
      printf("Go Forward %d meters\n", value);
      break;
    case BACKWARD:
      printf("Go Backward %d meters\n", value);
      break;
    case LEFT:
      printf("Go Left %d meters\n", value);
      break;
    case RIGHT:
      printf("Go Right %d meters\n", value);
      break;
    case ROTATE_LEFT:
      printf("Rotate Left %d degrees\n", value);
      break;
    case ROTATE_RIGHT:
      printf("Rotate Right %d degrees\n", value);
      break;
    case STOP:
      printf("Stop\n");
      break;
    default:
      printf("Unknown command\n");
      break;
  }
}

int main() {
  // Example usage of the executeCommand function
  executeCommand(TAKEOFF, 0);
  executeCommand(FORWARD, 10);
  executeCommand(LEFT, 5);
  executeCommand(ROTATE_LEFT, 90);
  executeCommand(UP, 8);
  executeCommand(STOP, 0);
  executeCommand(LAND, 0);

  return 0;
}