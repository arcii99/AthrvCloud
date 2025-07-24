//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed = 0, distance = 0;
    char direction;

    printf("Welcome to Remote Control Vehicle Simulation!\n");

    srand(time(NULL));

    while (distance < 100)
    {
        printf("Current speed: %d\n", speed);
        printf("Current distance travelled: %d\n", distance);
        printf("Enter direction (L - left, R - right): ");
        scanf(" %c", &direction);

        if (direction == 'L')
        {
            printf("Veering left...\n");
        }
        else if (direction == 'R')
        {
            printf("Veering right...\n");
        }
        else
        {
            printf("Invalid direction, try again\n");
            continue;
        }

        speed = rand() % 51 + 50;
        printf("Accelerating to speed of %d km/h...\n", speed);

        int distance_travelled = rand() % 6 + 5;
        printf("Travelling for %d km...\n", distance_travelled);

        distance += distance_travelled;
    }

    printf("Congratulations, you have reached your destination!\n");
    printf("Total distance travelled: %d\n", distance);

    return 0;
}