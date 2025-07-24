//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DRONE_ID 123456
#define ALTITUDE_LIMIT 250

void checkAltitude(int altitude);
void checkConnection();
void takeOff();
void land();
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();
void turnLeft();
void turnRight();

int main()
{
    srand(time(NULL));

    printf("Initializing remote control for drone %d...\n", DRONE_ID);

    checkConnection();

    int altitude = rand() % 501;

    checkAltitude(altitude);

    takeOff();

    printf("Drone %d has taken off at an altitude of %d meters.\n", DRONE_ID, altitude);

    int direction = rand() % 8;

    switch (direction)
    {
        case 0:
            moveForward();
            printf("Drone %d moving forward.\n", DRONE_ID);
            break;

        case 1:
            moveBackward();
            printf("Drone %d moving backward.\n", DRONE_ID);
            break;

        case 2:
            moveLeft();
            printf("Drone %d moving left.\n", DRONE_ID);
            break;

        case 3:
            moveRight();
            printf("Drone %d moving right.\n", DRONE_ID);
            break;

        case 4:
            turnLeft();
            printf("Drone %d turning left.\n", DRONE_ID);
            break;

        case 5:
            turnRight();
            printf("Drone %d turning right.\n", DRONE_ID);
            break;

        default:
            printf("Drone %d hovering in place.\n", DRONE_ID);
            break;
    }

    altitude = rand() % 501;

    checkAltitude(altitude);

    printf("Drone %d has reached an altitude of %d meters.\n", DRONE_ID, altitude);

    land();

    printf("Drone %d has landed.\n", DRONE_ID);

    return 0;
}

void checkAltitude(int altitude)
{
    if (altitude > ALTITUDE_LIMIT)
    {
        printf("Error: Altitude of %d meters exceeds the limit of %d meters.\n", altitude, ALTITUDE_LIMIT);
        exit(1);
    }
}

void checkConnection()
{
    int connection = rand() % 2;

    if (connection == 0)
    {
        printf("Error: Connection lost.\n");
        exit(1);
    }

    printf("Connection established. Preparing for takeoff.\n");
}

void takeOff()
{
    printf("Takeoff initiated.\n");
}

void land()
{
    printf("Landing sequence initiated.\n");
}

void moveForward()
{
    printf("Moving forward.\n");
}

void moveBackward()
{
    printf("Moving backward.\n");
}

void moveLeft()
{
    printf("Moving left.\n");
}

void moveRight()
{
    printf("Moving right.\n");
}

void turnLeft()
{
    printf("Turning left.\n");
}

void turnRight()
{
    printf("Turning right.\n");
}