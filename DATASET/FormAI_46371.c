//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int command;
    int x = 0, y = 0;

    printf("Welcome to the C Robot movement control program! Let's get started.\n");

    while(1)
    {
        printf("Enter your move command:\n");
        printf("1 - Move forward\n2 - Move backward\n3 - Move left\n4 - Move right\n5 - Quit\n");
        scanf("%d", &command);

        switch(command)
        {
            case 1:
                printf("Robot moves forward\n");
                y += 1;
                break;
            case 2:
                printf("Robot moves backward\n");
                y -= 1;
                break;
            case 3:
                printf("Robot moves left\n");
                x -= 1;
                break;
            case 4:
                printf("Robot moves right\n");
                x += 1;
                break;
            case 5:
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid command\n");
        }

        printf("Robot is at position (%d, %d)\n", x, y);
    }
    return 0;
}