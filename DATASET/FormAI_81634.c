//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10
#define ELEVATORS 3

int passengers[FLOORS][FLOORS];
int elevatorFloors[ELEVATORS];
int elevatorDirections[ELEVATORS];
bool elevatorOpen[ELEVATORS];
bool upRequests[FLOORS];
bool downRequests[FLOORS];

void initializeElevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        elevatorFloors[i] = 0;
        elevatorDirections[i] = 1;
        elevatorOpen[i] = false;
    }
}

void initializeRequests() {
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < FLOORS; j++) {
            passengers[i][j] = 0;
        }
        upRequests[i] = false;
        downRequests[i] = false;
    }
}

void printElevator(int elevator) {
    printf("Elevator %d: Floor %d, Direction %s, Door %s\n", elevator + 1, elevatorFloors[elevator] + 1, elevatorDirections[elevator] == 1 ? "Up" : "Down", elevatorOpen[elevator] ? "Open" : "Closed");
}

void printRequests() {
    for (int i = FLOORS - 1; i >= 0; i--) {
        printf("%d:", i + 1);
        if (upRequests[i]) {
            printf(" ^");
        } else {
            printf("  ");
        }
        for (int j = 0; j < FLOORS; j++) {
            printf(" %d", passengers[i][j]);
        }
        if (downRequests[i]) {
            printf(" v");
        }
        printf("\n");
    }
}

bool elevatorCanGoUp(int elevator) {
    return elevatorFloors[elevator] < FLOORS - 1 && (!upRequests[elevatorFloors[elevator]] || (!elevatorOpen[elevator] && passengers[elevatorFloors[elevator]][elevatorFloors[elevator] + 1] == 0));
}

bool elevatorCanGoDown(int elevator) {
    return elevatorFloors[elevator] > 0 && (!downRequests[elevatorFloors[elevator]] || (!elevatorOpen[elevator] && passengers[elevatorFloors[elevator] - 1][elevatorFloors[elevator]] == 0));
}

int findElevator(int floor, int direction) {
    int bestElevator = -1;
    int bestScore = 1000000;
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevatorDirections[i] == direction) {
            int score = abs(elevatorFloors[i] - floor);
            if (score < bestScore) {
                bestScore = score;
                bestElevator = i;
            }
        }
    }
    return bestElevator;
}

int findUpRequest() {
    for (int i = 0; i < FLOORS; i++) {
        if (upRequests[i]) {
            return i;
        }
    }
    return -1;
}

int findDownRequest() {
    for (int i = FLOORS - 1; i >= 0; i--) {
        if (downRequests[i]) {
            return i;
        }
    }
    return -1;
}

void embark(int elevator, int floor) {
    elevatorOpen[elevator] = true;
    passengers[floor][elevatorFloors[elevator]] = 0;
    printf("Passenger embarking on elevator %d at floor %d\n", elevator + 1, floor + 1);
}

void disembark(int elevator, int floor) {
    elevatorOpen[elevator] = true;
    passengers[floor][elevatorFloors[elevator]] = 0;
    printf("Passenger disembarking on elevator %d at floor %d\n", elevator + 1, floor + 1);
}

void moveElevator(int elevator) {
    if (elevatorDirections[elevator] == 1) {
        elevatorFloors[elevator]++;
    } else {
        elevatorFloors[elevator]--;
    }
}

void elevatorGoUp(int elevator) {
    elevatorDirections[elevator] = 1;
    moveElevator(elevator);
}

void elevatorGoDown(int elevator) {
    elevatorDirections[elevator] = -1;
    moveElevator(elevator);
}

void elevatorStop(int elevator) {
    elevatorOpen[elevator] = !elevatorOpen[elevator];
    if (elevatorOpen[elevator]) {
        int floor = elevatorFloors[elevator];
        if (elevatorDirections[elevator] == 1) {
            if (upRequests[floor]) {
                embark(elevator, floor);
            } else {
                elevatorOpen[elevator] = false;
            }
        } else {
            if (downRequests[floor]) {
                embark(elevator, floor);
            } else {
                elevatorOpen[elevator] = false;
            }
        }
    } else {
        if (elevatorDirections[elevator] == 1) {
            if (downRequests[elevatorFloors[elevator]]) {
                disembark(elevator, elevatorFloors[elevator]);
            } else if (passengers[elevatorFloors[elevator]][elevatorFloors[elevator] + 1] != 0) {
                disembark(elevator, elevatorFloors[elevator]);
            }
        } else {
            if (upRequests[elevatorFloors[elevator]]) {
                disembark(elevator, elevatorFloors[elevator]);
            } else if (passengers[elevatorFloors[elevator] - 1][elevatorFloors[elevator]] != 0) {
                disembark(elevator, elevatorFloors[elevator]);
            }
        }
    }
}

void updateElevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevatorOpen[i]) {
            elevatorStop(i);
        } else {
            if (elevatorDirections[i] == 1 && !elevatorCanGoUp(i)) {
                elevatorDirections[i] = -1;
            } else if (elevatorDirections[i] == -1 && !elevatorCanGoDown(i)) {
                elevatorDirections[i] = 1;
            } else if (elevatorCanGoUp(i)) {
                elevatorGoUp(i);
            } else if (elevatorCanGoDown(i)) {
                elevatorGoDown(i);
            } else {
                elevatorStop(i);
            }
        }
    }
}

void updateRequests() {
    for (int floor = 0; floor < FLOORS; floor++) {
        if (upRequests[floor]) {
            int elevator = findElevator(floor, 1);
            if (elevator != -1 && !elevatorOpen[elevator] && passengers[floor][floor + 1] == 0) {
                elevatorOpen[elevator] = true;
            }
        }
        if (downRequests[floor]) {
            int elevator = findElevator(floor, -1);
            if (elevator != -1 && !elevatorOpen[elevator] && passengers[floor - 1][floor] == 0) {
                elevatorOpen[elevator] = true;
            }
        }
    }
}

void simulate() {
    initializeElevators();
    initializeRequests();
    while (true) {
        printRequests();
        for (int i = 0; i < ELEVATORS; i++) {
            printElevator(i);
        }
        updateElevators();
        updateRequests();
    }
}

int main() {
    upRequests[0] = true;
    upRequests[3] = true;
    downRequests[6] = true;
    downRequests[9] = true;
    passengers[0][1] = 3;
    passengers[9][7] = 2;
    simulate();
    return 0;
}