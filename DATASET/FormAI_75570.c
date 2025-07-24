//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_ELEVATORS 3 // Number of elevators
#define NUM_FLOORS 10 // Number of floors
#define MAX_CAPACITY 10 // Max capacity of each elevator

typedef struct {
    int id; // id of the elevator
    int current_floor; // current floor of the elevator
    int destination_floor; // destination floor of the elevator
    int passengers[MAX_CAPACITY]; // list of passengers in the elevator
    int num_passengers; // current number of passengers in the elevator
} Elevator;

Elevator elevators[NUM_ELEVATORS]; // Array of all elevators
int waiting_passengers[NUM_FLOORS]; // Array of passengers waiting on each floor

// Function to initialize all elevators
void initialize_elevators() {
    for(int i=0; i<NUM_ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].current_floor = 1; // Elevators all start at the first floor
        elevators[i].destination_floor = -1; // No destination floor at the start
        for(int j=0; j<MAX_CAPACITY; j++)
            elevators[i].passengers[j] = 0; // All elevators start empty
        elevators[i].num_passengers = 0;
    }
}

// Function to simulate the movement of an elevator for one step
void move_elevator(Elevator *elevator) {
    if(elevator->current_floor == elevator->destination_floor) {
        // Elevator has reached its destination floor
        printf("Elevator %d has arrived at floor %d\n", elevator->id, elevator->current_floor);
        // Remove all passengers with this destination floor
        for(int i=0; i<elevator->num_passengers; i++) {
            if(elevator->passengers[i] == elevator->destination_floor) {
                elevator->passengers[i] = 0;
                elevator->num_passengers--;
            }
        }
        // Determine new destination floor and add passengers going in the same direction
        if(elevator->num_passengers > 0) {
            int distance = NUM_FLOORS + 1;
            for(int i=1; i<=NUM_FLOORS; i++) {
                int num_passengers = 0;
                for(int j=0; j<elevator->num_passengers; j++) {
                    if((elevator->destination_floor < elevator->current_floor && elevator->passengers[j] < elevator->current_floor && elevator->passengers[j] >= i) || 
                        (elevator->destination_floor > elevator->current_floor && elevator->passengers[j] > elevator->current_floor && elevator->passengers[j] <= i))
                        num_passengers++;
                }
                if(num_passengers > 0 && abs(i-elevator->current_floor) < distance) {
                    distance = abs(i-elevator->current_floor);
                    elevator->destination_floor = i;
                }
            }
        } else {
            elevator->destination_floor = -1; // No destination floor if no passengers
        }
    } else if(elevator->destination_floor == -1) {
        // Elevator is idle, choose a floor to go to
        int max_num_passengers = -1;
        int floor = -1;
        for(int i=1; i<=NUM_FLOORS; i++) {
            if(waiting_passengers[i-1] > 0) {
                int num_passengers = 0;
                for(int j=0; j<elevator->num_passengers; j++) {
                    if((elevator->passengers[j] < elevator->current_floor && i < elevator->current_floor) || (elevator->passengers[j] > elevator->current_floor && i > elevator->current_floor))
                        num_passengers++;
                }
                if(num_passengers >= MAX_CAPACITY-elevator->num_passengers) { // Do not exceed max capacity
                    printf("Elevator %d is full, waiting for the next one\n", elevator->id);
                    return; // Elevator cannot take any more passengers at this floor
                }
                if(waiting_passengers[i-1] > max_num_passengers) {
                    max_num_passengers = waiting_passengers[i-1];
                    floor = i;
                }
            }
        }
        if(floor != -1) {
            printf("Elevator %d is moving from floor %d to floor %d\n", elevator->id, elevator->current_floor, floor);
            elevator->destination_floor = floor;
        } else {
            printf("Elevator %d is idle at floor %d\n", elevator->id, elevator->current_floor); // No passengers waiting
        }
    } else {
        // Elevator is moving towards its destination floor
        printf("Elevator %d is moving from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->destination_floor);
        if(elevator->destination_floor > elevator->current_floor)
            elevator->current_floor++;
        else if(elevator->destination_floor < elevator->current_floor)
            elevator->current_floor--;
        // Add waiting passengers going in the same direction
        int max_num_passengers = MAX_CAPACITY - elevator->num_passengers;
        for(int i=0; i<max_num_passengers; i++) {
            if(waiting_passengers[elevator->current_floor-1] > 0) {
                elevator->passengers[elevator->num_passengers++] = elevator->current_floor;
                waiting_passengers[elevator->current_floor-1]--;
            } else {
                break;
            }
        }
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    // Initialize elevator system
    initialize_elevators();
    // Generate random waiting passengers
    for(int i=0; i<NUM_FLOORS; i++) {
        waiting_passengers[i] = rand() % (MAX_CAPACITY+1);
        printf("Floor %d has %d waiting passengers\n", i+1, waiting_passengers[i]);
    }
    // Simulate elevator movement for 100 steps
    for(int step=1; step<=100; step++) {
        printf("--------------Step %d--------------\n", step);
        for(int i=0; i<NUM_ELEVATORS; i++) {
            move_elevator(&elevators[i]);
        }
        printf("-----------------------------------\n");
    }
    return 0;
}