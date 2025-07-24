//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

int elevatorPosition = 0; // Current floor of the elevator
int passengerDestinations[MAX_PASSENGERS] = {0}; // Array of passenger destinations
int numPassengers = 0; // Number of passengers in the elevator

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min; 
}

// Function to simulate the elevator movement
void moveElevator(int floor) {
    printf("The elevator is on floor %d\n", floor);
    elevatorPosition = floor;
}

// Function to add a passenger to the elevator
void addPassenger(int destination) {
    if (numPassengers < MAX_PASSENGERS) {
        printf("A passenger has entered the elevator and wants to go to floor %d\n", destination);
        passengerDestinations[numPassengers] = destination;
        numPassengers++;
    } else {
        printf("The elevator is at full capacity\n");
    }
}

// Function to remove a passenger from the elevator
void removePassenger(int index) {
    printf("A passenger has reached their destination and has left the elevator on floor %d\n", elevatorPosition);
    numPassengers--;
    for (int i = index; i < numPassengers; i++) {
        passengerDestinations[i] = passengerDestinations[i+1];
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generato

    while (1) {
        // Generate a random floor to simulate a passenger call button press
        int pressedFloor = getRandomNumber(1, MAX_FLOORS);
        printf("Someone has pressed the elevator button on floor %d\n", pressedFloor);

        // Determine the direction the elevator needs to travel to reach the passenger
        int direction = pressedFloor - elevatorPosition;
        if (direction > 0) {
            printf("The elevator is moving up\n");
            for (int i = elevatorPosition + 1; i <= pressedFloor; i++) {
                moveElevator(i);
            }
        } else if (direction < 0) {
            printf("The elevator is moving down\n");
            for (int i = elevatorPosition - 1; i >= pressedFloor; i--) {
                moveElevator(i);
            }
        } else {
            printf("The elevator is already on the requested floor\n");
        }

        // Generate a random number of passengers to simulate entering the elevator
        int numNewPassengers = getRandomNumber(1, MAX_PASSENGERS - numPassengers);
        for (int i = 0; i < numNewPassengers; i++) {
            int destination = getRandomNumber(1, MAX_FLOORS);
            addPassenger(destination);
        }

        // Drop off passengers whose destination is the current floor
        for (int i = 0; i < numPassengers; i++) {
            if (passengerDestinations[i] == elevatorPosition) {
                removePassenger(i);
            }
        }
    }

    return 0;
}