//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CUSTOMERS 5

typedef struct
{
    int floor;
    bool direction; // 1 for upward and 0 for downward
} Request;

typedef struct
{
    int current_floor;
    bool direction;
    Request queue[MAX_FLOORS];
    int queue_count;
} Elevator;

int main()
{
    Elevator elevator = {0, 1, {}, 0};
    Request requests[MAX_CUSTOMERS] = {{2, 1}, {4, 0}, {1, 1}, {9, 0}, {5, 1}};

    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (elevator.queue_count >= MAX_FLOORS)
        {
            printf("Elevator queue is full\n");
            break;
        }

        Request request = requests[i];

        if (request.floor < 1 || request.floor > MAX_FLOORS)
        {
            printf("Invalid floor request\n");
            continue;
        }

        elevator.queue[elevator.queue_count] = request;
        elevator.queue_count++;

        printf("Added request: Floor %d, direction %s\n", request.floor, request.direction ? "up" : "down");
    }

    printf("\nStarting elevator simulation:\n");

    while (elevator.queue_count > 0)
    {
        Request current_request = elevator.queue[0];

        elevator.direction = current_request.floor > elevator.current_floor;

        printf("Elevator current floor: %d\n", elevator.current_floor);
        printf("Elevator current direction: %s\n", elevator.direction ? "up" : "down");
        printf("Next floor request: Floor %d, direction %s\n", current_request.floor, current_request.direction ? "up" : "down");

        while (elevator.current_floor != current_request.floor)
        {
            if (elevator.direction)
            {
                elevator.current_floor++;
            }
            else
            {
                elevator.current_floor--;
            }

            printf("Elevator arrived at floor %d\n", elevator.current_floor);
        }

        elevator.queue[0] = elevator.queue[elevator.queue_count - 1];
        elevator.queue_count--;
    }

    printf("Elevator simulation complete\n");

    return 0;
}