//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Macros for easy readability
#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define MOVE_FORWARD 3
#define MOVE_BACKWARD 4
#define MOVE_UP 5
#define MOVE_DOWN 6

#define TURN_LEFT 7
#define TURN_RIGHT 8

#define BATTERY_MAX 100
#define BATTERY_MIN 10

// Global variables
int battery_level = BATTERY_MAX;
int altitude = 0;
int x_pos = 0;
int y_pos = 0;
int z_pos = 0;
int facing = 0; // 0-N, 1-E, 2-S, 3-W

// Function to move the drone
void move_drone(int direction, int amount) {
  // Check battery level
  if (battery_level < BATTERY_MIN) {
    printf("Battery level too low. Cannot move!");
    return;
  }

  switch (direction) {
    case MOVE_LEFT:
      battery_level -= 5;
      x_pos -= amount;
      printf("Drone moved left by %d units.\n", amount);
      break;
    case MOVE_RIGHT:
      battery_level -= 5;
      x_pos += amount;
      printf("Drone moved right by %d units.\n", amount);
      break;
    case MOVE_FORWARD:
      battery_level -= 5;
      y_pos += amount;
      printf("Drone moved forward by %d units.\n", amount);
      break;
    case MOVE_BACKWARD:
      battery_level -= 5;
      y_pos -= amount;
      printf("Drone moved backward by %d units.\n", amount);
      break;
    case MOVE_UP:
      battery_level -= 10;
      altitude += amount;
      printf("Drone moved up by %d units.\n", amount);
      break;
    case MOVE_DOWN:
      battery_level -= 10;
      altitude -= amount;
      printf("Drone moved down by %d units.\n", amount);
      break;
    default:
      printf("Invalid direction. Cannot move!");
      break;
  }
}

// Function to turn the drone
void turn_drone(int direction) {
  if (battery_level < BATTERY_MIN) {
    printf("Battery level too low. Cannot turn!");
    return;
  }

  facing += direction;

  if (facing < 0) {
    facing += 4;
  } else if (facing > 3) {
    facing -= 4;
  }

  printf("Drone turned %s.\n", direction == TURN_LEFT ? "left" : "right");
}

int main() {
  printf("Starting drone control program.\n");

  // Move drone
  move_drone(MOVE_FORWARD, 5);
  move_drone(MOVE_LEFT, 3);
  move_drone(MOVE_UP, 10);
  move_drone(MOVE_RIGHT, 2);
  move_drone(MOVE_BACKWARD, 4);
  move_drone(MOVE_DOWN, 7);

  // Turn drone
  turn_drone(TURN_LEFT);
  turn_drone(TURN_RIGHT);
  turn_drone(TURN_RIGHT);

  printf("Ending drone control program.\n");
  return 0;
}