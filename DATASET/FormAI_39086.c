//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Constants
#define NUM_ELEVATORS 3
#define NUM_FLOORS 10
#define TIMER_INTERVAL 1
#define DOORS_OPEN_TIME 3

// Elevator struct
struct Elevator {
    int id;
    int current_floor;
    int target_floor;
    int doors_open;
    int direction; // 1 for up, -1 for down
};

// Global variables
int elevator_queue[NUM_ELEVATORS][NUM_FLOORS] = {0};
int floors_queue[NUM_FLOORS] = {0};
struct Elevator elevators[NUM_ELEVATORS];

// Function declarations
void setup_elevators();
void pick_up_request(int floor, int direction);
void elevator_move(struct Elevator *elevator);
void update_elevator_queue(struct Elevator *elevator);

int main()
{
    // Initialize elevators
    setup_elevators();

    // Main loop
    while (1) {
        int floor;
        int direction;

        // Check if there are any pending floor requests
        for (floor = 0; floor < NUM_FLOORS; floor++) {
            if (floors_queue[floor] > 0) { // Up request
                direction = 1;
                pick_up_request(floor, direction);
            } else if (floors_queue[floor] < 0) { // Down request
                direction = -1;
                pick_up_request(floor, direction);
            }
        }

        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            elevator_move(&elevators[i]);
        }

        // Wait for a second
        sleep(TIMER_INTERVAL);
    }

    return 0;
}

void setup_elevators()
{
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        elevators[i].target_floor = -1;
        elevators[i].doors_open = 0;
        elevators[i].direction = 1;
    }
}

void pick_up_request(int floor, int direction)
{
    int elevator_id = -1;
    int min_distance = NUM_FLOORS;

    // Find closest available elevator
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].target_floor == -1 && elevators[i].doors_open == 0) {
            int distance = abs(elevators[i].current_floor - floor);
            if (distance < min_distance) {
                min_distance = distance;
                elevator_id = i;
            }
        }
    }

    if (elevator_id == -1) { // All elevators are busy
        floors_queue[floor] = direction;
    } else { // Assign floor to chosen elevator
        elevators[elevator_id].target_floor = floor;
        elevators[elevator_id].direction = direction;
    }
}

void elevator_move(struct Elevator *elevator)
{
    // Update queue
    update_elevator_queue(elevator);

    // Check if elevator has reached target floor
    if (elevator->target_floor == elevator->current_floor) {
        elevator->doors_open = DOORS_OPEN_TIME;
        elevator->target_floor = -1;
    }

    // Move elevator
    if (elevator->target_floor > elevator->current_floor) {
        elevator->current_floor += 1;
    } else if (elevator->target_floor < elevator->current_floor) {
        elevator->current_floor -= 1;
    }
}

void update_elevator_queue(struct Elevator *elevator)
{
    int floor = elevator->current_floor;
    int elevator_id = elevator->id;

    // Remove current floor from queue
    elevator_queue[elevator_id][floor] = 0;

    // Check if elevator has any pending floor requests in current direction
    for (int i = floor + elevator->direction; i >= 0 && i < NUM_FLOORS; i += elevator->direction) {
        if (elevator_queue[elevator_id][i] != 0) { // Found a pending floor request
            elevator->target_floor = i;
            break;
        }
    }

    // If no pending requests found in current direction, reverse direction
    if (elevator->target_floor == -1) {
        elevator->direction *= -1;
        for (int i = floor + elevator->direction; i >= 0 && i < NUM_FLOORS; i += elevator->direction) {
            if (elevator_queue[elevator_id][i] != 0) { // Found a pending floor request
                elevator->target_floor = i;
                break;
            }
        }
    }

    // If still no pending requests, wait at current floor
    if (elevator->target_floor == -1) {
        elevator->doors_open = DOORS_OPEN_TIME;
    }

    // Add new floor requests to queue
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (floors_queue[i] == elevator->direction || floors_queue[i] == 0) {
            elevator_queue[elevator_id][i] = 1;
            floors_queue[i] = 0;
        } else if (floors_queue[i] == elevator->direction * -1) {
            elevator_queue[elevator_id][i] = -1;
            floors_queue[i] = 0;
        }
    }
}