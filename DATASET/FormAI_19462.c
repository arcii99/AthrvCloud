//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * Elevator Simulation
 *
 * This program simulates the movement of an elevator in a building with 10 floors
 * and 1 elevator. The elevator can go up, down, or stay idle. The simulation runs
 * for a total of 100 time steps.
 */

// Number of floors in the building
#define NUM_FLOORS 10

// Speed of elevator movement in floors per second
#define ELEVATOR_SPEED 0.5

// Time required for elevator doors to open/close in seconds
#define DOOR_TIME 2

// Enumeration to represent the state of the elevator
typedef enum {
    ELEV_IDLE,
    ELEV_UP,
    ELEV_DOWN
} ElevState;

// Enumeration to represent the state of a floor button
typedef enum {
    FLOOR_BUTTON_OFF,
    FLOOR_BUTTON_ON
} FloorButtonState;

// Structure to represent a floor button
typedef struct {
    int floor;                  // Floor number
    FloorButtonState state;     // State of the button
} FloorButton;

// Structure to represent an elevator request
typedef struct {
    int floor;                  // Floor number
    ElevState direction;        // Direction of travel
    int time;                   // Time the request was made
} ElevRequest;

// Structure to represent the elevator
typedef struct {
    int currentFloor;           // Current floor
    ElevState state;            // State of the elevator
    bool doorsOpen;             // State of the doors
    ElevRequest request;        // Request in progress
} Elevator;

// Function prototypes
void initializeButtons(FloorButton buttons[NUM_FLOORS]);
ElevRequest makeRequest(FloorButton buttons[NUM_FLOORS], int time);
void displayButtons(FloorButton buttons[NUM_FLOORS]);
void displayElevator(Elevator elev);
void moveElevator(Elevator *elev, int time);
void processRequest(Elevator *elev);
bool isRequestPending(Elevator elev, FloorButton buttons[NUM_FLOORS]);

// Main function
int main() {
    srand(time(NULL));  // Seed random number generator

    FloorButton floorButtons[NUM_FLOORS];   // Array of floor buttons
    initializeButtons(floorButtons);        // Initialize floor buttons

    Elevator elevator = {1, ELEV_IDLE, false};    // Create elevator and initialize to floor 1

    // Simulation loop
    for (int time = 1; time <= 100; time++) {
        printf("Time: %d\n", time);

        // Make a request if no request in progress and there are pending requests
        if (!isRequestPending(elevator, floorButtons)) {
            elevator.request = makeRequest(floorButtons, time);
            printf("Request made from floor %d going ", elevator.request.floor);
            printf("%s\n", elevator.request.direction == ELEV_UP ? "up" : "down");
        }

        displayButtons(floorButtons);   // Display floor buttons
        displayElevator(elevator);      // Display elevator state

        moveElevator(&elevator, time);  // Move the elevator
    }

    return 0;
}

/**
 * initializeButtons - Initializes an array of floor buttons to the OFF state
 */
void initializeButtons(FloorButton buttons[NUM_FLOORS]) {
    for (int floor = 0; floor < NUM_FLOORS; floor++) {
        buttons[floor].floor = floor + 1;
        buttons[floor].state = FLOOR_BUTTON_OFF;
    }
}

/**
 * makeRequest - Generates a random elevator request from a floor button
 */
ElevRequest makeRequest(FloorButton buttons[NUM_FLOORS], int time) {
    int floor;
    ElevState direction;

    // Look for a button that is on and has no associated request
    do {
        floor = rand() % NUM_FLOORS;
        direction = rand() % 2 == 0 ? ELEV_UP : ELEV_DOWN;
    } while (buttons[floor].state == FLOOR_BUTTON_OFF || buttons[floor].state == direction);

    // Set button state to OFF and return request
    buttons[floor].state = FLOOR_BUTTON_OFF;
    return (ElevRequest) {floor + 1, direction, time};
}

/**
 * displayButtons - Displays the state of the floor buttons
 */
void displayButtons(FloorButton buttons[NUM_FLOORS]) {
    printf("Floor Buttons:\n");
    for (int floor = 0; floor < NUM_FLOORS; floor++) {
        printf("%d: %s\n", buttons[floor].floor, buttons[floor].state == FLOOR_BUTTON_ON ? "ON" : "OFF");
    }
    printf("\n");
}

/**
 * displayElevator - Displays the state of the elevator
 */
void displayElevator(Elevator elev) {
    printf("Elevator:\n");
    printf("Floor: %d\n", elev.currentFloor);
    printf("State: ");
    switch (elev.state) {
        case ELEV_IDLE:
            printf("IDLE\n");
            break;
        case ELEV_UP:
            printf("UP\n");
            break;
        case ELEV_DOWN:
            printf("DOWN\n");
            break;
    }
    printf("Doors: %s\n", elev.doorsOpen ? "OPEN" : "CLOSED");
    printf("\n");
}

/**
 * moveElevator - Moves the elevator based on its current state and request
 */
void moveElevator(Elevator *elev, int time) {
    if (elev->state == ELEV_UP) {
        elev->currentFloor += ELEVATOR_SPEED;
        if (elev->currentFloor >= elev->request.floor) {  // Arrival at destination floor
            elev->currentFloor = elev->request.floor;
            elev->state = ELEV_IDLE;
            elev->doorsOpen = true;
            printf("Elevator arrived at floor %d\n", elev->currentFloor);
        }
    } else if (elev->state == ELEV_DOWN) {
        elev->currentFloor -= ELEVATOR_SPEED;
        if (elev->currentFloor <= elev->request.floor) {  // Arrival at destination floor
            elev->currentFloor = elev->request.floor;
            elev->state = ELEV_IDLE;
            elev->doorsOpen = true;
            printf("Elevator arrived at floor %d\n", elev->currentFloor);
        }
    } else if (elev->doorsOpen) {
        if (time - elev->request.time >= DOOR_TIME) {     // Doors are closed after DOOR_TIME seconds
            elev->doorsOpen = false;
            printf("Elevator doors closed\n");
        }
    } else {
        processRequest(elev);   // Process pending request
    }
}

/**
 * processRequest - Processes a pending request by setting the elevator state
 *                  to move up or down depending on the direction of the request
 */
void processRequest(Elevator *elev) {
    if (elev->currentFloor < elev->request.floor) {
        elev->state = ELEV_UP;
        printf("Elevator moving up\n");
    } else if (elev->currentFloor > elev->request.floor) {
        elev->state = ELEV_DOWN;
        printf("Elevator moving down\n");
    } else {
        elev->state = ELEV_IDLE;
        elev->doorsOpen = true;
        printf("Elevator arrived at floor %d\n", elev->currentFloor);
    }
}

/**
 * isRequestPending - Checks if there is a pending request that needs to be processed
 */
bool isRequestPending(Elevator elev, FloorButton buttons[NUM_FLOORS]) {
    if (elev.doorsOpen) {
        return false;
    }

    for (int floor = 0; floor < NUM_FLOORS; floor++) {
        if (buttons[floor].state == FLOOR_BUTTON_ON) {
            return true;
        }
    }

    return false;
}