//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// constants
#define MAX_FLOORS 10
#define MAX_PASSENGERS 10
#define MAX_ELEVATOR_CAPACITY 6

// data structures
typedef struct {
    int current_floor;
    bool direction_up;
    bool active;
    int passengers[MAX_ELEVATOR_CAPACITY];
    int num_passengers;
} Elevator;

typedef struct {
    int id;
    int start_floor;
    int dest_floor;
    bool in_elevator;
} Passenger;

// function prototypes
void print_elevator(Elevator e);
void print_passenger(Passenger p);
int get_random_int(int min, int max);

int main() {
    srand(42); // set the seed for random number generation
    Elevator elevator = { .current_floor = 0, .direction_up = true }; // initialize elevator to start at floor 0 going up
    Passenger passengers[MAX_PASSENGERS];
    
    // generate passengers
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger p = { .id = i, .start_floor = get_random_int(0, MAX_FLOORS-1), .dest_floor = get_random_int(0, MAX_FLOORS-1), .in_elevator = false };
        passengers[i] = p;
    }

    // simulation loop
    int iterations = 0;
    while (true) {
        printf("Iteration %d\n", iterations);
        print_elevator(elevator);

        // check if any passengers want to board
        for (int i = 0; i < MAX_PASSENGERS; i++) {
            if (passengers[i].in_elevator == false && passengers[i].start_floor == elevator.current_floor && 
                elevator.num_passengers < MAX_ELEVATOR_CAPACITY) {

                printf("Passenger %d boarding elevator from floor %d to floor %d\n", passengers[i].id, passengers[i].start_floor, passengers[i].dest_floor);
                elevator.passengers[elevator.num_passengers] = passengers[i].id;
                elevator.num_passengers++;
                passengers[i].in_elevator = true;
            }
        }

        // check if any passengers want to exit
        for (int i = 0; i < elevator.num_passengers; i++) {
            if (passengers[elevator.passengers[i]].dest_floor == elevator.current_floor) {
                printf("Passenger %d exiting elevator at floor %d\n", passengers[elevator.passengers[i]].id, elevator.current_floor);
                elevator.num_passengers--;

                // shift passengers over if there are empty seats
                if (i < elevator.num_passengers) {
                    for (int j = i; j < elevator.num_passengers; j++) {
                        elevator.passengers[j] = elevator.passengers[j+1];
                    }
                }
            }
        }

        // move elevator to a new floor
        if (elevator.direction_up) {
            elevator.current_floor++;
            if (elevator.current_floor == MAX_FLOORS-1) {
                elevator.direction_up = false;
            }
        } else {
            elevator.current_floor--;
            if (elevator.current_floor == 0) {
                elevator.direction_up = true;
            }
        }

        // check if simulation is over
        bool simulation_over = true;
        for (int i = 0; i < MAX_PASSENGERS; i++) {
            if (passengers[i].in_elevator == false || passengers[i].dest_floor != elevator.current_floor) {
                simulation_over = false;
            }
        }
        if (simulation_over) {
            break;
        }

        // delay between iterations to make simulation more realistic
        putchar('\n');
        system("sleep 1");
        iterations++;
    }

    printf("Simulation complete in %d iterations!\n", iterations);
    return 0;
}

void print_elevator(Elevator e) {
    printf("Elevator at floor %d, going %s, with %d passengers: ", e.current_floor, e.direction_up ? "up" : "down", e.num_passengers);
    for (int i = 0; i < e.num_passengers; i++) {
        printf("%d ", e.passengers[i]);
    }
    putchar('\n');
}

void print_passenger(Passenger p) {
    printf("Passenger %d: start_floor=%d, dest_floor=%d, in_elevator=%d\n", p.id, p.start_floor, p.dest_floor, p.in_elevator);
}

int get_random_int(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}