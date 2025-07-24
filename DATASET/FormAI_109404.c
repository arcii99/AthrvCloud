//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOOR 10
#define MAX_ELEVATOR 3
#define MAX_PERSON 20
#define SPEED 1

//Structs
typedef struct Person {
    int id;
    int currentFloor;
    int destinationFloor;
} Person;

typedef struct Elevator {
    int id;
    int currentFloor;
    int destinationFloor;
    bool isMoving;
    bool isDoorOpen;
    int doorOpenTime;
    int doorCloseTime;
    int direction;
    int numPeople;
    Person people[MAX_PERSON];
} Elevator;

//Functions
int getFloor(Elevator* elevator) {
    if(elevator->currentFloor > elevator->destinationFloor) {
        return elevator->currentFloor - SPEED;
    } else if (elevator->currentFloor < elevator->destinationFloor) {
        return elevator->currentFloor + SPEED;
    } else {
        return elevator->currentFloor;
    }
}

bool isDestination(Elevator* elevator) {
    return elevator->currentFloor == elevator->destinationFloor;
}

void openDoor(Elevator* elevator) {
    elevator->isDoorOpen = true;
    elevator->doorOpenTime = (rand() % 3) + 1;
    elevator->numPeople = 0;
}

void closeDoor(Elevator* elevator) {
    elevator->isDoorOpen = false;
    elevator->doorCloseTime = (rand() % 3) + 1;
}

void addPerson(Elevator* elevator, Person person) {
    if(elevator->numPeople == MAX_PERSON) {
        printf("Elevator %d is full\n", elevator->id);
        return;
    }
    elevator->people[elevator->numPeople++] = person;
}

void miniSleep(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

//Main Function
int main() {
    srand(time(NULL));
    Elevator elevators[MAX_ELEVATOR];
    int numPeopleOnFloors[MAX_FLOOR] = {0};
    int numPeopleInQueue = 0;
    int numPeopleProcessed = 0;

    //Initialize elevators
    for(int i = 0; i < MAX_ELEVATOR; i++) {
        elevators[i].id = i + 1;
        elevators[i].currentFloor = 1;
        elevators[i].destinationFloor = 1;
        elevators[i].isMoving = false;
        elevators[i].isDoorOpen = false;
        elevators[i].doorOpenTime = 0;
        elevators[i].doorCloseTime = 0;
        elevators[i].direction = 1;
        elevators[i].numPeople = 0;
    }

    //Simulate elevator system
    while(numPeopleProcessed < MAX_PERSON) {
        //Generate new people on floor
        for(int i = 0; i < MAX_FLOOR; i++) {
            int newPeople = rand() % 2;
            numPeopleOnFloors[i] += newPeople;
            numPeopleInQueue += newPeople;
        }

        //Move Elevators
        for(int i = 0; i < MAX_ELEVATOR; i++) {
            if(!elevators[i].isDoorOpen) {
                if(isDestination(&elevators[i])) {
                    openDoor(&elevators[i]);
                } else {
                    elevators[i].currentFloor = getFloor(&elevators[i]);
                }
            } else if (elevators[i].doorOpenTime > 0) { //Keep Door Open
                elevators[i].doorOpenTime--;
            } else if (elevators[i].doorCloseTime > 0) { //Close Door
                closeDoor(&elevators[i]);
            } else { //Add people inside elevator
                int remainingSpace = MAX_PERSON - elevators[i].numPeople;
                for(int j = 0; j < remainingSpace; j++) {
                    //Add people to elevator when destination == current floor
                    if(numPeopleOnFloors[elevators[i].currentFloor - 1] > 0 &&
                        elevators[i].destinationFloor == elevators[i].currentFloor) {
                        Person newPerson = {
                            .id = numPeopleProcessed + 1,
                            .currentFloor = elevators[i].currentFloor,
                            .destinationFloor = (rand() % (MAX_FLOOR - 1)) + 1
                        };
                        addPerson(&elevators[i], newPerson);
                        numPeopleOnFloors[elevators[i].currentFloor - 1]--;
                        numPeopleProcessed++;
                        numPeopleInQueue--;
                    }
                }

                elevators[i].destinationFloor = elevators[i].people[elevators[i].numPeople - 1].destinationFloor;
            }
        }

        //Print Current Status
        printf("Num People in Queue: %d\n", numPeopleInQueue);
        for(int i = 0; i < MAX_ELEVATOR; i++) {
            printf("Elevator %d (Floor %d): ", elevators[i].id, elevators[i].currentFloor);
            if(elevators[i].isMoving) {
                printf("Moving %d\n", elevators[i].direction);
            } else if (elevators[i].isDoorOpen) {
                printf("Door Open\n");
            } else {
                printf("Idle\n");
            }
        }

        miniSleep(SPEED);
    }

    printf("Simulation Complete\n");

    return 0;
}