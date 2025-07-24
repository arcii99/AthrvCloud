//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the maximum number of floors and elevators */
#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

/* Define the maximum number of passengers in each elevator */
#define MAX_CAPACITY 8

/* Define the struct for each passenger */
typedef struct Passenger {
    int current_floor;
    int target_floor;
} Passenger;

/* Define the struct for each elevator */
typedef struct Elevator {
    int id;
    int current_floor;
    int target_floor;
    Passenger passengers[MAX_CAPACITY];
    bool in_use;
} Elevator;

/* Define global variables for the elevator system */
Elevator elevators[MAX_ELEVATORS];
bool floors[MAX_FLOORS][MAX_ELEVATORS];

/* Function prototypes */
void initialize_system();
void update_system(int time);
void assign_passenger(int current_floor, int target_floor);
int get_elevator(int current_floor, int target_floor);
void simulate_elevators();

/* Main function */
int main() {
    initialize_system();
    for (int i = 0; i < 10; i++) {
        printf("Time: %d\n", i);
        update_system(i);
    }
    return 0;
}

/* Helper function to initialize the elevator system */
void initialize_system() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        elevators[i].target_floor = 0;
        elevators[i].in_use = false;
        for (int j = 0; j < MAX_CAPACITY; j++) {
            elevators[i].passengers[j].current_floor = -1;
            elevators[i].passengers[j].target_floor = -1;
        }
    }
    for (int i = 0; i < MAX_FLOORS; i++) {
        for (int j = 0; j < MAX_ELEVATORS; j++) {
            floors[i][j] = false;
        }
    }
}

/* Helper function to update the elevator system at each time step */
void update_system(int time) {
    simulate_elevators();
    if (time % 2 == 0) {
        assign_passenger(0, 5);
    }
    if (time % 3 == 0) {
        assign_passenger(2, 8);
    }
    if (time % 4 == 0) {
        assign_passenger(9, 1);
    }
}

/* Helper function to assign a passenger to an elevator */
void assign_passenger(int current_floor, int target_floor) {
    int elevator_id = get_elevator(current_floor, target_floor);
    floors[current_floor][elevator_id] = true;
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (elevators[elevator_id].passengers[i].current_floor == -1) {
            elevators[elevator_id].passengers[i].current_floor = current_floor;
            elevators[elevator_id].passengers[i].target_floor = target_floor;
            break;
        }
    }
}

/* Helper function to determine which elevator is closest to a passenger */
int get_elevator(int current_floor, int target_floor) {
    int closest_elevator = -1;
    int smallest_distance = 999;
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].in_use == false) {
            int distance = abs(elevators[i].current_floor - current_floor);
            if (distance < smallest_distance) {
                smallest_distance = distance;
                closest_elevator = i;
            }
        }
    }
    return closest_elevator;
}

/* Helper function to simulate the movement of each elevator */
void simulate_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].in_use == true) {
            if (elevators[i].current_floor == elevators[i].target_floor) {
                elevators[i].in_use = false;
                for (int j = 0; j < MAX_CAPACITY; j++) {
                    if (elevators[i].passengers[j].current_floor != -1) {
                        floors[elevators[i].passengers[j].current_floor][i] = false;
                        elevators[i].passengers[j].current_floor = -1;
                        elevators[i].passengers[j].target_floor = -1;
                    }
                }
            } else if (elevators[i].current_floor < elevators[i].target_floor) {
                elevators[i].current_floor++;
            } else {
                elevators[i].current_floor--;
            }
        } else {
            bool should_move = false;
            for (int j = 0; j < MAX_FLOORS; j++) {
                if (floors[j][i] == true) {
                    should_move = true;
                    elevators[i].target_floor = j;
                    break;
                }
            }
            if (should_move == true) {
                elevators[i].in_use = true;
            }
        }
    }
}