//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

int main()
{
    int speed = 0;
    bool running = true;

    while (running)
    {
        printf("Current speed: %d\n", speed);
        printf("Enter a command (a, d, w, s, q): ");
        char command = getchar();

        switch (command)
        {
            case 'a':
                speed -= 10;
                if (speed < MIN_SPEED)
                {
                    speed = MIN_SPEED;
                    printf("Cannot go any slower!\n");
                }
                break;
            case 'd':
                speed += 10;
                if (speed > MAX_SPEED)
                {
                    speed = MAX_SPEED;
                    printf("Cannot go any faster!\n");
                }
                break;
            case 'w':
                printf("Going up!\n");
                break;
            case 's':
                printf("Going down!\n");
                break;
            case 'q':
                printf("Stopping...\n");
                running = false;
                break;
            default:
                printf("Invalid command!\n");
        }

        fflush(stdin);
    }

    return 0;
}