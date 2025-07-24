//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Constants
#define MIN_FLOOR 1
#define MAX_FLOOR 10
#define NUM_ELEVATORS 3
#define MAX_CAPACITY 10

// Structures
typedef struct {
    int current_floor;
    bool going_up;
    int passengers[MAX_CAPACITY];
    int num_passengers;
} Elevator;

// Global Variables
Elevator elevators[NUM_ELEVATORS];

// Function prototypes
void move_elevator(Elevator* elevator);
void pickup_passenger(Elevator* elevator, int passenger);
void drop_off_passenger(Elevator* elevator, int floor);
void print_status();
int get_floor_input();
int get_passenger_input();

int main() {
    // Initialize elevators to first floor
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].going_up = true;
        elevators[i].num_passengers = 0;
    }
    
    while (true) {
        print_status();
        
        // Prompt user for passenger pickup or drop off
        int choice;
        printf("\n[1] Pickup passenger\n[2] Drop off passenger\n[3] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {  // Pickup passenger
                printf("Which elevator (1-%d) would you like to pickup the passenger?\n", NUM_ELEVATORS);
                int elevator_choice = get_floor_input();
                
                printf("How many passengers will be picked up (max capacity: %d)?\n", 
                    MAX_CAPACITY - elevators[elevator_choice - 1].num_passengers);
                int num_passengers = get_passenger_input();
                
                for (int i = 0; i < num_passengers; i++) {
                    printf("Enter passenger #%d destination floor:\n", i + 1);
                    int destination_floor = get_floor_input();
                    pickup_passenger(&elevators[elevator_choice - 1], destination_floor);
                }
                
                move_elevator(&elevators[elevator_choice - 1]);
                break;
            }
            
            case 2: {  // Drop off passenger
                printf("Which elevator (1-%d) would you like to drop off the passenger?\n", NUM_ELEVATORS);
                int elevator_choice = get_floor_input();
                
                printf("Enter floor where passenger will drop off:\n");
                int drop_floor = get_floor_input();
                
                drop_off_passenger(&elevators[elevator_choice - 1], drop_floor);
                
                move_elevator(&elevators[elevator_choice - 1]);
                break;
            }
            
            case 3: {  // Exit program
                printf("Exiting program.\n");
                exit(0);
            }
            
            default: {  // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    
    return 0;
}

void move_elevator(Elevator* elevator) {
    // Check elevator direction and adjust current floor accordingly
    if (elevator->going_up) {
        elevator->current_floor++;
    } else {
        elevator->current_floor--;
    }
    
    // If elevator reaches end floor, change direction
    if (elevator->current_floor == MIN_FLOOR || elevator->current_floor == MAX_FLOOR) {
        elevator->going_up = !elevator->going_up;
    }
}

void pickup_passenger(Elevator* elevator, int passenger) {
    // Check if elevator is at passenger's current floor
    if (elevator->current_floor == passenger) {
        // Check if elevator has reached max capacity
        if (elevator->num_passengers < MAX_CAPACITY) {
            elevator->passengers[elevator->num_passengers] = passenger;
            elevator->num_passengers++;
            printf("Passenger picked up on floor %d.\n", passenger);
        } else {
            printf("Elevator is at max capacity.\n");
        }
    } else {
        printf("Elevator is not at passenger's current floor.\n");
    }
}

void drop_off_passenger(Elevator* elevator, int floor) {
    // Check if elevator has any passengers
    if (elevator->num_passengers > 0) {
        // Check if any passengers want to get off at current floor
        for (int i = 0; i < elevator->num_passengers; i++) {
            if (elevator->passengers[i] == floor) {
                elevator->passengers[i] = 0;
                elevator->num_passengers--;
                printf("Passenger dropped off on floor %d.\n", floor);
                break;
            }
        }
    } else {
        printf("Elevator has no passengers.\n");
    }
}

void print_status() {
    // Print current elevator status
    printf("ELEVATOR STATUS:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d - Floor: %d, Direction: %s, Passengers: [",
            i + 1, elevators[i].current_floor, 
            elevators[i].going_up ? "Up" : "Down");
        
        for (int j = 0; j < elevators[i].num_passengers; j++) {
            printf("%d", elevators[i].passengers[j]);
            if (j < elevators[i].num_passengers - 1) {
                printf(", ");
            }
        }
        
        printf("]\n");
    }
}

int get_floor_input() {
    int input;
    printf("Enter floor (1-10):\n");
    scanf("%d", &input);
    
    while (input < 1 || input > 10) {
        printf("Invalid floor. Please enter a floor between 1 and 10:\n");
        scanf("%d", &input);
    }
    
    return input;
}

int get_passenger_input() {
    int input;
    scanf("%d", &input);
    
    while (input < 1 || input > MAX_CAPACITY) {
        printf("Invalid number of passengers. Please enter a number between 1 and %d:\n", MAX_CAPACITY);
        scanf("%d", &input);
    }
    
    return input;
}