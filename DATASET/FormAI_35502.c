//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 100

int main()
{
    printf("Welcome to Robot Movement Control Program!\n\n");

    char input[MAX_STRING_LENGTH];
    int x = 0, y = 0;
    char facing = 'N';

    while(1)
    {
        printf("Enter a command (F)orward, (L)eft, (R)ight, or (Q)uit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if(strcmp(input, "F") == 0 || strcmp(input, "f") == 0)
        {
            if(facing == 'N')
            {
                y++;
            }
            else if(facing == 'S')
            {
                y--;
            }
            else if(facing == 'E')
            {
                x++;
            }
            else if(facing == 'W')
            {
                x--;
            }
            else
            {
                printf("Error: Invalid facing direction!\n");
            }
        }
        else if(strcmp(input, "L") == 0 || strcmp(input, "l") == 0)
        {
            if(facing == 'N')
            {
                facing = 'W';
            }
            else if(facing == 'S')
            {
                facing = 'E';
            }
            else if(facing == 'E')
            {
                facing = 'N';
            }
            else if(facing == 'W')
            {
                facing = 'S';
            }
            else
            {
                printf("Error: Invalid facing direction!\n");
            }
        }
        else if(strcmp(input, "R") == 0 || strcmp(input, "r") == 0)
        {
            if(facing == 'N')
            {
                facing = 'E';
            }
            else if(facing == 'S')
            {
                facing = 'W';
            }
            else if(facing == 'E')
            {
                facing = 'S';
            }
            else if(facing == 'W')
            {
                facing = 'N';
            }
            else
            {
                printf("Error: Invalid facing direction!\n");
            }
        }
        else
        {
            printf("Error: Invalid input!\n");
        }

        printf("Current position: (%d,%d,%c)\n\n", x, y, facing);
    }

    return 0;
}