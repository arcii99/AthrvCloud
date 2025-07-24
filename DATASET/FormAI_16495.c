//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2
#define CAPACITY 10

typedef struct
{
    int current_floor;
    int target_floor;
    int passengers[CAPACITY];
    int num_passengers;
} elevator_t;

void move_elevator(elevator_t *elevator);
int add_passenger(elevator_t *elevator, int floor);
void remove_passengers(elevator_t *elevator);

int main()
{
    elevator_t elevators[NUM_ELEVATORS];
    int floor_requests[NUM_FLOORS] = {0};
    int num_requests = 0;

    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++)
    {
        elevators[i].current_floor = 0;
        elevators[i].target_floor = -1;
        for (int j = 0; j < CAPACITY; j++)
        {
            elevators[i].passengers[j] = -1;
        }
        elevators[i].num_passengers = 0;
    }

    // Simulation loop
    for (int time = 0; time < 100; time++)
    {
        // Add new passengers
        for (int floor = 0; floor < NUM_FLOORS; floor++)
        {
            if (rand() % 2 == 1)
            {
                num_requests += add_passenger(&elevators[0], floor);
            }
            if (rand() % 2 == 1)
            {
                num_requests += add_passenger(&elevators[1], floor);
            }
        }

        // Update floor requests
        for (int i = 0; i < NUM_ELEVATORS; i++)
        {
            if (elevators[i].target_floor != -1)
            {
                floor_requests[elevators[i].target_floor] = 1;
            }
        }

        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++)
        {
            move_elevator(&elevators[i]);
        }

        // Remove passengers
        for (int i = 0; i < NUM_ELEVATORS; i++)
        {
            remove_passengers(&elevators[i]);
        }

        // Reset floor requests
        for (int i = 0; i < NUM_FLOORS; i++)
        {
            floor_requests[i] = 0;
        }

        printf("Time: %d, Requests: %d\n", time, num_requests);
    }

    return 0;
}

void move_elevator(elevator_t *elevator)
{
    if (elevator->num_passengers == 0 && elevator->target_floor == -1) return;

    if (elevator->target_floor == -1)
    {
        // Choose target floor
        for (int i = 0; i < NUM_FLOORS; i++)
        {
            if (elevator->passengers[i] != -1)
            {
                elevator->target_floor = i;
                break;
            }
        }
    }

    if (elevator->target_floor < elevator->current_floor)
    {
        elevator->current_floor--;
    }
    else if (elevator->target_floor > elevator->current_floor)
    {
        elevator->current_floor++;
    }
}

int add_passenger(elevator_t *elevator, int floor)
{
    if (elevator->num_passengers == CAPACITY) return 0;

    elevator->passengers[floor] = 1;
    elevator->num_passengers++;

    return 1;
}

void remove_passengers(elevator_t *elevator)
{
    if (elevator->num_passengers == 0) return;

    for (int i = 0; i < NUM_FLOORS; i++)
    {
        if (elevator->passengers[i] == 1 && elevator->current_floor == i)
        {
            elevator->passengers[i] = -1;
            elevator->num_passengers--;
        }
    }

    if (elevator->num_passengers == 0 && elevator->target_floor != -1)
    {
        elevator->target_floor = -1;
    }
}