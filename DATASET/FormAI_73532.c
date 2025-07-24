//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stopLight()
{
    printf("Red light is on - STOP!\n");
}

void cautionLight()
{
    printf("Yellow light is on - Slow down!\n");
}

void goLight()
{
    printf("Green light is on - Go!\n");
}

int main()
{
    srand(time(NULL));
    int randomNumber = rand() % 3;
    printf("Traffic light controller started\n\n");

    while (1)
    {
        switch (randomNumber)
        {
            case 0:
                stopLight();
                break;

            case 1:
                cautionLight();
                break;

            case 2:
                goLight();
                break;

            default:
                printf("Traffic light controller error - shutting down\n");
                exit(1);
        }

        printf("\n");

        randomNumber = rand() % 3;
        sleep(3);
    }

    return 0;
}