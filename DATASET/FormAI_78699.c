//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Happy Robot Movement Control System!\n");
    printf("Let's get this robot moving and grooving!\n");
    printf("Enter 1 to move forward, 2 to turn left, 3 to turn right or 4 to stop and dance!\n");

    int input = 0;

    while(input != 4) // continue loop until stop and dance command is given
    {
        printf("Enter your next move: ");

        scanf("%d", &input);

        switch(input)
        {
            case 1:
                printf("Robot moves forward!\n");
                break;
            case 2:
                printf("Robot turns left!\n");
                break;
            case 3:
                printf("Robot turns right!\n");
                break;
            case 4:
                printf("Robot stops and starts dancing! Woohoo!\n");
                break;
            default: // if an invalid command is given
                printf("Oops, invalid command given! Try again!\n");
                break;
        }
    }

    printf("Thanks for using the Happy Robot Movement Control System! See you again soon!\n");

    return 0;
}