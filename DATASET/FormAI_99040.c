//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FLOORS 10
#define MAX_PEOPLE 10

struct Person
{
    int currentFloor;
    int destination;
};

struct Elevator
{
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for stationary
};

int getRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void moveElevator(struct Elevator *elevator, int destination)
{
    if(elevator->currentFloor < destination)
    {
        elevator->direction = 1;
        while(elevator->currentFloor != destination)
        {
            printf("\nElevator is at floor %d", elevator->currentFloor);
            elevator->currentFloor++;
        }
    }
    else if(elevator->currentFloor > destination)
    {
        elevator->direction = -1;
        while(elevator->currentFloor != destination)
        {
            printf("\nElevator is at floor %d", elevator->currentFloor);
            elevator->currentFloor--;
        }
    }
    else
    {
        elevator->direction = 0;
    }
}

int main()
{
    srand(time(0));
    struct Person people[MAX_PEOPLE];
    int numPeople = getRandom(1, MAX_PEOPLE);
    printf("Number of people waiting: %d\n", numPeople);

    for(int i = 0; i < numPeople; i++)
    {
        people[i].currentFloor = getRandom(1, MAX_FLOORS);
        people[i].destination = getRandom(1, MAX_FLOORS);
        while(people[i].destination == people[i].currentFloor)
        {
            people[i].destination = getRandom(1, MAX_FLOORS);
        }
        printf("Person %d wants to go from floor %d to floor %d\n", i+1, people[i].currentFloor, people[i].destination);
    }

    struct Elevator elevator = {1, 0};
    printf("\nElevator is at floor %d\n", elevator.currentFloor);

    while(numPeople > 0)
    {
        int numPeopleOnFloor = 0;
        for(int i = 0; i < numPeople; i++)
        {
            if(people[i].currentFloor == elevator.currentFloor)
            {
                numPeopleOnFloor++;
                if(elevator.direction == 0)
                {
                    int destination = people[i].destination;
                    printf("\nElevator door opens at floor %d\n", elevator.currentFloor);
                    moveElevator(&elevator, destination);
                    printf("\nElevator door opens at floor %d\n", elevator.currentFloor);
                    printf("Person %d gets off the elevator\n", i+1);
                    numPeople--;
                    i--;
                }
            }
        }

        if(numPeopleOnFloor > 0)
        {
            printf("\nElevator door opens at floor %d\n", elevator.currentFloor);
            for(int i = 0; i < numPeople; i++)
            {
                if(people[i].currentFloor == elevator.currentFloor)
                {
                    printf("Person %d gets on the elevator\n", i+1);
                    numPeopleOnFloor--;
                    if(numPeopleOnFloor == 0)
                    {
                        break;
                    }
                }
            }
            printf("\nElevator door closes\n");
            if(elevator.direction == 0)
            {
                if(elevator.currentFloor == MAX_FLOORS)
                {
                    elevator.direction = -1;
                }
                else if(elevator.currentFloor == 1)
                {
                    elevator.direction = 1;
                }
                else
                {
                    elevator.direction = getRandom(-1, 1);
                }
            }
        }

        if(elevator.direction == 1)
        {
            printf("\nElevator is going up");
            elevator.currentFloor++;
            if(elevator.currentFloor == MAX_FLOORS)
            {
                printf("\nElevator has reached the top floor");
                elevator.direction = -1;
            }
        }
        else if(elevator.direction == -1)
        {
            printf("\nElevator is going down");
            elevator.currentFloor--;
            if(elevator.currentFloor == 1)
            {
                printf("\nElevator has reached the bottom floor");
                elevator.direction = 1;
            }
        }
    }

    printf("\nAll people have reached their destination");
    printf("\nElevator is at floor %d\n", elevator.currentFloor);

    return 0;
}