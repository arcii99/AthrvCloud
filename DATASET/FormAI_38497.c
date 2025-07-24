//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CAPACITY 10 // maximum capacity of the elevator
#define FLOORS 7 // number of floors in the building

// global variables
int currentFloor = 1;
int destinationFloor = 1;
char* direction = "up";
int passengersCount = 0;

// passenger structure
struct Passenger {
    char* name;
    int currentFloor;
    int destinationFloor;
};

// create passenger function
struct Passenger createPassenger(char* name, int currentFloor, int destinationFloor) {
    struct Passenger p;
    p.name = name;
    p.currentFloor = currentFloor;
    p.destinationFloor = destinationFloor;
    return p;
}

// elevator struct
struct Elevator {
    struct Passenger passengers[CAPACITY];
    int capacity;
    int current;
};

// create elevator function
struct Elevator createElevator(int capacity, int current) {
    struct Elevator e;
    e.capacity = capacity;
    e.current = current;
    return e;
}

// add passenger function
void addPassenger(struct Elevator* elevator, struct Passenger passenger) {
    if (passengersCount < elevator->capacity) {
        elevator->passengers[passengersCount] = passenger;
        passengersCount++;
    }
}

// remove passenger function
void removePassenger(struct Elevator* elevator, int index) {
    if (index < passengersCount) {
        for (int i = index; i < passengersCount - 1; i++) {
            elevator->passengers[i] = elevator->passengers[i + 1];
        }
        passengersCount--;
    }
}

// print elevator status function
void printElevatorStatus(struct Elevator* elevator) {
    printf("Current Floor: %d\n", currentFloor);
    printf("Direction: %s\n", direction);
    printf("Destination Floor: %d\n", destinationFloor);
    printf("Passengers: [");
    for (int i = 0; i < passengersCount; i++) {
        printf("%s", elevator->passengers[i].name);
        if (i != passengersCount - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int main() {
    struct Elevator elevator = createElevator(CAPACITY, 1);

    // create passengers and add them to the elevator
    struct Passenger p1 = createPassenger("Alice", 1, 6);
    addPassenger(&elevator, p1);
    struct Passenger p2 = createPassenger("Bob", 4, 2);
    addPassenger(&elevator, p2);

    // move the elevator
    while (currentFloor != FLOORS) {
        printf("Elevator at floor %d\n", currentFloor);
        printElevatorStatus(&elevator);
        // check if we have any passengers who want to get off at this floor
        for (int i = 0; i < passengersCount; i++) {
            if (elevator.passengers[i].destinationFloor == currentFloor) {
                printf("%s gets off the elevator at floor %d.\n", elevator.passengers[i].name, currentFloor);
                removePassenger(&elevator, i);
            }
        }
        // check if we have any passengers who want to get on at this floor
        for (int i = 0; i < passengersCount; i++) {
            if (elevator.passengers[i].currentFloor == currentFloor) {
                printf("%s gets on the elevator at floor %d.\n", elevator.passengers[i].name, currentFloor);
            }
        }
        // move the elevator to the next floor
        if (direction == "up") {
            currentFloor++;
        }
        else {
            currentFloor--;
        }
        // change direction if we have reached the top or bottom floor
        if (currentFloor == FLOORS) {
            direction = "down";
        }
        else if (currentFloor == 1) {
            direction = "up";
        }
        // update the destination floor based on passenger requests
        for (int i = 0; i < passengersCount; i++) {
            if (strcmp(direction, "up") == 0) {
                if (elevator.passengers[i].destinationFloor > destinationFloor && elevator.passengers[i].currentFloor >= currentFloor) {
                    destinationFloor = elevator.passengers[i].destinationFloor;
                }
            }
            else {
                if (elevator.passengers[i].destinationFloor < destinationFloor && elevator.passengers[i].currentFloor <= currentFloor) {
                    destinationFloor = elevator.passengers[i].destinationFloor;
                }
            }
        }
    }

    printf("Elevator simulation complete.\n");

    return 0;
}