//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int state = 1, timeLeft = 0;

    while(1)
    {
        if(timeLeft == 0)
        {
            switch(state)
            {
                case 1:
                    printf("RED\n");
                    timeLeft = 10;
                    state = 2;
                    break;

                case 2:
                    printf("GREEN\n");
                    timeLeft = 12;
                    state = 3;
                    break;

                case 3:
                    printf("YELLOW\n");
                    timeLeft = 3;
                    state = 1;
                    break;
            }
        }

        while(timeLeft > 0)
        {
            printf("remaining time: %d\n", timeLeft);
            timeLeft--;
            sleep(1);
        }
    }

    return 0;
}