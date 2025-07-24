//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>

#define MAX_FLOOR 10
#define MAX_PERSONS 5

typedef struct
{
    int currentFloor;
    int destinationFloor;
} Person;

typedef struct
{
    int currentFloor;
    int direction; // 1 for up and -1 for down
    int numberOfPersonsInside;
    Person personsInside[MAX_PERSONS];
} Elevator;

void initializeElevator(Elevator* elevator)
{
    elevator->currentFloor = 1;
    elevator->direction = 1;
    elevator->numberOfPersonsInside = 0;
}

void printElevatorState(Elevator* elevator)
{
    printf("Elevator is currently at floor %d and going %s\n", elevator->currentFloor, elevator->direction == 1 ? "up" : "down");
    printf("Number of persons inside: %d\n", elevator->numberOfPersonsInside);
    printf("Persons inside: ");
    for (int i = 0; i < elevator->numberOfPersonsInside; i++)
    {
        printf("%d->%d ", elevator->personsInside[i].currentFloor, elevator->personsInside[i].destinationFloor);
    }
    printf("\n\n");
}

void addPersonToElevator(Elevator* elevator, Person* person)
{
    elevator->personsInside[elevator->numberOfPersonsInside] = *person;
    elevator->numberOfPersonsInside++;
}

void removePersonFromElevator(Elevator* elevator, int index)
{
    for (int i = index; i < elevator->numberOfPersonsInside-1; i++)
    {
        elevator->personsInside[i] = elevator->personsInside[i+1];
    }
    elevator->numberOfPersonsInside--;
}

void moveElevator(Elevator* elevator)
{
    if (elevator->currentFloor == MAX_FLOOR)
    {
        elevator->direction = -1;
    }
    else if (elevator->currentFloor == 1)
    {
        elevator->direction = 1;
    }

    for (int i = 0; i < elevator->numberOfPersonsInside; i++)
    {
        if (elevator->personsInside[i].destinationFloor == elevator->currentFloor)
        {
            removePersonFromElevator(elevator, i);
            printf("Person exits elevator at floor %d\n\n", elevator->currentFloor);
            break;
        }
    }

    for (int i = 0; i < MAX_PERSONS; i++)
    {
        if (elevator->numberOfPersonsInside == MAX_PERSONS)
        {
            break;
        }

        Person person = {rand() % MAX_FLOOR + 1, rand() % MAX_FLOOR + 1};
        if (person.currentFloor != elevator->currentFloor || person.destinationFloor == person.currentFloor)
        {
            continue;
        }
        else
        {
            addPersonToElevator(elevator, &person);
            printf("Person enters elevator at floor %d\n\n", elevator->currentFloor);
        }
    }

    elevator->currentFloor += elevator->direction;
}

int main()
{
    Elevator elevator;
    initializeElevator(&elevator);

    while (1)
    {
        printElevatorState(&elevator);
        moveElevator(&elevator);
    }

    return 0;
}