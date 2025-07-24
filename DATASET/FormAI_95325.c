//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

// These are global variables for easy access inside functions
int elevatorFloor = 1;
int passengerCount = 0;
int passengerFloors[MAX_PASSENGERS];
int destinations[MAX_FLOORS] = {0};

// Function to print the current state of the elevator and passengers
void printState() {
    printf("Elevator is currently on floor %d\n", elevatorFloor);
    printf("Destinations: ");
    for (int i = 1; i <= MAX_FLOORS; i++) {
        if (destinations[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Passengers: %d\n", passengerCount);
    if (passengerCount > 0) {
        printf("Passenger floors: ");
        for (int i = 0; i < passengerCount; i++) {
            printf("%d ", passengerFloors[i]);
        }
        printf("\n");
    }
}

// Function to add a passenger to the elevator
void addPassenger(int floor) {
    if (passengerCount < MAX_PASSENGERS) {
        passengerFloors[passengerCount] = floor;
        passengerCount++;
    } else {
        printf("Elevator is full! Cannot add passenger.\n");
    }
}

// Function to remove a passenger from the elevator
void removePassenger(int index) {
    for (int i = index; i < passengerCount-1; i++) {
        passengerFloors[i] = passengerFloors[i+1];
    }
    passengerCount--;
}

// Main function
int main() {
    int choice;
    do {
        // Print the current state of the elevator
        printState();

        // Get user input
        printf("\nEnter 1 to add a passenger, 2 to remove a passenger, 3 to set a destination, 4 to move the elevator, or 0 to quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a passenger
                printf("Enter the floor the passenger is on: ");
                int addFloor;
                scanf("%d", &addFloor);
                addPassenger(addFloor);
                break;
            case 2: // Remove a passenger
                printf("Enter the index of the passenger to remove: ");
                int removeIndex;
                scanf("%d", &removeIndex);
                removePassenger(removeIndex);
                break;
            case 3: // Set a destination
                printf("Enter the floor you want to go to: ");
                int destFloor;
                scanf("%d", &destFloor);
                if (destFloor >= 1 && destFloor <= MAX_FLOORS) {
                    destinations[destFloor] = 1;
                } else {
                    printf("Invalid floor number!\n");
                }
                break;
            case 4: // Move the elevator
                int dir;
                if (destinations[elevatorFloor] == 1) { // Check if the elevator has arrived at a destination
                    destinations[elevatorFloor] = 0;
                    int dropOffIndex = -1;
                    for (int i = 0; i < passengerCount; i++) { // Loop through passengers to find the one who wants to get off
                        if (passengerFloors[i] == elevatorFloor) {
                            dropOffIndex = i;
                            printf("Passenger %d has been dropped off on floor %d\n", i, elevatorFloor);
                            break;
                        }
                    }
                    if (dropOffIndex != -1) { // Remove the passenger who got off
                        removePassenger(dropOffIndex);
                    }
                } else if (passengerCount == 0) { // If there are no passengers, just move the elevator up or down
                    printf("Enter 1 to go up or 2 to go down: ");
                    scanf("%d", &dir);
                    if (dir == 1 && elevatorFloor < MAX_FLOORS) {
                        elevatorFloor++;
                    } else if (dir == 2 && elevatorFloor > 1) {
                        elevatorFloor--;
                    } else {
                        printf("Invalid direction!\n");
                    }
                } else { // If there are passengers, move to the next floor that one of them wants to go to
                    int tempDestinations[MAX_FLOORS] = {0};
                    for (int i = 0; i < passengerCount; i++) { // Loop through passengers to set their destinations
                        tempDestinations[passengerFloors[i]] = 1;
                    }
                    int destIndex = elevatorFloor;
                    if (dir == 1) { // Move up
                        while (destIndex <= MAX_FLOORS && tempDestinations[destIndex] != 1) {
                            destIndex++;
                        }
                    } else { // Move down
                        while (destIndex >= 1 && tempDestinations[destIndex] != 1) {
                            destIndex--;
                        }   
                    }
                    if (destIndex >= 1 && destIndex <= MAX_FLOORS) {
                        elevatorFloor = destIndex;
                    } else {
                        printf("No valid destination found!\n");
                    }
                }
                break;
            case 0: // Quit
                break;
            default: // Invalid input
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}