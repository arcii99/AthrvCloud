//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: surprised
#include <stdio.h>

#define FLOORS 10          // number of floors in the building
#define ELEVATORS 2        // number of elevators in the building
#define MAX_CAPACITY 10    // maximum capacity of each elevator
#define TIME_TO_TRAVEL 2   // time it takes to travel between floors
#define TIME_TO_LOAD 1     // time it takes to load/unload passengers

typedef struct {
    int current_floor;     // current floor of the elevator
    int direction;         // direction the elevator is going (-1, 0, or 1 for down, stopped, or up)
    int num_passengers;    // current number of passengers in the elevator
    int passengers[MAX_CAPACITY];   // floor number of each passenger in the elevator
} Elevator;

int main() {
    Elevator elevators[ELEVATORS];
    int floor_up[FLOORS] = {0};     // number of passengers waiting to go up on each floor
    int floor_down[FLOORS] = {0};   // number of passengers waiting to go down on each floor
    int i, j, k, target_floor, min_time, time;
    printf("Welcome to the elevator simulation!\n");
    // initialize elevators
    for (i = 0; i < ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].direction = 0;
        elevators[i].num_passengers = 0;
        for (j = 0; j < MAX_CAPACITY; j++) {
            elevators[i].passengers[j] = -1;  // -1 indicates no passenger
        }
    }
    // simulate elevator activity for a certain number of time steps
    for (time = 1; time <= 30; time++) {
        printf("Time: %d\n", time);
        // count passengers waiting on each floor
        for (i = 0; i < FLOORS; i++) {
            floor_up[i] += rand() % 2;    // 50% chance of a new passenger going up
            floor_down[i] += rand() % 2;  // 50% chance of a new passenger going down
        }
        // handle elevators
        for (i = 0; i < ELEVATORS; i++) {
            if (elevators[i].direction == 0) {  // elevator is stopped
                // check if there are any passengers waiting on the current floor
                if (floor_up[elevators[i].current_floor] > 0) {
                    elevators[i].direction = 1;
                } else if (floor_down[elevators[i].current_floor] > 0) {
                    elevators[i].direction = -1;
                }
            } else {  // elevator is moving
                // check if elevator has arrived at target floor
                if (elevators[i].current_floor == target_floor) {
                    elevators[i].direction = 0;
                    // unload passengers
                    for (j = 0; j < elevators[i].num_passengers; j++) {
                        if (elevators[i].passengers[j] == elevators[i].current_floor) {
                            elevators[i].num_passengers--;
                            for (k = j; k < elevators[i].num_passengers; k++) {
                                elevators[i].passengers[k] = elevators[i].passengers[k+1];
                            }
                            break;
                        }
                    }
                    // load passengers
                    if (elevators[i].direction == 1) {
                        for (j = 0; j < MAX_CAPACITY-elevators[i].num_passengers; j++) {
                            if (floor_up[elevators[i].current_floor] > 0 && elevators[i].num_passengers < MAX_CAPACITY) {
                                elevators[i].passengers[elevators[i].num_passengers] = elevators[i].current_floor;
                                elevators[i].num_passengers++;
                                floor_up[elevators[i].current_floor]--;
                            } else {
                                break;
                            }
                        }
                    } else if (elevators[i].direction == -1) {
                        for (j = 0; j < MAX_CAPACITY-elevators[i].num_passengers; j++) {
                            if (floor_down[elevators[i].current_floor] > 0 && elevators[i].num_passengers < MAX_CAPACITY) {
                                elevators[i].passengers[elevators[i].num_passengers] = elevators[i].current_floor;
                                elevators[i].num_passengers++;
                                floor_down[elevators[i].current_floor]--;
                            } else {
                                break;
                            }
                        }
                    }
                } else {  // elevator has not arrived at target floor
                    elevators[i].current_floor += elevators[i].direction;
                }
            }
            // find closest target floor
            min_time = FLOORS*2;  // start with maximum possible time
            for (j = 0; j < FLOORS; j++) {
                if (floor_up[j] > 0 && elevators[i].direction >= 0) {
                    if (abs(elevators[i].current_floor-j)*TIME_TO_TRAVEL + TIME_TO_LOAD < min_time) {
                        target_floor = j;
                        min_time = abs(elevators[i].current_floor-j)*TIME_TO_TRAVEL + TIME_TO_LOAD;
                        elevators[i].direction = 1;
                    }
                }
                if (floor_down[j] > 0 && elevators[i].direction <= 0) {
                    if (abs(elevators[i].current_floor-j)*TIME_TO_TRAVEL + TIME_TO_LOAD < min_time) {
                        target_floor = j;
                        min_time = abs(elevators[i].current_floor-j)*TIME_TO_TRAVEL + TIME_TO_LOAD;
                        elevators[i].direction = -1;
                    }
                }
            }
            // move elevator toward target floor if necessary
            if (elevators[i].current_floor != target_floor) {
                elevators[i].current_floor += elevators[i].direction;
            }
        }
        // print elevator status
        for (i = 0; i < ELEVATORS; i++) {
            printf("Elevator %d: floor %d, direction %d, passengers ", i+1, elevators[i].current_floor, elevators[i].direction);
            if (elevators[i].num_passengers == 0) {
                printf("none\n");
            } else {
                for (j = 0; j < elevators[i].num_passengers; j++) {
                    printf("%d ", elevators[i].passengers[j]);
                }
                printf("\n");
            }
        }
        // print floor status
        for (i = 0; i < FLOORS; i++) {
            printf("Floor %d: %d up, %d down\n", i+1, floor_up[i], floor_down[i]);
        }
        printf("\n");
    }
    return 0;
}