//FormAI DATASET v1.0 Category: Robot movement control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* This program controls the movements of a robot. It has a unique artistic style
that incorporates dance moves and sound effects. */

int main()
{
    int x, y, z;
    char choice, sound;
    printf("*** Welcome to the Robot Movement Control Program! ***\n\n");
    printf("Please enter the starting coordinates of the robot:\n");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    printf("Z: ");
    scanf("%d", &z);
    printf("\n\n");

    do {
        printf("Please select the movement of the robot:\n");
        printf("A. Move Forward\n");
        printf("B. Move Backward\n");
        printf("C. Move Left\n");
        printf("D. Move Right\n");
        printf("E. Jump\n");
        printf("F. Spin Around\n");
        printf("G. Exit\n");
        printf("Your Choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'A':
                printf("Moving Forward...\n");
                x++;
                soundEffect();
                break;
            case 'B':
                printf("Moving Backward...\n");
                x--;
                soundEffect();
                break;
            case 'C':
                printf("Moving Left...\n");
                y--;
                soundEffect();
                break;
            case 'D':
                printf("Moving Right...\n");
                y++;
                soundEffect();
                break;
            case 'E':
                printf("Jumping...\n");
                z++;
                soundEffect();
                break;
            case 'F':
                printf("Spinning Around...\n");
                x++;
                y++;
                z--;
                soundEffect();
                break;
            case 'G':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice. Please try Again.\n");
        }

        printf("Current Coordinates: X=%d, Y=%d, Z=%d\n\n", x, y, z);

    } while(choice != 'G');

    return 0;
}

void soundEffect(){
    printf("Playing Sound Effect... Beep!\n");
}