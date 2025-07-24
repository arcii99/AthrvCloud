//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

// Elevator struct holding current floor, direction and status
typedef struct {
    int floor;
    int direction;  // 0 for up, 1 for down
    bool is_moving;
} Elevator;

// Config struct holding info about the building and elevators
typedef struct {
    int num_floors;
    int num_elevators;
    Elevator elevators[MAX_ELEVATORS];
} Config;

// Helper function to print out the status of all elevators
void print_elevators_status(Config *config) {
    for (int i = 0; i < config->num_elevators; i++) {
        Elevator *elevator = &config->elevators[i];
        printf("Elevator %d is currently on floor %d, going %s\n", 
                i + 1, elevator->floor, elevator->direction == 0 ? "up" : "down");
    }
}

// Helper function to handle moving an elevator up a floor
void move_elevator_up(Elevator *elevator) {
    elevator->floor++;
    printf("Elevator on floor %d moving up to floor %d\n", elevator->floor - 1, elevator->floor);
}

// Helper function to handle moving an elevator down a floor
void move_elevator_down(Elevator *elevator) {
    elevator->floor--;
    printf("Elevator on floor %d moving down to floor %d\n", elevator->floor + 1, elevator->floor);
}

// Main function to simulate elevators in a building
int main() {
    Config config = {
        .num_floors = 10,
        .num_elevators = 2,
        .elevators = {
            {.floor = 0, .direction = 0, .is_moving = false},
            {.floor = 5, .direction = 1, .is_moving = false}
        }
    };

    int target_floor = 8;  // Change this value to test different elevator usage

    printf("Welcome to our building with %d floors and %d elevators!\n", 
            config.num_floors, config.num_elevators);

    while (true) {
        // Print out the status of all elevators
        print_elevators_status(&config);

        // Check if any elevator is moving and update its current floor
        for (int i = 0; i < config.num_elevators; i++) {
            Elevator *elevator = &config.elevators[i];
            if (elevator->is_moving) {
                if (elevator->direction == 0) {
                    move_elevator_up(elevator);
                } else {
                    move_elevator_down(elevator);
                }

                if (elevator->floor == target_floor) {
                    printf("Elevator %d has arrived at floor %d\n", i + 1, target_floor);
                    elevator->is_moving = false;
                }
            }
        }

        // Find the nearest elevator and assign it to target floor
        Elevator *nearest_elevator = NULL;
        int nearest_distance = config.num_floors;
        for (int i = 0; i < config.num_elevators; i++) {
            Elevator *elevator = &config.elevators[i];
            if (!elevator->is_moving) {
                int distance = abs(elevator->floor - target_floor);
                if (distance < nearest_distance) {
                    nearest_distance = distance;
                    nearest_elevator = elevator;
                }
            }
        }

        // If no available elevator is found, wait for some time
        if (nearest_elevator == NULL) {
            printf("No available elevators at the moment. Please wait...\n");
            continue;
        }

        // Determine the direction of the elevator's movement
        if (nearest_elevator->floor < target_floor) {
            nearest_elevator->direction = 0;
        } else {
            nearest_elevator->direction = 1;
        }

        // Update elevator's movement status and print message
        nearest_elevator->is_moving = true;
        printf("Elevator %d is moving to floor %d\n", 
                (int)(nearest_elevator - config.elevators) + 1, target_floor);
    }

    return 0;
}