//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Use MAX_FLOORS and MIN_FLOORS constant to adjust the number of floors in the building
#define MAX_FLOORS 10
#define MIN_FLOORS 3

// Use MAX_ELEVATORS constant to adjust the number of elevators in the building
#define MAX_ELEVATORS 3

// Use MAX_PEOPLE constant to adjust the number of people in the building
#define MAX_PEOPLE 20

// Use SECONDS_PER_FLOOR constant to adjust the time it takes for an elevator to travel one floor
#define SECONDS_PER_FLOOR 2

// Define a Person struct to represent a person in the building
typedef struct Person {
    int currentFloor;   // Current floor of the person
    int destination;    // Destination floor of the person
} Person;

// Define an Elevator struct to represent an elevator in the building
typedef struct Elevator {
    int currentFloor;           // Current floor of the elevator
    int destination;            // Destination floor of the elevator
    bool isMoving;              // Flag indicating if the elevator is moving
    bool isDoorOpen;            // Flag indicating if the elevator door is open
    int doorCloseTime;          // Time when the elevator door will close
    Person* passengers[MAX_PEOPLE]; // Array of pointers to the passengers in the elevator
    int numPassengers;          // Number of passengers currently in the elevator
} Elevator;

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Initialize the building
    int numFloors = rand() % (MAX_FLOORS - MIN_FLOORS + 1) + MIN_FLOORS; // Random number of floors between MIN_FLOORS and MAX_FLOORS
    int numElevators = rand() % (MAX_ELEVATORS + 1); // Random number of elevators between 0 and MAX_ELEVATORS
    Elevator elevators[MAX_ELEVATORS];
    for (int i = 0; i < numElevators; i++) {
        elevators[i].currentFloor = 1; // Initially, all elevators are on the first floor
        elevators[i].destination = 1;
        elevators[i].isMoving = false;
        elevators[i].isDoorOpen = true; // Initially, all elevator doors are open
        elevators[i].doorCloseTime = 0;
        elevators[i].numPassengers = 0;
    }
    Person people[MAX_PEOPLE];
    for (int i = 0; i < MAX_PEOPLE; i++) {
        people[i].currentFloor = rand() % numFloors + 1; // Random current floor between 1 and numFloors
        people[i].destination = rand() % numFloors + 1; // Random destination floor between 1 and numFloors
        while (people[i].currentFloor == people[i].destination) {
            people[i].destination = rand() % numFloors + 1; // Make sure the destination floor is different from the current floor
        }
    }
    
    // Main loop
    bool done = false;
    while (!done) {
        // Move elevators
        for (int i = 0; i < numElevators; i++) {
            if (elevators[i].isMoving) {
                if (elevators[i].currentFloor < elevators[i].destination) {
                    elevators[i].currentFloor++;
                } else if (elevators[i].currentFloor > elevators[i].destination) {
                    elevators[i].currentFloor--;
                } else { // arrived at destination
                    elevators[i].isMoving = false;
                    elevators[i].isDoorOpen = true;
                    elevators[i].doorCloseTime = time(NULL) + 5; // Keep door open for 5 seconds
                    printf("Elevator %d has arrived at floor %d.\n", i + 1, elevators[i].currentFloor);
                    
                    // Drop off passengers
                    for (int j = 0; j < elevators[i].numPassengers; j++) {
                        if (elevators[i].passengers[j]->destination == elevators[i].currentFloor) {
                            printf("Person %d has left elevator %d at floor %d.\n", (int)elevators[i].passengers[j], i + 1, elevators[i].currentFloor);
                            elevators[i].passengers[j] = NULL;
                            elevators[i].numPassengers--;
                        }
                    }

                    // Pick up passengers
                    for (int j = 0; j < MAX_PEOPLE; j++) {
                        if (elevators[i].numPassengers == MAX_PEOPLE) {
                            break; // Elevator is full
                        }
                        if (people[j].currentFloor == elevators[i].currentFloor && people[j].destination != elevators[i].currentFloor) {
                            printf("Person %d has entered elevator %d at floor %d.\n", j, i + 1, elevators[i].currentFloor);
                            elevators[i].passengers[elevators[i].numPassengers++] = &people[j];
                        }
                    }
                }
            } else if (time(NULL) >= elevators[i].doorCloseTime) { // Check if door should close
                elevators[i].isDoorOpen = false;
                printf("Elevator %d door has closed at floor %d.\n", i + 1, elevators[i].currentFloor);
                
                // Decide where to go next
                int closestFloor = -1;
                int closestDist = numFloors + 1;
                for (int j = 1; j <= numFloors; j++) {
                    int dist = abs(j - elevators[i].currentFloor);
                    if (closestFloor == -1 || dist < closestDist) {
                        // Check if there are passengers on this floor that need to go up
                        bool upFound = false;
                        for (int k = 0; k < MAX_PEOPLE; k++) {
                            if (people[k].currentFloor == j && people[k].destination > j) {
                                upFound = true;
                                break;
                            }
                        }
                        if (upFound) {
                            closestFloor = j;
                            closestDist = dist;
                        }
                    }
                }
                if (closestFloor == -1) {
                    // No passengers need to go up, so go to the first floor
                    elevators[i].destination = 1;
                } else {
                    elevators[i].destination = closestFloor;
                }
                
                // Start moving
                if (elevators[i].destination > elevators[i].currentFloor) {
                    printf("Elevator %d is moving up from floor %d to floor %d.\n", i + 1, elevators[i].currentFloor, elevators[i].destination);
                } else {
                    printf("Elevator %d is moving down from floor %d to floor %d.\n", i + 1, elevators[i].currentFloor, elevators[i].destination);
                }
                elevators[i].isMoving = true;
            }
        }
        
        // Wait for a while before updating again
        clock_t startTime = clock();
        while (((float)(clock() - startTime) / CLOCKS_PER_SEC) < SECONDS_PER_FLOOR) {}
        
        // Check if all passengers have reached their destinations
        done = true;
        for (int i = 0; i < MAX_PEOPLE; i++) {
            if (people[i].currentFloor != people[i].destination) {
                done = false;
                break;
            }
        }
    }
    
    printf("All passengers have reached their destinations.\n");
    
    return 0;
}