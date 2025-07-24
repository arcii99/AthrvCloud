//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 4

int elevator_positions[ELEVATORS];
int elevator_destinations[ELEVATORS];
bool elevator_directions[ELEVATORS];
bool floor_requests[FLOORS][2];

void initialize_elevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        elevator_positions[i] = 0;
        elevator_destinations[i] = 0;
        elevator_directions[i] = true;
    }
}

void initialize_floor_requests() {
    for (int i = 0; i < FLOORS; i++) {
        floor_requests[i][0] = false;
        floor_requests[i][1] = false;
    }
}

void print_elevator_status(int elevator_number) {
    printf("Elevator %d: Position - %d, ", elevator_number, elevator_positions[elevator_number]);
    printf("Destination - %d, Direction - %s\n", elevator_destinations[elevator_number], elevator_directions[elevator_number] ? "UP" : "DOWN");
}

bool any_requests(int elevator_number) {
    int current_position = elevator_positions[elevator_number];
    bool current_direction = elevator_directions[elevator_number];
    for (int i = current_position; i < FLOORS && current_direction; i++) {
        if (floor_requests[i][0] || floor_requests[i][1]) {
            return true;
        }
    }
    for (int i = current_position; i >= 0 && !current_direction; i--) {
        if (floor_requests[i][0] || floor_requests[i][1]) {
            return true;
        }
    }
    return false;
}

void update_elevator_status(int elevator_number) {
    int current_position = elevator_positions[elevator_number];
    bool current_direction = elevator_directions[elevator_number];
    if (elevator_destinations[elevator_number] == current_position || !any_requests(elevator_number)) {
        elevator_destinations[elevator_number] = -1;
        elevator_directions[elevator_number] = true;
        for (int i = 0; i < FLOORS; i++) {
            if (floor_requests[i][1]) {
                elevator_destinations[elevator_number] = i;
                elevator_directions[elevator_number] = true;
                floor_requests[i][1] = false;
                break;
            } else if (floor_requests[i][0]) {
                elevator_destinations[elevator_number] = i;
                elevator_directions[elevator_number] = false;
                floor_requests[i][0] = false;
                break;
            }
        }
    } else if (current_direction) {
        bool should_stop = floor_requests[current_position][0] || floor_requests[current_position][1];
        if (should_stop) {
            floor_requests[current_position][0] = false;
            floor_requests[current_position][1] = false;
        } else {
            elevator_positions[elevator_number]++;
        }
    } else {
        bool should_stop = floor_requests[current_position][0] || floor_requests[current_position][1];
        if (should_stop) {
            floor_requests[current_position][0] = false;
            floor_requests[current_position][1] = false;
        } else {
            elevator_positions[elevator_number]--;
        }
    }
}

void update_floor_requests() {
    for (int i = 0; i < FLOORS; i++) {
        if (rand() % 2 == 0) {
            floor_requests[i][rand() % 2] = true;
        }
    }
}

void run_simulation(int steps) {
    for (int i = 0; i < steps; i++) {
        printf("Step %d\n", i + 1);
        for (int j = 0; j < ELEVATORS; j++) {
            printf("\n");
            print_elevator_status(j);
            update_elevator_status(j);
        }
        printf("\nFloor Requests\n");
        for (int j = 0; j < FLOORS; j++) {
            printf("Floor %d: UP - %s, DOWN - %s\n", j, floor_requests[j][0] ? "True" : "False", floor_requests[j][1] ? "True" : "False");
        }
        printf("\n");
        update_floor_requests();
    }
}

int main() {
    srand(time(NULL));
    initialize_elevators();
    initialize_floor_requests();
    run_simulation(10);
    return 0;
}