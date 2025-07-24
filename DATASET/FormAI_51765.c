//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));  // seed the random number generator

  int baggage_count = rand() % 1000;  // generate a random number of baggage

  printf("Welcome to our surreal airport baggage handling simulation!\n");
  printf("Today we have %d pieces of luggage to move around.\n\n", baggage_count);

  int conveyor_belt_speed = rand() % 20;  // generate a random conveyor belt speed
  printf("Our conveyor belt is currently moving at %d units per minute.\n", conveyor_belt_speed);

  // randomly decide whether to switch conveyor belt direction
  int switch_direction = rand() % 2;
  if (switch_direction) {
    printf("Uh oh, the conveyor belt has suddenly changed direction!\n");
  } else {
    printf("Phew, the conveyor belt is still moving in the same direction.\n");
  }

  // create an array to represent the baggage handling system
  int baggage_handling_system[10][10];
  for (int row = 0; row < 10; row++) {
    for (int col = 0; col < 10; col++) {
      baggage_handling_system[row][col] = rand() % 3;  // randomly assign a type of baggage handling system
    }
  }

  // print out the baggage handling system
  printf("\nHere is a map of the baggage handling system:\n");
  for (int row = 0; row < 10; row++) {
    for (int col = 0; col < 10; col++) {
      switch (baggage_handling_system[row][col]) {
        case 0:
          printf(".");  // empty space
          break;

        case 1:
          printf("H");  // handling system
          break;

        case 2:
          printf("C");  // conveyor belt
          break;

        default:
          printf("?");  // unknown type
      }
    }
    printf("\n");  // move to the next row
  }

  // simulate moving the baggage through the system
  int baggage_on_conveyor_belt = baggage_count;
  for (int row = 9; row >= 0; row--) {
    for (int col = 0; col < 10; col++) {
      switch (baggage_handling_system[row][col]) {
        case 0:
          // empty space, do nothing
          break;

        case 1:
          if (baggage_on_conveyor_belt > 0) {
            printf("A piece of luggage has been processed by the handling system at (%d,%d)!\n", row, col);
            baggage_on_conveyor_belt--;
          }
          break;

        case 2:
          if (baggage_on_conveyor_belt > 0) {
            printf("A piece of luggage is on the conveyor belt at (%d,%d).\n", row, col);
            baggage_on_conveyor_belt--;
          } else {
            printf("The conveyor belt is empty at (%d,%d).\n", row, col);
          }

          // randomly decide whether to speed up or slow down the conveyor belt
          int speed_change = rand() % 3 - 1;
          conveyor_belt_speed += speed_change;
          printf("The conveyor belt is now moving at %d units per minute.\n", conveyor_belt_speed);

          // randomly decide whether to switch conveyor belt direction
          int switch_direction = rand() % 10;
          if (switch_direction == 0) {
            printf("Uh oh, the conveyor belt has suddenly changed direction!\n");
          }
          break;

        default:
          printf("Unknown type of baggage handling system encountered at (%d,%d)!\n", row, col);
        }
    }
  }

  printf("\nAll luggage has been processed!\n");
  return 0;
}