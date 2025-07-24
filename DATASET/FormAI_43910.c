//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

typedef enum { NS, EW } Direction;

typedef struct {
    Direction direction;
    int signalTime;
    int currentColor;
    int timer;
} Street;

typedef struct {
    Street nsStreet;
    Street ewStreet;
    int isEmergency;
} Intersection;

void initStreet(Street *streetPtr, Direction direction, int signalTime)
{
    streetPtr->direction = direction;
    streetPtr->signalTime = signalTime;
    streetPtr->currentColor = GREEN;
    streetPtr->timer = signalTime;
}

void initIntersection(Intersection *intersectionPtr, int nsSignalTime, int ewSignalTime)
{
    initStreet(&(intersectionPtr->nsStreet), NS, nsSignalTime);
    initStreet(&(intersectionPtr->ewStreet), EW, ewSignalTime);
    intersectionPtr->isEmergency = 0;
}

int shouldChangeColor(Street *streetPtr)
{
    return streetPtr->timer == 0;
}

void changeToNextColor(Street *streetPtr)
{
    streetPtr->currentColor++;
    if (streetPtr->currentColor > GREEN)
    {
        streetPtr->currentColor = RED;
    }
    streetPtr->timer = streetPtr->signalTime;
}

void updateStreetTimer(Street *streetPtr)
{
    if (shouldChangeColor(streetPtr))
    {
        changeToNextColor(streetPtr);
    }
    else
    {
        streetPtr->timer--;
    }
}

Direction getNextDirection(Intersection *intersectionPtr)
{
    if (intersectionPtr->isEmergency)
    {
        return intersectionPtr->nsStreet.direction;
    }
    else
    {
        if (shouldChangeColor(&(intersectionPtr->nsStreet)) || intersectionPtr->ewStreet.currentColor == GREEN)
        {
            return NS;
        }
        else
        {
            return EW;
        }
    }
}

void updateIntersection(Intersection *intersectionPtr)
{
    Direction nextDirection = getNextDirection(intersectionPtr);
    if (nextDirection == NS)
    {
        updateStreetTimer(&(intersectionPtr->nsStreet));
        intersectionPtr->ewStreet.timer--;
    }
    else
    {
        updateStreetTimer(&(intersectionPtr->ewStreet));
        intersectionPtr->nsStreet.timer--;
    }
}

void printIntersection(Intersection *intersectionPtr)
{
    printf("\n+-------+");
    printf("\n|  NS %c  |", intersectionPtr->nsStreet.currentColor == RED ? 'R' : (intersectionPtr->nsStreet.currentColor == YELLOW ? 'Y' : 'G'));
    printf("\n|    |    |");
    printf("\n|    |    |");
    printf("\n|  EW %c  |", intersectionPtr->ewStreet.currentColor == RED ? 'R' : (intersectionPtr->ewStreet.currentColor == YELLOW ? 'Y' : 'G'));
    printf("\n+-------+\n");
}

int main()
{
    Intersection intersection;
    initIntersection(&intersection, 10, 15);

    int i;
    for (i = 0; i < 100; i++)
    {
        updateIntersection(&intersection);
        printIntersection(&intersection);
        if (i == 20)
        {
            intersection.isEmergency = 1;
        }
    }

    return 0;
}