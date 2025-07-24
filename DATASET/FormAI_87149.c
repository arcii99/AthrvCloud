//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int timeLeft = 10;
    printf("Traffic Light Controller\n");
    while(timeLeft >= 0)
    {
        printf("Time left: %d seconds\n", timeLeft);

        if(timeLeft == 10)
        {
            printf("Green light turned on\n");
        }
        else if(timeLeft <= 5 && timeLeft > 0)
        {
            printf("Red light turning on in %d seconds\n", timeLeft);
        }
        else if(timeLeft == 0)
        {
            printf("Red light turned on\n");
        }

        timeLeft--;
        sleep(1);
    }

    printf("Traffic Light Controller Finished\n");
    return 0;
}