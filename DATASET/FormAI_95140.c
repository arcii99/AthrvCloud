//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Constants */
#define FLOORS 10
#define ELEVATORS 3

/* Structs */
typedef struct {
    int floor;
    bool isAvailable;
} Elevator;

/* Function Prototypes */
void printState();
void checkFloorRequests(int);
void checkElevatorRequests(int);
void assignRequest(int, int);
void updateElevators();
void drawElevator(int);

/* Global Variables */
int floorRequests[FLOORS];
Elevator elevators[ELEVATORS];

int main() {
    // Set initial state
    for (int i = 0; i < FLOORS; i++) {
        floorRequests[i] = 0;
    }
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].isAvailable = true;
    }
    
    // Main loop
    while (true) {
        system("clear"); // Clear console
        printState(); // Print current state
        
        // Check floor requests
        for (int i = FLOORS - 1; i >= 0; i--) {
            checkFloorRequests(i);
        }
        
        // Check elevator requests
        for (int i = 0; i < ELEVATORS; i++) {
            checkElevatorRequests(i);
        }
        
        // Update elevators
        updateElevators();
        
        // Pause for 500ms
        usleep(500000);
    }
    
    return 0;
}

// Prints the current state of the simulation
void printState() {
    printf("Floor Requests: ");
    for (int i = FLOORS - 1; i >= 0; i--) {
        printf("%d ", floorRequests[i]);
    }
    printf("\n\n");
    
    for (int i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d: ", i);
        drawElevator(elevators[i].floor);
        printf("\n");
    }
}

// Checks for floor requests on the specified floor
void checkFloorRequests(int floor) {
    if (floorRequests[floor] > 0) {
        assignRequest(floor, floor);
        floorRequests[floor] = 0;
    }
}

// Checks for elevator requests on the specified elevator
void checkElevatorRequests(int elevator) {
    if (elevators[elevator].isAvailable == true) {
        int closestFloor = -1;
        int closestDist = FLOORS;
        
        for (int i = 0; i < FLOORS; i++) {
            if (floorRequests[i] > 0) {
                int dist = abs(i - elevators[elevator].floor);
                
                if (dist < closestDist) {
                    closestFloor = i;
                    closestDist = dist;
                }
            }
        }
        
        if (closestFloor != -1) {
            assignRequest(elevator, closestFloor);
        }
    }
}

// Assigns a request to the specified elevator
void assignRequest(int elevator, int floor) {
    elevators[elevator].isAvailable = false;
    floorRequests[floor]--;
    
    if (floor < elevators[elevator].floor) {
        elevators[elevator].floor--;
    } else if (floor > elevators[elevator].floor) {
        elevators[elevator].floor++;
    }
}

// Updates the state of all elevators
void updateElevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevators[i].isAvailable == false) {
            if (elevators[i].floor == 0 || elevators[i].floor == FLOORS - 1) {
                elevators[i].isAvailable = true;
            }
        }
    }
}

// Draws the specified elevator on the screen
void drawElevator(int floor) {
    for (int i = FLOORS - 1; i >= 0; i--) {
        if (i == floor) {
            printf("[]");
        } else {
            printf("  ");
        }
    }
}