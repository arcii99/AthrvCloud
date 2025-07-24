//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // define variables for elevator simulation
    int floorCount = 5; // number of floors
    int elevatorPosition = 1; // start at first floor
    int elevatorDirection = 1; // 1 for up, -1 for down
    int elevatorStopTime = 2; // time to stop at each floor
    int passengerDestination = 0; // initialize to invalid location
    int elevatorDoorOpen = 0; // 1 if door is open, 0 if closed
    
    // simulate elevator movement
    while (1) {
        // print current status of elevator
        printf("Elevator is on floor %d\n", elevatorPosition);
        if (elevatorDoorOpen) {
            printf("Door is open\n");
        } else {
            printf("Door is closed\n");
        }
        
        // check if there are passengers waiting on current floor
        if (passengerDestination == elevatorPosition) {
            elevatorDoorOpen = 1; // open door
            printf("Passenger exits the elevator\n");
            passengerDestination = 0; // reset passenger destination
            elevatorStopTime = 2; // reset stop time
        }
        
        // check if there are passengers inside the elevator
        if (passengerDestination != 0) {
            // move towards passenger destination
            if (passengerDestination > elevatorPosition) {
                elevatorPosition++; // move up
            } else {
                elevatorPosition--; // move down
            }
            elevatorDoorOpen = 0; // close door
        } else {
            // move in current direction
            elevatorPosition += elevatorDirection; 
        }
        
        // check if elevator has reached the top or bottom floor
        if (elevatorPosition == floorCount || elevatorPosition == 1) {
            elevatorDirection *= -1; // reverse direction
        }
        
        // check if elevator has stopped at a floor
        if (!elevatorDoorOpen) {
            printf("Elevator is moving...\n");
            // randomly decide if elevator will stop at current floor
            int elevatorStop = rand() % 2;
            if (elevatorStop && elevatorPosition != passengerDestination) {
                elevatorDoorOpen = 1; // open door
                printf("Elevator stops at floor %d\n", elevatorPosition);
                // randomly decide if passenger will enter
                int passengerEnter = rand() % 2;
                if (passengerEnter) {
                    // enter random floor as destination
                    passengerDestination = (rand() % (floorCount - 1)) + 1;
                    printf("Passenger enters the elevator\n");
                }
                elevatorStopTime = 5; // set stop time
            }
        }
        
        // wait for elevator to move or stop
        printf("\n");
        if (elevatorStopTime > 0) {
            elevatorStopTime--; // decrement stop time
            continue;
        }
        // sleep for 1 second to simulate elevator movement
        sleep(1);
    }
    
    return 0;
}