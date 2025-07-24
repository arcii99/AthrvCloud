//FormAI DATASET v1.0 Category: Robot movement control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int position = 0;
    char direction[4] = {'N', 'S', 'E', 'W'};

    srand(time(0));

    printf("Starting position: %d\n", position);

    for (int i = 0; i < 50; i++)
    {
        int random_num = rand() % 4;

        if (direction[random_num] == 'N')
        {
            position += 1;
            printf("Moved North, new position: %d\n", position);
        }
        else if (direction[random_num] == 'S')
        {
            position -= 1;
            printf("Moved South, new position: %d\n", position);
        }
        else if (direction[random_num] == 'E')
        {
            position += 2;
            printf("Moved East, new position: %d\n", position);
        }
        else if (direction[random_num] == 'W')
        {
            position -= 2;
            printf("Moved West, new position: %d\n", position);
        }

        if (position < 0)
        {
            printf("Oops! You fell off the grid.\n");
            break;
        }
    }

    printf("Final position: %d\n", position);

    return 0;
}