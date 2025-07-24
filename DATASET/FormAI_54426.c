//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int currentFloor = 1;
int destinationFloor;
int direction = 0; // 0 for stationary, 1 for going up, -1 for going down
int insideElevator = 0; // 1 if someone is inside the elevator, 0 otherwise
int peopleWaiting[7] = {0, 0, 0, 0, 0, 0, 0}; // Stores the number of people waiting on each floor
int capacity = 8; // Maximum number of people the elevator can carry
int peopleInside = 0; // Number of people currently inside the elevator

// Function to simulate waiting time
void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

// Function to move the elevator to the next floor
void moveElevator() {
    if (direction == 1) {
        currentFloor++;
    } else if (direction == -1) {
        currentFloor--;
    }
    printf("Elevator at floor %d\n", currentFloor);
    wait(1);
}

// Function to add a person to the elevator
void addPerson() {
    if (peopleInside < capacity) {
        printf("Person enters elevator\n");
        peopleInside++;
        insideElevator = 1;
        peopleWaiting[currentFloor]--; // Remove person from waiting list
    } else {
        printf("Elevator is full\n");
    }
}

// Function to remove a person from the elevator
void removePerson() {
    printf("Person exits elevator\n");
    peopleInside--;
    if (peopleInside == 0) {
        insideElevator = 0;
    }
}

// Main function
int main() {
    // Seed the random number generator for simulating people waiting on floors
    srand(time(NULL));
	
    // Loop to simulate elevator operation
    while (1) {
        // Check if there are people waiting on the current floor
        if (insideElevator == 0 && peopleWaiting[currentFloor] > 0) {
            printf("Elevator doors open\n");
            addPerson();
        }
		
        // Check if there are people waiting on other floors in the same direction as the elevator
        int i;
        for (i = currentFloor + direction; i < 7 && i >= 0; i += direction) {
            if (peopleWaiting[i] > 0) {
                destinationFloor = i;
                printf("Elevator doors open\n");
                addPerson();
            }
        }
		
        // If nobody is inside the elevator, check if there are people waiting on any floor
        if (insideElevator == 0) {
            int j;
            for (j = 0; j < 7; j++) {
                if (peopleWaiting[j] > 0) {
                    destinationFloor = j;
                    break;
                }
            }
        }
		
        // If there are people inside the elevator and they have reached their destination
        if (insideElevator == 1 && currentFloor == destinationFloor) {
            printf("Elevator doors open\n");
            removePerson();
        }
		
        // If the elevator is full or there are no people waiting, go to the first floor
        if (peopleInside == capacity || (insideElevator == 0 && peopleWaiting[1] == 0)) {
            destinationFloor = 1;
        }
		
        // Change direction if the elevator has reached the top floor or the ground floor
        if (currentFloor == 7) {
            direction = -1;
        } else if (currentFloor == 0) {
            direction = 1;
        }
		
        // Move the elevator to the next floor
        moveElevator();
    }
    return 0;
}