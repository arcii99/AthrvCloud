//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main()
{
    srand(time(NULL));
    int state = 1, timer = rand() % 30 + 1;

    while (1)
    {
        switch (state)
        {
            case GREEN:
                printf("\nGreen light\n");
                for (int i = 0; i < timer; i++)
                {
                    printf("Time remaining: %d seconds\n", timer - i);
                    sleep(1);
                }
                state = YELLOW;
                timer = rand() % 5 + 1;
                break;

            case YELLOW:
                printf("\nYellow light\n");
                for (int i = 0; i < timer; i++)
                {
                    printf("Time remaining: %d seconds\n", timer - i);
                    sleep(1);
                }
                state = RED;
                timer = rand() % 25 + 1;
                break;

            case RED:
                printf("\nRed light\n");
                for (int i = 0; i < timer; i++)
                {
                    printf("Time remaining: %d seconds\n", timer - i);
                    sleep(1);
                }
                state = GREEN;
                timer = rand() % 15 + 1;
                break;
        }
    }

    return 0;
}