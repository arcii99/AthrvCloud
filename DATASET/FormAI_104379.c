//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10
#define PPL 5

int currFloor = 0;
int maxWeight = 500;

int floorRequests[FLOORS] = {0};
int totalRequests = 0;
int currDirection = 1; //1 for up, -1 for down

struct Person {
    int weight;
    int fromFloor;
    int toFloor;
} people[PPL];

void addPerson(int weight, int fromFloor, int toFloor) {
    if (totalRequests >= PPL) return;
    people[totalRequests].weight = weight;
    people[totalRequests].fromFloor = fromFloor;
    people[totalRequests].toFloor = toFloor;
    floorRequests[fromFloor]++;
    totalRequests++;
}

void unloadPeople() {
    for (int i = 0; i < totalRequests; i++) {
        if (people[i].toFloor == currFloor) {
            printf("Person with weight %d has been unloaded at floor %d\n", people[i].weight, currFloor);
            floorRequests[currFloor]--;
            totalRequests--;
            people[i] = people[totalRequests];
        }
    }
}

void loadPeople() {
    for (int i = 0; i < totalRequests; i++) {
        if (people[i].fromFloor == currFloor && maxWeight - people[i].weight >= 0) {
            printf("Person with weight %d has been added to elevator on floor %d\n", people[i].weight, currFloor);
            maxWeight -= people[i].weight;
            floorRequests[currFloor]--;
            people[i] = people[totalRequests - 1];
            totalRequests--;
            i--;
        }
    }
}

void moveElevator() {
    if (currFloor == 0 || currFloor == FLOORS - 1) currDirection *= -1;
    currFloor += currDirection;
}

void printFloorRequests() {
    printf("Floor requests:\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: %d\n", i, floorRequests[i]);
    }
}

int main() {
    addPerson(150, 0, 4);
    addPerson(200, 1, 8);
    addPerson(100, 3, 1);
    addPerson(50, 6, 9);

    while (totalRequests > 0) {
        printf("Current floor: %d\n", currFloor);
        unloadPeople();
        loadPeople();
        moveElevator();
        printFloorRequests();
    }

    printf("All people have been transported successfully!\n");

    return 0;
}