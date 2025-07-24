//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHIP_SPEED 200

int destinationX, destinationY;
int shipX, shipY;

void setDestination()
{
    srand(time(NULL));
    destinationX = rand() % 1000;
    destinationY = rand() % 1000;
}

void moveShip()
{
    if (shipX < destinationX)
    {
        shipX += SHIP_SPEED;
    }
    else if (shipX > destinationX)
    {
        shipX -= SHIP_SPEED;
    }

    if (shipY < destinationY)
    {
        shipY += SHIP_SPEED;
    }
    else if (shipY > destinationY)
    {
        shipY -= SHIP_SPEED;
    }
}

int main()
{
    setDestination();

    while (1)
    {
        moveShip();

        printf("Ship position: (%d, %d)\n", shipX, shipY);

        if (shipX == destinationX && shipY == destinationY)
        {
            printf("We have arrived at our destination!\n");
            break;
        }
    }

    return 0;
}