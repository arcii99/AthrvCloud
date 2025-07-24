//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_FLOORS 8
#define TOTAL_ELEVATORS 3

// Initialize the floors and elevators
int floors[TOTAL_FLOORS][TOTAL_ELEVATORS];
bool is_running = true;

// Display the status of each elevator and floor
void display_status() {
    printf("\nCURRENT ELEVATOR STATUS:\n");
    for (int i = 0; i < TOTAL_ELEVATORS; i++) {
        printf("Elevator %d: ", i+1);
        for (int j = 0; j < TOTAL_FLOORS; j++) {
            printf("%d ", floors[j][i]);
        }
        printf("\n");
    }

    printf("\nCURRENT FLOOR STATUS:\n");
    for (int i = 0; i < TOTAL_FLOORS; i++) {
        printf("Floor %d: ", i+1);
        for (int j = 0; j < TOTAL_ELEVATORS; j++) {
            printf("%d ", floors[i][j]);
        }
        printf("\n");
    }
}

// Check if any elevator is available on current floor
bool is_elevator_available(int floor) {
    for (int i = 0; i < TOTAL_ELEVATORS; i++) {
        if (floors[floor][i] == 1) {
            return true;
        }
    }
    return false;
}

// Find the closest elevator from current floor
int find_closest_elevator(int floor) {
    int min_dist = 50; // Maximum floor distance
    int closest_elevator = -1; // Initialize to invalid elevator

    for (int i = 0; i < TOTAL_ELEVATORS; i++) {
        if (floors[floor][i] == 1) {
            // Elevator is available on current floor
            return i;
        } else {
            // Find distance from current floor to this elevator
            int dist = abs((i+1) - floor);
            if (dist < min_dist) {
                min_dist = dist;
                closest_elevator = i;
            }
        }
    }

    return closest_elevator;
}

// Move the elevator to desired floor
void move_elevator(int elevator, int current_floor, int desired_floor) {
    if (current_floor == desired_floor) {
        return;
    } else if (current_floor < desired_floor) {
        printf("Elevator %d going up from floor %d to floor %d\n", elevator+1, current_floor+1, desired_floor+1);
        floors[current_floor][elevator] = 0;
        floors[desired_floor][elevator] = 1;
        move_elevator(elevator, current_floor+1, desired_floor);
    } else {
        printf("Elevator %d going down from floor %d to floor %d\n", elevator+1, current_floor+1, desired_floor+1);
        floors[current_floor][elevator] = 0;
        floors[desired_floor][elevator] = 1;
        move_elevator(elevator, current_floor-1, desired_floor);
    }
}

int main() {
    // Initialize all floors and elevators to 0 (not available)
    for (int i = 0; i < TOTAL_FLOORS; i++) {
        for (int j = 0; j < TOTAL_ELEVATORS; j++) {
            floors[i][j] = 0;
        }
    }

    // Run the simulation
    while (is_running) {
        display_status();

        int current_floor, desired_floor, closest_elevator;
        printf("\nEnter current floor: ");
        scanf("%d", &current_floor);
        printf("Enter desired floor: ");
        scanf("%d", &desired_floor);

        if (current_floor < 1 || current_floor > 8 || desired_floor < 1 || desired_floor > 8) {
            printf("Invalid floor input. Please enter a floor between 1 and 8.\n");
            continue;
        }

        if (is_elevator_available(current_floor-1)) {
            // Elevator is available on current floor
            closest_elevator = find_closest_elevator(current_floor-1);
            move_elevator(closest_elevator, current_floor-1, desired_floor-1);
        } else {
            // Elevator not available on current floor
            closest_elevator = find_closest_elevator(current_floor-1);
            printf("Sending elevator %d from floor %d to floor %d...\n", closest_elevator+1, closest_elevator+1, current_floor);
            move_elevator(closest_elevator, closest_elevator, current_floor-1);
            move_elevator(closest_elevator, current_floor-1, desired_floor-1);
        }
    }

    return 0;
}