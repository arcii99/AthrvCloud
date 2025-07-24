//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct Elevator {
    int id;
    int floor;
    int dest;
    bool inService;
    bool doorsOpen;
} Elevator;

Elevator elevators[ELEVATORS];
int requests[FLOORS];

void printStatus() {
    system("clear");
    printf("Elevator\tFloor\tDestination\n");
    for (int i = 0; i < ELEVATORS; i++) {
        printf("%d\t\t%d\t%d\n", elevators[i].id, elevators[i].floor, elevators[i].dest);
    }
    printf("\nRequests:\n");
    for (int i = 0; i < FLOORS; i++) {
        if (requests[i]) printf("Floor %d\n", i+1);
    }
}

void moveElevator(int id) {
    if (elevators[id].dest > elevators[id].floor) {
        elevators[id].floor++;
        if (elevators[id].floor == elevators[id].dest) {
            elevators[id].doorsOpen = true;
            printf("Elevator %d doors opening on floor %d.\n", elevators[id].id, elevators[id].floor);
        }
        else {
            printf("Elevator %d moving to floor %d.\n", elevators[id].id, elevators[id].floor);
        }
    }
    else if (elevators[id].dest < elevators[id].floor) {
        elevators[id].floor--;
        if (elevators[id].floor == elevators[id].dest) {
            elevators[id].doorsOpen = true;
            printf("Elevator %d doors opening on floor %d.\n", elevators[id].id, elevators[id].floor);
        }
        else {
            printf("Elevator %d moving to floor %d.\n", elevators[id].id, elevators[id].floor);
        }
    }
}

int main() {
    // initialize elevators
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].floor = 1;
        elevators[i].dest = 1;
        elevators[i].inService = true;
        elevators[i].doorsOpen = false;
    }

    // initialize requests
    for (int i = 0; i < FLOORS; i++) {
        requests[i] = rand() % 2;
    }

    // main loop
    bool running = true;
    while (running) {
        // move elevators
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevators[i].inService && !elevators[i].doorsOpen) {
                if (elevators[i].floor == elevators[i].dest) {
                    // check if there are any requests on this floor
                    if (requests[elevators[i].floor-1]) {
                        elevators[i].doorsOpen = true;
                        printf("Elevator %d doors opening on floor %d.\n", elevators[i].id, elevators[i].floor);
                    }
                    else {
                        // select new destination
                        int dest = rand() % FLOORS + 1;
                        while (dest == elevators[i].floor) {
                            dest = rand() % FLOORS + 1;
                        }
                        elevators[i].dest = dest;
                    }
                }
                else {
                    moveElevator(i);
                }
            }
        }

        // handle requests
        for (int i = 0; i < FLOORS; i++) {
            if (requests[i]) {
                bool serviced = false;
                for (int j = 0; j < ELEVATORS && !serviced; j++) {
                    if (elevators[j].inService && elevators[j].floor == i+1 && elevators[j].doorsOpen) {
                        printf("Passenger picked up on floor %d by elevator %d.\n", i+1, elevators[j].id);
                        requests[i] = 0;
                        elevators[j].dest = rand() % FLOORS + 1;
                        serviced = true;
                    }
                }
                if (!serviced) {
                    int closest = 0;
                    int closestDist = abs(i+1 - elevators[0].floor);
                    for (int j = 1; j < ELEVATORS; j++) {
                        if (elevators[j].inService && abs(i+1 - elevators[j].floor) < closestDist) {
                            closest = j;
                            closestDist = abs(i+1 - elevators[j].floor);
                        }
                    }
                    elevators[closest].dest = i+1;
                    printf("Elevator %d dispatched to floor %d.\n", elevators[closest].id, i+1);
                }
            }
        }

        // check if all requests have been handled and all elevators are idle
        bool idle = true;
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevators[i].inService && elevators[i].dest != elevators[i].floor) {
                idle = false;
                break;
            }
        }
        if (idle) {
            bool allRequestsHandled = true;
            for (int i = 0; i < FLOORS; i++) {
                if (requests[i]) {
                    allRequestsHandled = false;
                    break;
                }
            }
            if (allRequestsHandled) {
                running = false;
            }
        }

        printStatus();
        printf("------------------------\n");
        usleep(500000);
    }

    printf("All requests handled. Program exiting.\n");
    return 0;
}