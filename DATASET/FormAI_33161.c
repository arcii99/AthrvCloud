//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

int current_floor[NUM_ELEVATORS]; // track the current position of each elevator
int goals[NUM_FLOORS][NUM_ELEVATORS]; // record which floors passengers want to get off at
bool up[NUM_FLOORS]; // track which floors have passengers waiting to go up
bool down[NUM_FLOORS]; // track which floors have passengers waiting to go down

// helper function to check if any passengers on any floor are waiting to move in a particular direction
bool passengers_waiting(bool *directions, int num_floors) {
    for (int i = 0; i < num_floors; i++) {
        if (directions[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    // initialize the system
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        current_floor[i] = 0;
    }
    for (int i = 0; i < NUM_FLOORS; i++) {
        up[i] = false;
        down[i] = false;
        for (int j = 0; j < NUM_ELEVATORS; j++) {
            goals[i][j] = 0;
        }
    }

    // simulate the system over time
    for (int t = 0; t < 1000; t++) {
        // check if any elevators are at their destination and need to unload passengers
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (current_floor[i] == goals[current_floor[i]][i]) {
                // unload passengers
                goals[current_floor[i]][i] = 0;
                printf("Elevator %d unloaded passengers at floor %d\n", i, current_floor[i]);
            }
        }

        // check if any elevators can move to a new floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (current_floor[i] < NUM_FLOORS - 1 && passengers_waiting(up, NUM_FLOORS) && (goals[current_floor[i]][i] == 0 || goals[current_floor[i]][i] > current_floor[i])) {
                // move up
                current_floor[i]++;
                printf("Elevator %d moved up to floor %d\n", i, current_floor[i]);
            } else if (current_floor[i] > 0 && passengers_waiting(down, NUM_FLOORS) && (goals[current_floor[i]][i] == 0 || goals[current_floor[i]][i] < current_floor[i])) {
                // move down
                current_floor[i]--;
                printf("Elevator %d moved down to floor %d\n", i, current_floor[i]);
            }
        }

        // check which floors have waiting passengers
        for (int i = 0; i < NUM_FLOORS; i++) {
            up[i] = false;
            down[i] = false;
            for (int j = 0; j < NUM_ELEVATORS; j++) {
                if (goals[i][j] != 0) {
                    continue; // an elevator is already going to this floor, so no one is waiting
                }
                if (i > current_floor[j]) {
                    up[i] = true;
                } else if (i < current_floor[j]) {
                    down[i] = true;
                }
            }
        }

        // assign goals to elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            // if the elevator has no goal, assign it to the nearest waiting passenger going in its direction
            if (goals[current_floor[i]][i] == 0) {
                int direction = -1;
                int goal = -1;
                if (current_floor[i] < NUM_FLOORS - 1) {
                    for (int j = current_floor[i] + 1; j < NUM_FLOORS; j++) {
                        if (up[j]) {
                            direction = 1;
                            goal = j;
                            break;
                        }
                    }
                }
                if (direction == -1 && current_floor[i] > 0) {
                    for (int j = current_floor[i] - 1; j >= 0; j--) {
                        if (down[j]) {
                            direction = -1;
                            goal = j;
                            break;
                        }
                    }
                }
                goals[goal][i] = goal;
                printf("Elevator %d set goal to floor %d\n", i, goal);
            }
        }
    }

    return 0;
}