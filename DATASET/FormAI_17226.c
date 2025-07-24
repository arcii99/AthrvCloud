//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEVATOR_CAPACITY 5 // Maximum number of passengers' elevator can carry at once
#define ELEVATOR_SPEED 2 // The speed of elevator (in seconds) to reach one floor
#define FLOORS 6 // Total number of floors in the building

// Passenger structure to hold information about each passenger and their destination floor
typedef struct {
    int id; // Passenger ID
    int start_floor; // Floor where passenger starts
    int dest_floor; // Floor where passenger wants to go
} Passenger;

// Function prototypes
void delay(int seconds);
int start_floor();
int dest_floor(int start);
void print_elevator(int floor, Passenger elevator[]);
void enter_elevator(Passenger passenger, Passenger elevator[]);
void exit_elevator(int floor, Passenger elevator[]);
void move_elevator(int current_floor, int next_floor);

int main() {
    srand(time(NULL)); // Seed the random number generator

    Passenger passengers[FLOORS][FLOORS]; // Array to hold all the passengers waiting on each floor
    Passenger elevator[ELEVATOR_CAPACITY]; // Array to hold passengers inside the elevator
    int floor = 1; // Starting floor of elevator

    printf("\nWelcome to the Elevator simulator!\n\n");

    while(1) { // Keep the elevator moving forever
        // Check if any passenger is waiting on the current floor
        for(int i = 1; i < FLOORS; i++) {
            if(passengers[floor][i].id != 0) {
                printf("\nA passenger entered on floor %d, heading to floor %d.\n", floor, passengers[floor][i].dest_floor);
                enter_elevator(passengers[floor][i], elevator);
                passengers[floor][i].id = 0; // Remove the passenger from the waiting list
            }
        }

        // Check if any passenger wants to get off the elevator on the current floor
        for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
            if(elevator[i].id != 0 && elevator[i].dest_floor == floor) {
                printf("\nA passenger exited on floor %d.\n", floor);
                exit_elevator(i, elevator);
            }
        }

        // Move elevator to the next floor
        int next_floor = dest_floor(floor);
        move_elevator(floor, next_floor);
        floor = next_floor;

        // Print the current state of the elevator
        print_elevator(floor, elevator);

        // Add new passenger on the floor randomly with a 10% probability every cycle
        if(rand() % 10 == 0) {
            int start = start_floor();
            int dest = dest_floor(start);
            Passenger p = { rand() % 100 + 1, start, dest };
            passengers[start][dest] = p;
            printf("\nA new passenger appeared on floor %d, heading to floor %d.\n", start, dest);
        }

        delay(ELEVATOR_SPEED); // Pause the program for elevator speed (in seconds)
    }

    return 0;
}

/* Function to add a delay of given number of seconds */
void delay(int seconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) < (seconds * CLOCKS_PER_SEC));
}

/* Function to generate a random starting floor for the passenger */
int start_floor() {
    return rand() % (FLOORS-1) + 1;
}

/* Function to generate a random destination floor for the passenger based on the starting floor */
int dest_floor(int start) {
    int dest = start;
    while(dest == start) { // Destination floor should not be same as starting floor
        dest = rand() % (FLOORS-1) + 1;
    }
    return dest;
}

/* Function to print the current state of the elevator */
void print_elevator(int floor, Passenger elevator[]) {
    printf("\n=========================================\n");
    printf("Current floor: %d\n\n", floor);
    for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if(elevator[i].id != 0) {
            printf("Passenger %d, Dest floor: %d\n", elevator[i].id, elevator[i].dest_floor);
        }
    }
    printf("\n=========================================\n");
}

/* Function to add a passenger in the elevator */
void enter_elevator(Passenger passenger, Passenger elevator[]) {
    for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if(elevator[i].id == 0) {
            elevator[i] = passenger;
            return;
        }
    }
}

/* Function to remove a passenger from the elevator */
void exit_elevator(int index, Passenger elevator[]) {
    elevator[index].id = 0;
    elevator[index].start_floor = 0;
    elevator[index].dest_floor = 0;
}

/* Function to move the elevator from current floor to the given floor */
void move_elevator(int current_floor, int next_floor) {
    printf("\nElevator moving from floor %d to floor %d...\n", current_floor, next_floor);
}