//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_FLOORS 5
#define CAPACITY 10

// Delay function to simulate elevator movement
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds) {}
}

// Elevator struct
typedef struct {
    int floor;
    int capacity;
    bool doorsOpen;
    bool goingUp;
    bool goingDown;
    bool isFull;
} Elevator;

// Building struct
typedef struct {
    Elevator elevator;
    int building[NUM_FLOORS][CAPACITY];
    int numPeople;
} Building;

// Function to initialize the building and the elevator
Building initializeBuilding() {
    Building building;
    building.elevator.floor = 1;
    building.elevator.capacity = CAPACITY;
    building.elevator.doorsOpen = false;
    building.elevator.goingUp = false;
    building.elevator.goingDown = false;
    building.elevator.isFull = false;
    building.numPeople = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < CAPACITY; j++) {
            building.building[i][j] = 0;
        }
    }
    return building;
}

// Function to randomly add people to the building
void addPeople(Building *building) {
    int numToAdd = rand() % 6; // Add between 0 and 5 people
    for (int i = 0; i < numToAdd; i++) {
        int floor = rand() % NUM_FLOORS;
        int person = rand() % 100 + 1; // Assign each person a unique ID
        building->building[floor][building->numPeople] = person;
        building->numPeople++;
    }
}

// Function to check if the elevator is full
void checkIfFull(Elevator *elevator) {
    if (elevator->capacity == 0) {
        elevator->isFull = true;
    } else {
        elevator->isFull = false;
    }
}

// Function to check if anyone on the current floor wants to go in the elevator's direction
bool checkIfWaiting(Building building, Elevator elevator) {
    if (elevator.goingUp) {
        for (int i = elevator.floor - 1; i < NUM_FLOORS; i++) {
            for (int j = 0; j < CAPACITY; j++) {
                if (building.building[i][j] != 0) {
                    return true;
                }
            }
        }
    } else if (elevator.goingDown) {
        for (int i = elevator.floor - 2; i >= 0; i--) {
            for (int j = 0; j < CAPACITY; j++) {
                if (building.building[i][j] != 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Function to move the elevator to the next floor
void moveToNextFloor(Elevator *elevator) {
    if (elevator->goingUp) {
        elevator->floor++;
    } else if (elevator->goingDown) {
        elevator->floor--;
    }
}

// Function to check if the elevator is at the top or bottom floor
bool atTopOrBottomFloor(Elevator elevator) {
    if (elevator.floor == 1 && elevator.goingDown) {
        return true;
    } else if (elevator.floor == NUM_FLOORS && elevator.goingUp) {
        return true;
    }
    return false;
}

// Function to open the elevator doors
void openDoors(Elevator *elevator) {
    delay(1); // Wait 1 second to simulate doors opening
    elevator->doorsOpen = true;
}

// Function to close the elevator doors
void closeDoors(Elevator *elevator) {
    delay(1); // Wait 1 second to simulate doors closing
    elevator->doorsOpen = false;
}

// Function to move people into the elevator
void movePeopleIn(Building *building, Elevator *elevator) {
    for (int i = 0; i < CAPACITY; i++) {
        if (elevator->capacity == 0) {
            break;
        }
        if (elevator->goingUp) {
            for (int j = 0; j < building->numPeople; j++) {
                if (building->building[elevator->floor-1][j] != 0) {
                    elevator->capacity--;
                    checkIfFull(elevator);
                    int person = building->building[elevator->floor-1][j];
                    building->building[elevator->floor-1][j] = 0;
                    building->numPeople--;
                    printf("Person %d entered the elevator on floor %d\n", person, elevator->floor);
                }
            }
        } else if (elevator->goingDown) {
            for (int j = 0; j < building->numPeople; j++) {
                if (building->building[elevator->floor-1][j] != 0) {
                    elevator->capacity--;
                    checkIfFull(elevator);
                    int person = building->building[elevator->floor-1][j];
                    building->building[elevator->floor-1][j] = 0;
                    building->numPeople--;
                    printf("Person %d entered the elevator on floor %d\n", person, elevator->floor);
                }
            }
        }
    }
}

// Function to move people out of the elevator
void movePeopleOut(Building *building, Elevator *elevator) {
    for (int i = 0; i < CAPACITY; i++) {
        if (elevator->goingUp) {
            if (building->building[elevator->floor-1][i] == 0) {
                building->building[elevator->floor-1][i] = elevator->capacity + 1;
                elevator->capacity--;
                printf("Person %d exited the elevator on floor %d\n", building->building[elevator->floor-1][i], elevator->floor);
                return;
            }
        } else if (elevator->goingDown) {
            if (building->building[elevator->floor-1][i] == 0) {
                building->building[elevator->floor-1][i] = elevator->capacity + 1;
                elevator->capacity--;
                printf("Person %d exited the elevator on floor %d\n", building->building[elevator->floor-1][i], elevator->floor);
                return;
            }
        }
    }
}

// Function to move the elevator
void moveElevator(Building *building, Elevator *elevator) {
    if (checkIfWaiting(*building, *elevator)) {
        openDoors(elevator);
        movePeopleIn(building, elevator);
        closeDoors(elevator);
        if (elevator->goingUp) {
            if (elevator->floor == NUM_FLOORS) {
                elevator->goingUp = false;
                elevator->goingDown = true;
            } else {
                moveToNextFloor(elevator);
            }
        } else if (elevator->goingDown) {
            if (elevator->floor == 1) {
                elevator->goingUp = true;
                elevator->goingDown = false;
            } else {
                moveToNextFloor(elevator);
            }
        }
        openDoors(elevator);
        movePeopleOut(building, elevator);
        closeDoors(elevator);
    } else {
        if (atTopOrBottomFloor(*elevator)) {
            elevator->goingUp = !elevator->goingUp;
            elevator->goingDown = !elevator->goingDown;
        } else {
            moveToNextFloor(elevator);
        }
    }
}

int main() {
    Building building = initializeBuilding();
    srand(time(NULL)); // Seed random number generator
    while (true) {
        addPeople(&building);
        moveElevator(&building, &building.elevator);
        delay(1); // Wait 1 second between moves to simulate time passing
    }
    return 0;
}