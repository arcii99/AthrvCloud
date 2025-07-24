//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>

void turn_left()
{
    printf("Turning left!\n");
}

void turn_right()
{
    printf("Turning right!\n");
}

void move_forward()
{
    printf("Moving forward!\n");
}

void move_backward()
{
    printf("Moving backward!\n");
}

int main()
{
    int movement_input;

    printf("Welcome to the C Robot Movement Control Program!\n");

    while (1)
    {
        printf("Please enter a movement command (1 for Left, 2 for Right, 3 for Forward, 4 for Backward): ");
        scanf("%d", &movement_input);

        switch (movement_input)
        {
            case 1:
                turn_left();
                break;
            case 2:
                turn_right();
                break;
            case 3:
                move_forward();
                break;
            case 4:
                move_backward();
                break;
            default:
                printf("Invalid input. Please try again.\n");
                continue;
        }
    }

    return 0;
}