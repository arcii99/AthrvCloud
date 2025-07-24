//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int currentFloor = 0; // current floor of the elevator
int destinationFloor = 0; // destination floor
int maxFloor = 10; // maximum number of floors 
int elevatorStatus = 0; // 0 for stopped, 1 for moving up, 2 for moving down
int numPassengers = 0; // number of passengers currently in the elevator
 
// function to simulate elevator movement
void moveElevator() {
    if(currentFloor < destinationFloor) {
        elevatorStatus = 1; // set to moving up
        printf("Elevator is moving up from floor %d to floor %d\n", currentFloor, (currentFloor+1));
        currentFloor++;
    } else {
        elevatorStatus = 2; // set to moving down
        printf("Elevator is moving down from floor %d to floor %d\n", currentFloor, (currentFloor-1));
        currentFloor--;
    }
}
 
int main() {
    srand(time(NULL)); // seed random number generator
 
    while(1) { // infinite loop to simulate elevator operation
        if(numPassengers == 0) { // if there are no passengers, elevator stops at ground floor
            destinationFloor = 0;
        } else { // otherwise, elevator moves randomly within building
            destinationFloor = rand() % maxFloor + 1;
        }
 
        while(currentFloor != destinationFloor) { // continue to move elevator until destination floor is reached
            moveElevator();
            sleep(1); // wait for 1 second to simulate elevator movement
        }
 
        if(currentFloor == destinationFloor) { // reached destination floor
            elevatorStatus = 0; // elevator stops
            printf("Elevator has arrived at floor %d\n", currentFloor);
            if(numPassengers > 0) {
                printf("%d passengers have exited the elevator at floor %d\n", numPassengers, currentFloor);
                numPassengers = 0; // all passengers have exited
            }
            sleep(5); // wait for 5 seconds to simulate passengers entering/exiting elevator
            if(currentFloor != 0) { // if not at ground floor, passengers can enter elevator
                int numEntering = rand() % (10 - numPassengers) + 1; // up to 10 passengers can enter
                printf("%d passengers have entered the elevator at floor %d\n", numEntering, currentFloor);
                numPassengers += numEntering; // increment number of passengers
            }
        }
    }
 
    return 0;
}