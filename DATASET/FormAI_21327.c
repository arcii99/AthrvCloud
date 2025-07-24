//FormAI DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>

int main()
{
    int position = 0;
    char direction;

    printf("Enter direction (f-forward, b-backward, r-right, l-left): ");

    while (1)
    {
        scanf("%c", &direction);

        if (direction == '\n')
        {
            continue;
        }
        else if (direction == 'f')
        {
            position++;
        }
        else if (direction == 'b')
        {
            position--;
        }
        else if (direction == 'r')
        {
            printf("Turn right\n");
        }
        else if (direction == 'l')
        {
            printf("Turn left\n");
        }
        else
        {
            printf("Invalid direction\n");
        }

        printf("Position: %d\n", position);
    }
    
    return 0;
}