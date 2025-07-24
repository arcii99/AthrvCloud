//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3

int floor_request[FLOORS] = {0};
int elevator_request[ELEVATORS][FLOORS] = {0};
int elevator_direction[ELEVATORS] = {0}; // 1 means the elevator is going up, -1 means it is going down, and 0 means it is not moving
int elevator_current_floor[ELEVATORS] = {0}; // holds the current floor of each elevator
int elevator_dest_floor[ELEVATORS] = {0}; // holds the destination floor of each elevator

// simulates an elevator moving up or down one floor
void move_elevator(int elevator) {
    if (elevator_direction[elevator] == 1) {
        elevator_current_floor[elevator]++;
    } else if (elevator_direction[elevator] == -1) {
        elevator_current_floor[elevator]--;
    }
    printf("Elevator %d is now on floor %d.\n", elevator+1, elevator_current_floor[elevator]);
}

// checks if any elevator is on the requested floor
int check_elevator_on_floor(int floor) {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevator_current_floor[i] == floor && elevator_direction[i] == 0) {
            return i;
        }
    }
    return -1;
}

// selects the closest elevator to a requested floor
int select_elevator(int floor) {
    int min_distance = FLOORS+1;
    int elevator = -1;
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevator_direction[i] == 0) {
            int distance = abs(elevator_current_floor[i] - floor);
            if (distance < min_distance) {
                min_distance = distance;
                elevator = i;
            }
        }
    }
    return elevator;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the elevator simulation!\n");
    
    while (1) {
        // generate floor requests
        int floor_request_count = 0;
        for (int i = 0; i < FLOORS; i++) {
            if (rand() % 100 < 10) { // 10% chance of someone requesting a floor
                floor_request[i] = 1;
                floor_request_count++;
            } else {
                floor_request[i] = 0;
            }
        }
        
        printf("There are %d floor requests:\n", floor_request_count);
        for (int i = FLOORS-1; i >= 0; i--) {
            if (floor_request[i]) {
                printf("Floor %d:\n", i+1);
                
                int elevator = check_elevator_on_floor(i);
                if (elevator != -1) {
                    printf("An elevator is already on this floor. Opening doors...\n");
                    elevator_request[elevator][i] = 1;
                } else {
                    elevator = select_elevator(i);
                    printf("Sending elevator %d to floor %d...\n", elevator+1, i+1);
                    elevator_request[elevator][i] = 1;
                    if (elevator_current_floor[elevator] < i+1) {
                        elevator_direction[elevator] = 1;
                    } else {
                        elevator_direction[elevator] = -1;
                    }
                    elevator_dest_floor[elevator] = i+1;
                }
            }
        }
        
        // move elevators
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevator_direction[i] != 0) {
                move_elevator(i);
                if (elevator_current_floor[i] == elevator_dest_floor[i]) {
                    elevator_direction[i] = 0;
                    printf("Elevator %d has arrived at floor %d.\n", i+1, elevator_current_floor[i]);                    
                    for (int j = 0; j < FLOORS; j++) {
                        if (elevator_request[i][j]) {
                            printf("Elevator %d is picking up someone on floor %d.\n", i+1, j+1);
                            elevator_request[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}