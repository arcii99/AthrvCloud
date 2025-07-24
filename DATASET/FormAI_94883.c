//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed = 0;
  int steering = 0;
  int battery_life = 100;

  printf("Welcome to the RC Vehicle Simulator!\n");
  printf("Use the following buttons to control the vehicle:\n");
  printf("W - Move forward\n");
  printf("S - Move backward\n");
  printf("A - Turn left\n");
  printf("D - Turn right\n");
  printf("Q - Quit program\n\n");

  while (1) {
    printf("Battery life: %d%%\n", battery_life);

    // get user input
    char input = getchar();
    getchar(); // ignore newline character

    // update vehicle speed and steering based on user input
    if (input == 'w' || input == 'W') {
      speed += 10;
      printf("Moving forward at %d mph.\n", speed);
    }
    else if (input == 's' || input == 'S') {
      speed -= 10;
      printf("Moving backward at %d mph.\n", speed);
    }
    else if (input == 'a' || input == 'A') {
      steering -= 10;
      printf("Turning left with %d degrees steering.\n", steering);
    }
    else if (input == 'd' || input == 'D') {
      steering += 10;
      printf("Turning right with %d degrees steering.\n", steering);
    }
    else if (input == 'q' || input == 'Q') {
      printf("Exiting program...\n");
      break;
    }
    else {
      printf("Invalid input: %c\n", input);
    }

    // update battery life based on vehicle speed and steering
    battery_life -= abs(speed)/10 + abs(steering)/10;
    if (battery_life <= 0) {
      printf("Battery is empty! Exiting program...\n");
      break;
    }
  }

  return 0;
}