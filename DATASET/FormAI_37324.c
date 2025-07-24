//FormAI DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randNum(int min, int max)
{
    int num = (rand() % (max-min+1)) + min;
    return num;
}

int main()
{
    int x = 0, y = 0, z = 0;
    srand(time(NULL)); // seed for random number generator

    printf("Initializing Robot\n");
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Moving Robot Forward\n");
    x += randNum(1, 10);
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Turning Right\n");
    z += 90;
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Moving Robot Forward\n");
    y += randNum(1, 10);
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Turning Left\n");
    z -= 90;
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Moving Robot Forward\n");
    x -= randNum(1, 10);
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Turning Right\n");
    z += 90;
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Moving Robot Forward\n");
    y -= randNum(1, 10);
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Turning Left\n");
    z -= 90;
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    printf("Returning to Initial Location\n");
    x = 0;
    y = 0;
    z = 0;
    printf("Current Location: (%d, %d, %d)\n", x, y, z);

    return 0;
}