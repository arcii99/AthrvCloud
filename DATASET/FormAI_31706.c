//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: portable
// C Elevator Simulation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10  // Number of floors
#define ELEVATOR_CAPACITY 10  // Elevator capacity
#define MAX_PEOPLE 30  // Maximum number of people waiting for the elevator
#define MAX_WEIGHT 1000.0  // Maximum weight allowance in pounds
#define DOOR_OPEN_TIME 2  // Time, in seconds, for elevator door to stay open
#define MOVEMENT_TIME 3  // Time, in seconds, for elevator to travel one floor

// Function to generate random number between a and b
int randNumBetween(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// Function to calculate total weight of people in elevator
double calcTotalWeight(int numPeople) {
    double totalWeight = 0;
    for (int i = 0; i < numPeople; i++) {
        totalWeight += randNumBetween(80, 250);  // Assuming weight of people is between 80 and 250 pounds
    }
    return totalWeight;
}

int main() {
    srand(time(NULL));  // Seed random number generator
    
    // Initialize variables
    int currentFloor = 1;
    int destinationFloor = 1;
    int numPeopleInElevator = 0;
    double totalWeightInElevator = 0.0;
    int peopleWaiting[NUM_FLOORS] = {0};  // Array to keep track of people waiting on each floor
    int totalPeopleGenerated = 0;
    
    // Loop until user terminates program
    while (1) {
        // Generate new people waiting for elevator if less than MAX_PEOPLE waiting
        if (totalPeopleGenerated < MAX_PEOPLE && rand() % 10 <= 5) {
            int destination = randNumBetween(1, NUM_FLOORS);
            while (destination == currentFloor) {  // Prevent generating people for current floor
                destination = randNumBetween(1, NUM_FLOORS);
            }
            peopleWaiting[destination - 1]++;
            totalPeopleGenerated++;
        }
        
        // Check if elevator has arrived at its destination
        if (currentFloor == destinationFloor) {
            totalWeightInElevator = 0.0;
            // Open elevator door and let people out
            printf("Elevator has arrived at floor %d\n", currentFloor);
            printf("Door opening...\n");
            printf("People exiting elevator:\n");
            for (int i = 0; i < numPeopleInElevator; i++) {
                printf("    Person %d\n", i+1);
            }
            numPeopleInElevator = 0;
            printf("Door closing...\n");
            printf("Elevator moving to next floor...\n");
            printf("\n");
            sleep(DOOR_OPEN_TIME);  // Wait for door to close
            destinationFloor = randNumBetween(1, NUM_FLOORS);
            while (destinationFloor == currentFloor) {  // Prevent selecting current floor as destination
                destinationFloor = randNumBetween(1, NUM_FLOORS);
            }
        }
        // Otherwise, continue moving elevator towards its destination
        else {
            // Check if elevator is full or weight limit will be reached
            if (numPeopleInElevator >= ELEVATOR_CAPACITY || totalWeightInElevator >= MAX_WEIGHT) {
                printf("Elevator is full or cannot accommodate any more weight. Moving to next floor...\n");
                printf("\n");
                sleep(MOVEMENT_TIME);  // Wait for elevator to move to next floor
                // Determine next destination floor based on remaining people waiting
                int closestFloor = -1;
                int smallestDifference = NUM_FLOORS;
                for (int i = 0; i < NUM_FLOORS; i++) {
                    if (peopleWaiting[i] > 0) {
                        int difference = abs(i+1 - currentFloor);
                        if (difference < smallestDifference) {
                            closestFloor = i+1;
                            smallestDifference = difference;
                        }
                    }
                }
                destinationFloor = closestFloor;
            }
            // Otherwise, pick up people waiting on current floor
            else {
                int numPeopleToPickup = peopleWaiting[currentFloor - 1];
                if (numPeopleToPickup > 0) {
                    printf("Elevator has arrived at floor %d\n", currentFloor);
                    printf("Door opening...\n");
                    printf("People entering elevator:\n");
                    for (int i = 0; i < numPeopleToPickup; i++) {
                        printf("    Person %d\n", i+1);
                    }
                    numPeopleInElevator += numPeopleToPickup;
                    totalWeightInElevator = calcTotalWeight(numPeopleInElevator);
                    peopleWaiting[currentFloor - 1] = 0;
                    currentFloor = destinationFloor;
                    printf("Door closing...\n");
                    printf("Elevator moving to next floor...\n");
                    printf("\n");
                    sleep(DOOR_OPEN_TIME);  // Wait for door to close
                }
                else {  // If no people waiting on current floor, continue moving elevator towards destination
                    printf("Elevator moving to next floor...\n");
                    printf("\n");
                    sleep(MOVEMENT_TIME);  // Wait for elevator to move to next floor
                    if (currentFloor < destinationFloor) {
                        currentFloor++;
                    }
                    else {
                        currentFloor--;
                    }
                }
            }
        }
    }
    
    return 0;
}