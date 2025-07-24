//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 4

typedef enum {IDLE, UP, DOWN} ElevatorDirection;

typedef struct {
    int floor;
    int passengers;
    ElevatorDirection dir;
} Elevator;

typedef struct {
    bool buttons[FLOORS];
} Floor;

Elevator elevators[ELEVATORS];
Floor floors[FLOORS];

void printElevatorStatus(int index) {
    printf("Elevator %d - Floor %d [", index, elevators[index].floor);
    for(int p = 0; p < elevators[index].passengers; p++) {
        printf("*");
    }
    for(int e = elevators[index].passengers; e < 10; e++) {
        printf(" ");
    }
    printf("] %s\n", elevators[index].dir == IDLE ? "IDLE" : elevators[index].dir == UP ? "UP" : "DOWN");
}

void printBuildingStatus() {
    for(int i = FLOORS-1; i >= 0; i--) {
        printf("F%d\t", i);
        if(floors[i].buttons[0]) printf("^ ");
        else printf("  ");
        if(floors[i].buttons[1]) printf("^ ");
        else printf("  ");
        if(floors[i].buttons[2]) printf("^ ");
        else printf("  ");
        if(floors[i].buttons[3]) printf("^ ");
        else printf("  ");
        printf("\n");
    }
    printf("\n");
    for(int e = 0; e < ELEVATORS; e++) {
        printElevatorStatus(e);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < FLOORS; i++) {
        for(int j = 0; j < ELEVATORS; j++) {
            if(i == rand() % FLOORS) elevators[j].floor = i;
        }
    }
    printf("INITIAL STATUS:\n\n");
    printBuildingStatus();
    for(int s = 0; s < 20; s++) {
        printf("STEP %d:\n\n", s+1);
        for(int e = 0; e < ELEVATORS; e++) {
            if(elevators[e].dir == IDLE) {
                if(elevators[e].passengers == 0) {
                    for(int f = 0; f < FLOORS; f++) {
                        if(floors[f].buttons[elevators[e].floor]) {
                            elevators[e].dir = f > elevators[e].floor ? UP : DOWN;
                            floors[f].buttons[elevators[e].floor] = false;
                            break;
                        }
                    }
                } else {
                    elevators[e].dir = elevators[e].floor < FLOORS-1 ? UP : DOWN;
                }
            } else if(elevators[e].dir == UP) {
                bool stop = false;
                for(int f = elevators[e].floor+1; f < FLOORS; f++) {
                    if(floors[f].buttons[elevators[e].floor] || elevators[e].passengers < FLOORS-elevators[e].floor-1) {
                        elevators[e].floor = f;
                        stop = true;
                        break;
                    }
                }
                if(!stop) {
                    elevators[e].dir = DOWN;
                }
            } else {
                bool stop = false;
                for(int f = elevators[e].floor-1; f >= 0; f--) {
                    if(floors[f].buttons[elevators[e].floor] || elevators[e].passengers > FLOORS-f-1) {
                        elevators[e].floor = f;
                        stop = true;
                        break;
                    }
                }
                if(!stop) {
                    elevators[e].dir = UP;
                }
            }
            for(int f = 0; f < FLOORS; f++) {
                if(f != elevators[e].floor && floors[f].buttons[elevators[e].floor] && elevators[e].passengers < FLOORS-elevators[e].floor-1) {
                    floors[f].buttons[elevators[e].floor] = false;
                    elevators[e].passengers++;
                }
            }
            for(int p = 0; p < elevators[e].passengers; p++) {
                if(rand() % 10 == 0) elevators[e].passengers--;
            }
            printBuildingStatus();
        }
    }
    return 0;
}