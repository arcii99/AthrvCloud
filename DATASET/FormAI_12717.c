//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP      'u'
#define DOWN    'd'
#define LEFT    'l'
#define RIGHT   'r'

int main()
{
    char input;
    int x = 0, y = 0;
    srand(time(NULL));
    printf("Starting position: (%d,%d)\n", x, y);
    while (1)
    {
        input = rand() % 4;
        switch (input)
        {
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
        }
        printf("Moved %c. New position: (%d,%d)\n", input, x, y);
        if (x == 10 || x == -10 || y == 10 || y == -10)
        {
            printf("Boundary reached. Robot stopped.\n");
            break;
        }
    }
    return 0;
}