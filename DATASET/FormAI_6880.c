//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOOR_COUNT 10

// Define the elevator struct
typedef struct {
    int current_floor;
    bool is_moving;
} elevator;

// Define the floor queue struct
typedef struct {
    int floor;
    bool is_calling;
} floor_queue;

// Define the function prototypes
void elevator_init(elevator *e);
void queue_init(floor_queue *queue);
void print_floor_queue(floor_queue *queue);
void simulate_movement(elevator *e, floor_queue *queue);
void handle_floor_call(floor_queue *queue, int floor);

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Initialize the elevator and floor queue
    elevator e;
    floor_queue queue[FLOOR_COUNT];
    elevator_init(&e);
    for (int i = 0; i < FLOOR_COUNT; i++) {
        queue_init(&queue[i]);
    }
    
    // Loop over a simulated time period of 10 minutes
    int total_time = 10 * 60; // seconds
    for (int time = 0; time < total_time; time++) {
        // Randomly generate elevator calls from floors
        if (rand() % 10 == 0) {
            int floor = rand() % FLOOR_COUNT;
            handle_floor_call(&queue[floor], floor);
        }
        // Update elevator movement and floor queues
        simulate_movement(&e, queue);
        // Print the current floor queue status every 30 seconds
        if (time % 30 == 0) {
            printf("Time: %d seconds\n", time);
            print_floor_queue(queue);
        }
    }
    return 0;
}

// Initialize the elevator to start on the first floor and not moving
void elevator_init(elevator *e) {
    e->current_floor = 1;
    e->is_moving = false;
}

// Initialize a floor queue to have no calls
void queue_init(floor_queue *queue) {
    queue->floor = -1;
    queue->is_calling = false;
}

// Print the current status of all floor queues
void print_floor_queue(floor_queue *queue) {
    for (int i = 0; i < FLOOR_COUNT; i++) {
        if (queue[i].is_calling) {
            printf("Floor %d: Elevator called\n", i+1);
        } else {
            printf("Floor %d: No calls\n", i+1);
        }
    }
}

// Simulate elevator movement and floor queues
void simulate_movement(elevator *e, floor_queue *queue) {
    // If the elevator is moving, change its position based on current direction
    if (e->is_moving) {
        if (rand() % 2 == 0) { // 50% chance to stay on current floor
            if (e->current_floor == FLOOR_COUNT) {
                e->is_moving = false;
            } else {
                e->current_floor++;
            }
        } else {
            if (e->current_floor == 1) {
                e->is_moving = false;
            } else {
                e->current_floor--;
            }
        }
    // If the elevator is not moving, check if there are any calls on current floor
    } else {
        if (queue[e->current_floor-1].is_calling) {
            printf("Elevator arrived at floor %d\n", e->current_floor);
            queue[e->current_floor-1].is_calling = false;
            e->is_moving = true;
        }
    }
}

// Handle a floor call by setting the corresponding queue's is_calling flag to true
void handle_floor_call(floor_queue *queue, int floor) {
    printf("Elevator called from floor %d\n", floor+1);
    queue->floor = floor;
    queue->is_calling = true;
}