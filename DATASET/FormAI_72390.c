//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

int main() {
  int elevator_floor = 1; // default starting floor
  int target_floor, num_people_boarding;
  char direction;

  printf("Elevator simulation starting on floor %d\n", elevator_floor);

  while(1) {
    printf("Enter destination floor and number of people boarding (format: <floor> <num_people>) or q to quit: ");
    scanf("%c", &direction);

    if (direction == 'q') {
      break;
    }

    scanf("%d %d", &target_floor, &num_people_boarding);

    if (target_floor < 1 || target_floor > MAX_FLOORS) {
      printf("Invalid target floor entered. Please enter a value between 1 and %d.\n", MAX_FLOORS);
      continue; // start over
    }

    if (num_people_boarding < 0) {
      printf("Invalid number of people entered. Please enter a non-negative value.\n");
      continue; // start over
    }

    printf("Elevator moved from floor %d to floor %d.\n", elevator_floor, target_floor);
    elevator_floor = target_floor;

    if (num_people_boarding > 0) {
      printf("%d people entered the elevator on floor %d.\n", num_people_boarding, elevator_floor);
    }
  }

  printf("Elevator simulation ended.\n");
  return 0;
}