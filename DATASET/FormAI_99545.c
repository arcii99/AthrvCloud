//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define MAX_DELAY 10

int main()
{
    int state = RED_LIGHT;
    int delay = 0;
    int temp;

    printf("Traffic Light Controller Beginning Operation...\n");

    srand(time(NULL));

    while(1)
    {
        switch(state)
        {
            case RED_LIGHT:
                printf("RED\n");
                delay = (rand() % MAX_DELAY) + 1;
                while(delay > 0)
                {
                    printf("%d\n", delay);
                    delay--;
                    sleep(1);
                }
                state = GREEN_LIGHT;
                break;

            case GREEN_LIGHT:
                printf("GREEN\n");
                delay = (rand() % MAX_DELAY) + 1;
                while(delay > 0)
                {
                    printf("%d\n", delay);
                    delay--;
                    sleep(1);
                }
                state = YELLOW_LIGHT;
                break;

            case YELLOW_LIGHT:
                printf("YELLOW\n");
                delay = (rand() % MAX_DELAY) + 1;
                while(delay > 0)
                {
                    printf("%d\n", delay);
                    delay--;
                    sleep(1);
                }
                temp = rand() % 2;
                if(temp == 0)
                {
                    state = GREEN_LIGHT;
                }
                else
                {
                    state = RED_LIGHT;
                }
                break;
        }
    }
    return 0;
}