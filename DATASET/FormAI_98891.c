//FormAI DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVEMENTS 100

// function prototype
void move(char direction);

int main()
{
    char movements[MAX_MOVEMENTS];
    int num_movements = 0;
    char ch;

    // read movements from user input
    printf("Enter movements: ");
    while ((ch = getchar()) != '\n')
    {
        if (num_movements < MAX_MOVEMENTS)
        {
            movements[num_movements++] = ch;
        }
    }

    // execute movements
    for (int i = 0; i < num_movements; i++)
    {
        move(movements[i]);
    }

    printf("Done.\n");

    return 0;
}

void move(char direction)
{
    static int x = 0, y = 0;

    switch (direction)
    {
    case 'U':
        y++;
        break;
    case 'D':
        y--;
        break;
    case 'L':
        x--;
        break;
    case 'R':
        x++;
        break;
    default:
        printf("Invalid direction %c\n", direction);
        exit(1);
    }

    printf("Moved %c. New position: (%d, %d) \n", direction, x, y);
}