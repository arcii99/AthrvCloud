//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

int current_floor[MAX_ELEVATORS] = {1, 1, 1, 1}; // Current floor for each elevator
int direction[MAX_ELEVATORS] = {1, 1, 1, 1}; // Direction of each elevator
int destination_floor[MAX_ELEVATORS]; // Destination floor for each elevator
int elevator_status[MAX_ELEVATORS] = {0, 0, 0, 0}; // Status of each elevator (0 = idle, 1 = moving)

void print_elevator_status() {
    printf("Elevator status:\n");
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        printf("Elevator %d - Current floor: %d | Direction: %s | Status: %s\n", 
                i+1, current_floor[i], direction[i] == 1 ? "Up" : "Down",
                elevator_status[i] == 0 ? "Idle" : "Moving");
    }
}

void move_elevator(int elevator_index) {
    if (elevator_status[elevator_index] == 0) {
        return; // elevator is idle, nothing to do
    }
    int dest = destination_floor[elevator_index];
    if (current_floor[elevator_index] == dest) {
        elevator_status[elevator_index] = 0; // reached destination floor, set status to idle
        printf("Elevator %d has arrived at floor %d\n", elevator_index+1, dest);
        return;
    }
    if (current_floor[elevator_index] > dest) {
        direction[elevator_index] = -1;
        current_floor[elevator_index]--;
    } else {
        direction[elevator_index] = 1;
        current_floor[elevator_index]++;
    }
    printf("Elevator %d is now at floor %d\n", elevator_index+1, current_floor[elevator_index]);
}

void request_elevator(int floor, int dest) {
    printf("Requesting elevator from floor %d to floor %d\n", floor, dest);
    // Find closest idle elevator
    int closest_elevator = -1, min_distance = MAX_FLOORS+1;
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevator_status[i] == 0) { // idle elevator
            int dist = abs(current_floor[i] - floor);
            if (dist < min_distance) {
                min_distance = dist;
                closest_elevator = i;
            }
        }
    }
    if (closest_elevator == -1) {
        printf("All elevators are busy, please wait.\n");
        return;
    }
    printf("Sending elevator %d to floor %d\n", closest_elevator+1, floor);
    destination_floor[closest_elevator] = dest;
    if (floor < current_floor[closest_elevator]) {
        direction[closest_elevator] = -1;
    } else {
        direction[closest_elevator] = 1;
    }
    elevator_status[closest_elevator] = 1; // set status to moving
}

int main() {
    printf("Welcome to Elevator Simulation!\n");

    // Simulate elevator requests
    request_elevator(5, 10);
    request_elevator(2, 7);
    request_elevator(15, 1);
    request_elevator(17, 3);
    request_elevator(12, 8);
    print_elevator_status();

    // Simulate elevator movement
    while (1) {
        int moving = 0;
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (elevator_status[i] == 1) { // elevator is moving
                moving = 1;
                move_elevator(i);
            }
        }
        if (moving == 0) {
            break; // all elevators are idle, no more requests
        }
    }
    printf("All elevators are idle, simulation complete.\n");

    return 0;
}