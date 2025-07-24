//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FLOORS 10 // Total number of floors
#define ELEVATORS 4 // Total number of elevators

typedef struct
{
    int current_floor; // Current floor of elevator
    int target_floor; // Target floor of elevator
    int in_use; // Flag to indicate whether elevator is in use or not
} elevator_t;

void initialize_elevators(elevator_t* elevators)
{
    for(int i=0; i<ELEVATORS; i++)
    {
        elevators[i].current_floor = 1;
        elevators[i].target_floor = 1;
        elevators[i].in_use = 0;
    }
}

int get_random_floor()
{
    return (rand() % FLOORS) + 1; // Random floor between 1 and FLOORS
}

void print_elevator_status(elevator_t* elevator)
{
    printf("Elevator is on floor %d and going to floor %d\n", elevator->current_floor, elevator->target_floor);
}

void simulate_elevator(elevator_t* elevators, int elevator_id)
{
    if(elevators[elevator_id].in_use == 0)
    {
        elevators[elevator_id].target_floor = get_random_floor();
        elevators[elevator_id].in_use = 1;
        printf("Elevator %d is now in use\n", elevator_id+1);
    }
    else
    {
        if(elevators[elevator_id].current_floor == elevators[elevator_id].target_floor)
        {
            elevators[elevator_id].in_use = 0;
            printf("Elevator %d has reached destination floor %d\n", elevator_id+1, elevators[elevator_id].target_floor);
        }
        else if(elevators[elevator_id].current_floor < elevators[elevator_id].target_floor)
        {
            elevators[elevator_id].current_floor++;
            printf("Elevator %d is going up...\n", elevator_id+1);
        }
        else
        {
            elevators[elevator_id].current_floor--;
            printf("Elevator %d is going down...\n", elevator_id+1);
        }
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator with current time
    elevator_t elevators[ELEVATORS];
    initialize_elevators(elevators);
    int total_simulations = 20;
    for(int i=0; i<total_simulations; i++)
    {
        printf("Simulation %d\n", i+1);
        for(int j=0; j<ELEVATORS; j++)
        {
            simulate_elevator(elevators, j);
            print_elevator_status(&elevators[j]);
        }
        printf("\n");
    }
    return 0;
}