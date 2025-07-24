//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

// define constants for number of floors, elevator capacity, and number of elevators
#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10
#define NUM_ELEVATORS 3

// define struct to represent an elevator
typedef struct {
    int floor;
    int passengers[ELEVATOR_CAPACITY];
    int num_passengers;
    bool is_moving;
    int destination_floor;
} Elevator;

// define struct to represent a floor and its waiting passengers
typedef struct {
    int floor_number;
    int waiting_passengers[NUM_FLOORS];
} Floor;

// simulate the elevator system
void simulate_elevator_system(Elevator elevators[], Floor floors[]) {
    // loop infinitely
    while (true) {
        // check if any elevators have reached their destination floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].is_moving && elevators[i].floor == elevators[i].destination_floor) {
                // elevator has arrived at destination floor, so let passengers off
                for (int j = 0; j < elevators[i].num_passengers; j++) {
                    floors[elevators[i].floor].waiting_passengers[elevators[i].passengers[j]]++;
                }
                elevators[i].num_passengers = 0;
                elevators[i].is_moving = false;
            }
        }

        // check if any floors have waiting passengers
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (floors[i].waiting_passengers[i] > 0) {
                // find nearest idle elevator and assign it to the floor
                int nearest_elevator = -1;
                int smallest_distance = NUM_FLOORS + 1;
                for (int j = 0; j < NUM_ELEVATORS; j++) {
                    if (!elevators[j].is_moving) {
                        int distance = abs(elevators[j].floor - i);
                        if (distance < smallest_distance) {
                            smallest_distance = distance;
                            nearest_elevator = j;
                        }
                    }
                }

                if (nearest_elevator >= 0) {
                    // assign elevator to floor
                    elevators[nearest_elevator].destination_floor = i;
                    elevators[nearest_elevator].is_moving = true;
                }
            }
        }

        // move elevators that are in motion
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].is_moving) {
                if (elevators[i].destination_floor > elevators[i].floor) {
                    elevators[i].floor++;
                } else if (elevators[i].destination_floor < elevators[i].floor) {
                    elevators[i].floor--;
                }
            }
        }
    }
}

int main() {
    // initialize elevators to first floor
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].num_passengers = 0;
        elevators[i].is_moving = false;
        elevators[i].destination_floor = 0;
    }

    // initialize floors to no waiting passengers
    Floor floors[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].floor_number = i;
        for (int j = 0; j < NUM_FLOORS; j++) {
            floors[i].waiting_passengers[j] = 0;
        }
    }

    // simulate the elevator system
    simulate_elevator_system(elevators, floors);

    return 0;
}