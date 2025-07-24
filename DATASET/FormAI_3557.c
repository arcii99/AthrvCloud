//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define MAX_FLOORS 10
#define MAX_PASSENGERS 5
#define MIN_FLOOR 1
#define MAX_ELEVATOR_CAPACITY 10
#define ELEVATOR_SPEED 1 // in floors per second

// Functions declarations
void move_elevator(int *current_floor, int target_floor);
void open_doors();
void close_doors();
void enter_elevator();
void exit_elevator();
void display_state(int current_floor, int destination_floor, int num_passengers);
void simulate_elevator();

int main()
{
    simulate_elevator();
    return 0;
}

void simulate_elevator()
{
    srand(time(0)); // seed random number generator

    int current_floor = 1;
    int destination_floor = current_floor;
    int num_passengers = 0;

    printf("Elevator Simulation starting...\n");

    // Main loop
    while (true)
    {
        // Elevator is at a floor and has no destination
        if (current_floor == destination_floor)
        {
            // Choose a random floor as destination or stay idle
            int random_num = rand() % 3; // 1/3 chance of staying idle
            if (random_num == 0)
            {
                // Choose a random floor as destination
                destination_floor = rand() % MAX_FLOORS + 1;
                printf("Elevator called to floor %d\n", destination_floor);
            }
            else
            {
                printf("Elevator is idle\n");
            }
        }
        // Elevator has a destination
        else
        {
            // Check if we are at the destination
            if (current_floor == destination_floor)
            {
                printf("Elevator has arrived at floor %d\n", current_floor);
                open_doors();
                // Let passengers exit elevator
                while (num_passengers > 0 && current_floor == destination_floor)
                {
                    exit_elevator(&num_passengers);
                }
                // Let new passengers enter elevator
                while (num_passengers < MAX_ELEVATOR_CAPACITY && current_floor == destination_floor)
                {
                    enter_elevator(&num_passengers);
                }
                // Close doors and go to new destination
                close_doors();
                destination_floor = rand() % MAX_FLOORS + 1;
            }
            // Move elevator towards destination
            else
            {
                move_elevator(&current_floor, destination_floor);
            }
        }
        // Display elevator state
        display_state(current_floor, destination_floor, num_passengers);
        // Sleep for 1 second to simulate time
        printf("\n\n");
        sleep(1);
    }
}

void move_elevator(int *current_floor, int target_floor)
{
    int direction = (*current_floor < target_floor)? 1: -1;
    printf("Elevator is moving %d to floor %d\n", direction, *current_floor+direction);
    *current_floor += direction;
}

void open_doors()
{
    printf("Elevator doors opening...\n");
}

void close_doors()
{
    printf("Elevator doors closing...\n");
}

void enter_elevator(int *num_passengers)
{
    if (*num_passengers < MAX_ELEVATOR_CAPACITY)
    {
        printf("New passenger has entered the elevator\n");
        (*num_passengers)++;
    }
    else
    {
        printf("Elevator is full, cannot let more passengers in\n");
    }
}

void exit_elevator(int *num_passengers)
{
    if (*num_passengers > 0)
    {
        printf("Passenger has exited the elevator\n");
        (*num_passengers)--;
    }
    else
    {
        printf("Elevator is empty, no passengers to exit\n");
    }
}

void display_state(int current_floor, int destination_floor, int num_passengers)
{
    printf("Elevator is at floor %d, heading to floor %d. %d passengers inside.\n", current_floor, destination_floor, num_passengers);
}