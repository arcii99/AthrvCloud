//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
// Define the elevator struct
typedef struct {
    int current_floor;
    int direction;
    int capacity;
} Elevator;

// Define the floor struct
typedef struct {
    int passengers_waiting; // number of people waiting for the elevator
    int destination_floor;
} Floor;

// Define constants for the number of floors and elevator capacity
#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 8

int main() {
    // Initialize the elevator struct
    Elevator elevator = {1, 1, 0};

    // Initialize the building array
    Floor building[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        building[i].passengers_waiting = 0;
        building[i].destination_floor = -1;
    }

    // ... rest of the code goes here
}