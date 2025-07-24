//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10
#define NUM_ELEVATORS 3

// Define global variables
int current_floor = 1;
bool up_button[NUM_FLOORS];
bool down_button[NUM_FLOORS];
int num_waiting_up[NUM_FLOORS];
int num_waiting_down[NUM_FLOORS];
int num_passengers_waiting_elevator = 0;
int num_passengers_in_elevators = 0;
int passengers_arrived = 0;
int total_passengers = 0;
int elevator_locations[NUM_ELEVATORS] = {1, 1, 1};
int elevator_destinations[NUM_ELEVATORS][NUM_FLOORS] = {0};
bool elevator_directions[NUM_ELEVATORS] = {true, true, true};
int elevator_passengers[NUM_ELEVATORS][ELEVATOR_CAPACITY] = {0};
int current_elevator = 0;

// Function prototypes
void print_status();
void simulate_elevator();
void update_elevator(int elevator_id);
void move_elevator(int elevator_id);
void load_passengers(int elevator_id);
void unload_passengers(int elevator_id);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize up and down buttons to false
    memset(up_button, false, NUM_FLOORS * sizeof(bool));
    memset(down_button, false, NUM_FLOORS * sizeof(bool));

    // Simulate elevator until all passengers have arrived at their destination
    while (passengers_arrived < total_passengers) {
        simulate_elevator();
    }

    printf("All passengers have arrived at their destination.\n");
    return 0;
}

void print_status() {
    printf("Current floor: %d\n", current_floor);
    printf("Up button status: ");
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("%d ", up_button[i]);
    }
    printf("\n");
    printf("Down button status: ");
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("%d ", down_button[i]);
    }
    printf("\n");
    printf("Number of passengers waiting for elevator: %d\n", num_passengers_waiting_elevator);
    printf("Number of passengers in elevators: %d\n", num_passengers_in_elevators);
    printf("Passengers arrived: %d/%d\n", passengers_arrived, total_passengers);
    printf("Elevator locations: ");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("%d ", elevator_locations[i]);
    }
    printf("\n");
    printf("Elevator destinations: \n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: ", i+1);
        for (int j = 0; j < NUM_FLOORS; j++) {
            printf("%d ", elevator_destinations[i][j]);
        }
        printf("\n");
    }
    printf("Elevator directions: ");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("%d ", elevator_directions[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d passengers: ", i+1);
        for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
            printf("%d ", elevator_passengers[i][j]);
        }
        printf("\n");
    }
}

void simulate_elevator() {
    // Update elevator position and direction
    update_elevator(current_elevator);

    // Load and unload passengers at the current floor
    unload_passengers(current_elevator);
    load_passengers(current_elevator);

    // Move elevator to next floor
    move_elevator(current_elevator);

    // Increment current elevator or loop around if at end of array
    current_elevator = (current_elevator + 1) % NUM_ELEVATORS;

    // Print current status
    print_status();
}

void update_elevator(int elevator_id) {
    // Mark destination floor for current direction
    elevator_destinations[elevator_id][elevator_locations[elevator_id]-1] = elevator_directions[elevator_id] ? 1 : -1;

    // Find new direction if at top or bottom floor
    if (elevator_locations[elevator_id] == 1) {
        elevator_directions[elevator_id] = true;
    } else if (elevator_locations[elevator_id] == NUM_FLOORS) {
        elevator_directions[elevator_id] = false;
    }
}

void move_elevator(int elevator_id) {
    if (elevator_directions[elevator_id]) {
        current_floor++;
    } else {
        current_floor--;
    }

    elevator_locations[elevator_id] = current_floor;
}

void load_passengers(int elevator_id) {
    if (num_waiting_up[current_floor-1] > 0 && elevator_directions[elevator_id]) {
        for (int i = 0; i < ELEVATOR_CAPACITY && num_waiting_up[current_floor-1] > 0 && num_passengers_in_elevators < ELEVATOR_CAPACITY; i++) {
            elevator_passengers[elevator_id][i] = 1;
            num_passengers_waiting_elevator--;
            num_passengers_in_elevators++;
            num_waiting_up[current_floor-1]--;
            total_passengers--;
        }
        up_button[current_floor-1] = false;
    }
    if (num_waiting_down[current_floor-1] > 0 && !elevator_directions[elevator_id]) {
        for (int i = 0; i < ELEVATOR_CAPACITY && num_waiting_down[current_floor-1] > 0 && num_passengers_in_elevators < ELEVATOR_CAPACITY; i++) {
            elevator_passengers[elevator_id][i] = -1;
            num_passengers_waiting_elevator--;
            num_passengers_in_elevators++;
            num_waiting_down[current_floor-1]--;
            total_passengers--;
        }
        down_button[current_floor-1] = false;
    }
}

void unload_passengers(int elevator_id) {
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (elevator_passengers[elevator_id][i] != 0 && elevator_destinations[elevator_id][current_floor-1] == elevator_passengers[elevator_id][i]) {
            passengers_arrived++;
            num_passengers_in_elevators--;
            elevator_passengers[elevator_id][i] = 0;
            elevator_destinations[elevator_id][current_floor-1] = 0;
        }
    }
}