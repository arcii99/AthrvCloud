//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

// Struct to represent a person
typedef struct {
    int startFloor;
    int targetFloor;
} Person;

// Recursive function to simulate the elevator
void elevator(int currentFloor, int direction, int numPeople, Person people[MAX_PEOPLE], int numFloors, int floors[MAX_FLOORS]) {
    // Print current floor
    printf("Elevator is on floor %d\n", currentFloor);

    // Stop elevator if reached target floor of any person
    for (int i = 0; i < numPeople; i++) {
        if (people[i].targetFloor == currentFloor) {
            printf("Elevator stopped to let off person starting from floor %d\n", people[i].startFloor);

            // Remove person from the list
            for (int j = i; j < numPeople - 1; j++) {
                people[j] = people[j + 1];
            }
            numPeople--;

            // Check if elevator is empty
            if (numPeople == 0) {
                return;
            }
        }
    }

    // Change direction if reached top/bottom floor
    if (currentFloor == numFloors || currentFloor == 1) {
        direction *= -1;
    }

    // Check if there are people waiting on current floor
    for (int i = 0; i < numPeople; i++) {
        if (people[i].startFloor == currentFloor) {
            printf("Elevator stopped to pick up person going to floor %d\n", people[i].targetFloor);

            // Remove person from the list of waiting people
            for (int j = i; j < numPeople - 1; j++) {
                people[j] = people[j + 1];
            }
            numPeople--;

            // Add person's destination floor to floors[] if not already present
            int found = 0;
            for (int j = 0; j < numFloors; j++) {
                if (floors[j] == people[i].targetFloor) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                floors[numFloors++] = people[i].targetFloor;
            }

            // Add person's destination floor to floors[] if not already present
            found = 0;
            for (int j = 0; j < numFloors; j++) {
                if (floors[j] == people[i].targetFloor) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                floors[numFloors++] = people[i].targetFloor;
            }
        }
    }

    // Sort floors[] based on distance from current floor
    for (int i = 0; i < numFloors - 1; i++) {
        for (int j = 0; j < numFloors - i - 1; j++) {
            if (abs(currentFloor - floors[j]) > abs(currentFloor - floors[j + 1])) {
                int temp = floors[j];
                floors[j] = floors[j + 1];
                floors[j + 1] = temp;
            }
        }
    }

    // Move elevator to next target floor
    int nextFloor;
    for (int i = 0; i < numFloors; i++) {
        if (floors[i] * direction > currentFloor * direction) {
            nextFloor = floors[i];
            break;
        }
    }
    elevator(nextFloor, direction, numPeople, people, numFloors, floors);
}

int main() {
    // Initialize variables
    int numPeople = 4;
    Person people[MAX_PEOPLE] = {
        {1, 5},
        {2, 7},
        {3, 4},
        {9, 2}
    };
    int numFloors = 3;
    int floors[MAX_FLOORS] = {5, 7, 4};

    // Start elevator on floor 1, going up
    elevator(1, 1, numPeople, people, numFloors, floors);

    return 0;
}