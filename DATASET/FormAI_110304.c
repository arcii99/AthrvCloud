//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void move_up();
void move_down();
void move_right();
void move_left();
void stop();

int main()
{
    char direction;

    // loop until user inputs "x" to exit
    while (1)
    {
        printf("Enter direction (u, d, l, r) or x to exit: ");
        scanf(" %c", &direction);

        // switch statement to determine direction
        switch (direction)
        {
            case 'u':
                move_up();
                break;
            case 'd':
                move_down();
                break;
            case 'l':
                move_left();
                break;
            case 'r':
                move_right();
                break;
            case 'x':
                stop();
                exit(0); // exit program
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    }

    return 0;
}

// function implementations
void move_up()
{
    printf("Moving up\n");
}

void move_down()
{
    printf("Moving down\n");
}

void move_right()
{
    printf("Moving right\n");
}

void move_left()
{
    printf("Moving left\n");
}

void stop()
{
    printf("Stopping\n");
}