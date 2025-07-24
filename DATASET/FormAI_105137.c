//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAP 8

// Struct for each passenger
typedef struct Passenger {
  int id;
  int dest_floor;
} Passenger;

// Struct for the elevator itself
typedef struct Elevator {
  int curr_floor;
  int num_passengers;
  int passenger_list[ELEVATOR_CAP];
} Elevator;

// Function to generate a random integer between 0 and max_value
int random_int(int max_value) {
  return rand() % (max_value + 1);
}

int main(void) {
  // Seed random number generator with current time
  srand(time(NULL));

  // Initialize elevator and passenger lists
  Elevator elevator = { .curr_floor = 0, .num_passengers = 0 };
  Passenger passengers[NUM_FLOORS][ELEVATOR_CAP];

  // Loop until all passengers have reached their destination
  while (true) {
    // Simulate passengers arriving on each floor
    for (int f = 0; f < NUM_FLOORS; f++) {
      // Random number of passengers arrive on this floor
      int num_arriving = random_int(ELEVATOR_CAP);

      // Add passengers to the floor's passenger list
      for (int p = 0; p < num_arriving; p++) {
        int dest_floor = random_int(NUM_FLOORS - 1);
        passengers[f][p].id = p;
        passengers[f][p].dest_floor = dest_floor;
        printf("Passenger %d on floor %d wants to go to floor %d\n", p, f, dest_floor);
      }
    }

    // Simulate elevator stopping on floors and passengers boarding
    for (int f = 0; f < NUM_FLOORS; f++) {
      if (elevator.curr_floor == f) {
        // Board passengers up to the elevator's capacity
        for (int p = 0; p < ELEVATOR_CAP; p++) {
          if (elevator.num_passengers < ELEVATOR_CAP && passengers[f][p].id != -1) {
            elevator.passenger_list[elevator.num_passengers++] = passengers[f][p].id;
            passengers[f][p].id = -1;
            printf("Passenger %d on floor %d boarded the elevator\n", p, f);
          }
        }
      }
    }

    // Simulate elevator moving to a new floor
    elevator.curr_floor = random_int(NUM_FLOORS - 1);
    printf("Elevator moved to floor %d\n", elevator.curr_floor);

    // Simulate passengers reaching their destinations and leaving the elevator
    for (int p = 0; p < elevator.num_passengers; p++) {
      if (passengers[elevator.curr_floor][elevator.passenger_list[p]].dest_floor == elevator.curr_floor) {
        printf("Passenger %d on floor %d reached their destination on floor %d\n", passengers[elevator.curr_floor][elevator.passenger_list[p]].id, elevator.curr_floor, elevator.curr_floor);
        elevator.passenger_list[p] = -1;
      }
    }

    // Check if all passengers have reached their destinations
    bool all_arrived = true;
    for (int f = 0; f < NUM_FLOORS; f++) {
      for (int p = 0; p < ELEVATOR_CAP; p++) {
        if (passengers[f][p].id != -1 || elevator.passenger_list[p] != -1) {
          all_arrived = false;
        }
      }
    }

    if (all_arrived) {
      break;
    }
  }

  return 0;
}