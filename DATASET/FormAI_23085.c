//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20

void takeoff() {
  printf("The drone takes off.\n");
}

void land() {
  printf("The drone lands.\n");
}

void move_left() {
  printf("The drone moves left.\n");
}

void move_right() {
  printf("The drone moves right.\n");
}

void move_forward() {
  printf("The drone moves forward.\n");
}

void move_backward() {
  printf("The drone moves backward.\n");
}

void move_up() {
  printf("The drone moves up.\n");
}

void move_down() {
  printf("The drone moves down.\n");
}

void fly() {
  char command[MAX_COMMAND_LENGTH];
  int running = 1;

  while (running) {
    printf("Enter a command (takeoff, land, left, right, forward, backward, up, down, exit): ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\r\n")] = 0; // remove trailing newline

    if (strcmp(command, "takeoff") == 0) {
      takeoff();
    } else if (strcmp(command, "land") == 0) {
      land();
    } else if (strcmp(command, "left") == 0) {
      move_left();
    } else if (strcmp(command, "right") == 0) {
      move_right();
    } else if (strcmp(command, "forward") == 0) {
      move_forward();
    } else if (strcmp(command, "backward") == 0) {
      move_backward();
    } else if (strcmp(command, "up") == 0) {
      move_up();
    } else if (strcmp(command, "down") == 0) {
      move_down();
    } else if (strcmp(command, "exit") == 0) {
      running = 0;
    } else {
      printf("Unknown command: %s\n", command);
    }
  }
}

int main() {
  printf("Welcome to the drone remote control.\n");
  printf("Press enter to start.\n");
  getchar();
  fly();
  printf("Shutting down the drone remote control.\n");
  return 0;
}