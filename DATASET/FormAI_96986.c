//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

#define FLOORS 10    // number of floors in the building
#define MAX_PASSENGERS 6    // maximum number of passengers allowed in the elevator

// function to move elevator up by one floor
void moveUp(int *current_floor)
{
    (*current_floor)++;
    printf("Elevator moving up. Now at floor %d.\n", *current_floor);
}

// function to move elevator down by one floor
void moveDown(int *current_floor)
{
    (*current_floor)--;
    printf("Elevator moving down. Now at floor %d.\n", *current_floor);
}

// function to load passengers into the elevator
void loadPassengers(int *current_floor, int *num_passengers)
{
    int passengers_to_load = rand() % (MAX_PASSENGERS - (*num_passengers) + 1);
    printf("%d passengers waiting at floor %d.\n", passengers_to_load, *current_floor);
    if(passengers_to_load > 0)
    {
        printf("Loading passengers.\n");
        (*num_passengers) += passengers_to_load;
    }
    printf("Number of passengers in elevator now: %d\n", *num_passengers);
}

// function to unload passengers from the elevator
void unloadPassengers(int *current_floor, int *num_passengers)
{
    int passengers_to_unload = rand() % (*num_passengers + 1);
    printf("%d passengers getting off at floor %d.\n", passengers_to_unload, *current_floor);
    if(passengers_to_unload > 0)
    {
        printf("Unloading passengers.\n");
        (*num_passengers) -= passengers_to_unload;
    }
    printf("Number of passengers in elevator now: %d\n", *num_passengers);
}

// function to simulate elevator operation for one floor
void operateElevator(int *current_floor, int *num_passengers, int direction)
{
    // print current status
    printf("\n");
    printf("Current floor: %d\n", *current_floor);
    if(direction == 1)
    {
        printf("Direction: Up\n");
    }
    else
    {
        printf("Direction: Down\n");
    }
    printf("Number of passengers in elevator: %d\n", *num_passengers);

    // load and/or unload passengers
    unloadPassengers(current_floor, num_passengers);
    loadPassengers(current_floor, num_passengers);

    // move elevator to next floor
    if(*current_floor == FLOORS)
    {
        direction = -1;
    }
    else if(*current_floor == 1)
    {
        direction = 1;
    }
    if(direction == 1)
    {
        moveUp(current_floor);
    }
    else
    {
        moveDown(current_floor);
    }
}

int main()
{
    int current_floor = 1;    // elevator current floor
    int num_passengers = 0;    // number of passengers in the elevator
    int direction = 1;    // 1 for up, -1 for down

    // operate elevator for each floor in sequence
    for(int i = 1; i <= FLOORS; i++)
    {
        operateElevator(&current_floor, &num_passengers, direction);
    }

    return 0;
}