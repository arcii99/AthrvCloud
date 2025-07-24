//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10 // number of floors in the building
#define TIME_INTERVAL 3 // time interval between floors

// enum to define the states of the elevator
enum ElevatorState {
    ELEVATOR_MOVING_UP,
    ELEVATOR_MOVING_DOWN,
    ELEVATOR_STOPPED
};

// function to generate a random number between given min and max values
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main(void) {
    // initialize variables
    int current_floor = 1;
    int passengers = 0;
    int destination_floor;
    enum ElevatorState elevator_state = ELEVATOR_STOPPED;
    
    // seed random number generator
    srand(time(NULL));
    
    // main loop
    while (1) {
        // check if elevator is stopped
        if (elevator_state == ELEVATOR_STOPPED) {
            // print current floor
            printf("Elevator at floor %d.\n", current_floor);
            
            // check for passengers
            if (rand_range(0, 1)) {
                // generate random destination floor
                do {
                    destination_floor = rand_range(1, FLOORS);
                } while (destination_floor == current_floor); // ensure destination is not current floor
                
                // print message
                printf("Passenger(s) waiting to go to floor %d.\n", destination_floor);
                
                // add passengers
                passengers++;
                
                // set elevator state 
                if (destination_floor > current_floor) {
                    elevator_state = ELEVATOR_MOVING_UP;
                } else {
                    elevator_state = ELEVATOR_MOVING_DOWN;
                }
            }
        } else {
            // check destination floor and move elevator
            if (destination_floor > current_floor) {
                printf("Elevator moving up to floor %d.\n", current_floor + 1);
                current_floor++;
            } else if (destination_floor < current_floor) {
                printf("Elevator moving down to floor %d.\n", current_floor - 1);
                current_floor--;
            } else {
                printf("Elevator arrived at floor %d.\n", current_floor);
                elevator_state = ELEVATOR_STOPPED;
                passengers--;
            }
        }
        
        // wait for next time interval
        sleep(TIME_INTERVAL);
    }

    return 0;
}