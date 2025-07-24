//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

// Elevator struct definition
typedef struct {
    int current_floor;
    int target_floor;
    int direction;  // 1 for up, -1 for down, 0 for idle
    int passengers[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

// Function prototypes
void print_status(Elevator elevator);
void update_direction(Elevator *elevator);
void move_elevator(Elevator *elevator);
void add_passenger(Elevator *elevator, int floor);
void remove_passenger(Elevator *elevator);

int main() {
    Elevator elevator = {1, 1, 0, {}, 0};
    
    // Simulate elevator activity for 10 seconds
    for (int i = 0; i < 10; i++) {
        int floor = rand() % MAX_FLOORS + 1;
        
        add_passenger(&elevator, floor);
        update_direction(&elevator);
        move_elevator(&elevator);
        remove_passenger(&elevator);
        
        printf("Time: %d seconds\n", i + 1);
        print_status(elevator);
        printf("\n");
    }
    
    return 0;
}

// Print current elevator status
void print_status(Elevator elevator) {
    printf("Current floor: %d\n", elevator.current_floor);
    printf("Target floor: %d\n", elevator.target_floor);
    printf("Direction: ");
    
    if (elevator.direction == 1) {
        printf("up\n");
    } else if (elevator.direction == -1) {
        printf("down\n");
    } else {
        printf("idle\n");
    }
    
    printf("Passengers: ");
    
    if (elevator.num_passengers == 0) {
        printf("none\n");
    } else {
        for (int i = 0; i < elevator.num_passengers; i++) {
            printf("%d ", elevator.passengers[i]);
        }
        
        printf("\n");
    }
}

// Update elevator direction based on current and target floor
void update_direction(Elevator *elevator) {
    if (elevator->current_floor < elevator->target_floor) {
        elevator->direction = 1;
    } else if (elevator->current_floor > elevator->target_floor) {
        elevator->direction = -1;
    } else {
        elevator->direction = 0;
    }
}

// Move elevator one floor in the current direction
void move_elevator(Elevator *elevator) {
    if (elevator->direction == 1) {
        elevator->current_floor++;
    } else if (elevator->direction == -1) {
        elevator->current_floor--;
    }
}

// Add passenger to elevator if there is still room
void add_passenger(Elevator *elevator, int floor) {
    if (elevator->num_passengers < MAX_PASSENGERS) {
        elevator->passengers[elevator->num_passengers] = floor;
        elevator->num_passengers++;
    } else {
        printf("Elevator full, passenger not added.\n");
    }
}

// Remove passenger from elevator if current floor is target floor
void remove_passenger(Elevator *elevator) {
    for (int i = 0; i < elevator->num_passengers; i++) {
        if (elevator->passengers[i] == elevator->current_floor) {
            elevator->passengers[i] = 0;
            
            for (int j = i; j < elevator->num_passengers - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            
            elevator->num_passengers--;
            i--;
        }
    }
}