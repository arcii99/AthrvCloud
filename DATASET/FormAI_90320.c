//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void init();
void takeoff();
void land();
void ascend(int altitude);
void descend(int altitude);
void move(char direction, int distance);
void rotate(char direction, int angle);
void stop();

int main()
{
    init(); // Initialize the drone

    // User commands to control the drone
    takeoff();
    ascend(20);
    move('F', 30);
    move('R', 10);
    rotate('L', 90);
    descend(10);
    move('B', 20);
    land();

    stop(); // Stop the drone and disconnect

    return 0;
}

void init()
{
    printf("Drone initialized\n");
}

void takeoff()
{
    printf("Taking off\n");
}

void land()
{
    printf("Landing\n");
}

void ascend(int altitude)
{
    printf("Ascending to %d meters\n", altitude);
}

void descend(int altitude)
{
    printf("Descending to %d meters\n", altitude);
}

void move(char direction, int distance)
{
    printf("Moving %d meters %c\n", distance, direction);
}

void rotate(char direction, int angle)
{
    printf("Rotating %d degrees %c\n", angle, direction);
}

void stop()
{
    printf("Drone stopped\n");
}