//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 15

// Define the structure for elevator
typedef struct {
    int current_floor;
    int passengers;
    int direction; // 1 for up, -1 for down, 0 for idle
    int dest_floor[MAX_FLOORS];
    int dest_count;
} Elevator;

// Define the structure for passenger
typedef struct {
    int current_floor;
    int dest_floor;
    int id;
} Passenger;

// Define the function to move the elevator
void move_elevator(Elevator *elevator, int floor) {
    elevator -> current_floor = floor;
    printf("Elevator reached floor %d\n", floor);
    int i, temp_dest_floor[MAX_FLOORS], count=0;
    for(i=0; i<elevator->dest_count; i++) {
        if(floor == elevator->dest_floor[i]) {
            printf("Passenger %d exited on floor %d\n", elevator->passengers, floor);
            elevator->passengers--;
        } else {
            temp_dest_floor[count++] = elevator->dest_floor[i];
        }
    }
    if(count<elevator->dest_count) {
        elevator->dest_count = count;
        for(i=0; i<count; i++) {
            elevator->dest_floor[i] = temp_dest_floor[i];
        }
    }
    if(elevator->direction == 1) { // Going up
        if(floor == MAX_FLOORS) {
            elevator->direction = -1; // Change direction when elevator reaches last floor
        } else if(count > 0 && elevator->dest_floor[0]>floor) { // Any passengers going up?
            return;
        } else { // Otherwise, go to next upper floor
            move_elevator(elevator, floor+1);
        }
    } else if(elevator->direction == -1) { // Going down
        if(floor == 1) {
            elevator->direction = 1; // Change direction when elevator reaches first floor
        } else if(count > 0 && elevator->dest_floor[0]<floor) { // Any passengers going down?
            return;
        } else { // Otherwise, go to next lower floor
            move_elevator(elevator, floor-1);
        }
    } else { // Elevator is idle
        if(count > 0) {
            elevator->direction = (elevator->dest_floor[0]>floor ? 1 : -1); // Set direction based on first passenger's destination
            move_elevator(elevator, floor+(elevator->direction)); // Start moving towards first passenger's destination
        }
    }  
}

// Define the main function
int main() {
    srand(time(0));
    Elevator elevator = {1, 0, 0, {0}, 0};
    Passenger passengers[MAX_PASSENGERS];
    int i;
    for(i=0; i<MAX_PASSENGERS; i++) { // Randomly generate passengers with destinations
        passengers[i].id = i+1;
        passengers[i].current_floor = rand()%MAX_FLOORS + 1;
        passengers[i].dest_floor = rand()%MAX_FLOORS + 1;
        printf("Passenger %d is on floor %d and wants to go to floor %d\n", passengers[i].id, passengers[i].current_floor, passengers[i].dest_floor);
    }
    printf("Elevator starts at floor %d\n", elevator.current_floor);
    while(1) { // Keep running the simulation until stopped
        if(elevator.dest_count == 0) { // If no passengers inside, check for any waiting at current floor
            for(i=0; i<MAX_PASSENGERS; i++) {
                if(passengers[i].current_floor == elevator.current_floor) {
                    elevator.dest_floor[elevator.dest_count++] = passengers[i].dest_floor;
                    elevator.passengers++;
                    printf("Passenger %d entered elevator on floor %d\n", passengers[i].id, elevator.current_floor);
                }
            }            
        } else {
            move_elevator(&elevator, elevator.current_floor); // Move the elevator to next floor
        }
        usleep(500000); // Wait for 500ms before moving again
    }
    return 0;
}