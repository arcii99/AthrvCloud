//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN_TIME 10
#define YELLOW_TIME 5
#define RED_TIME 15

int main()
{
    int greenCounter = GREEN_TIME;
    int yellowCounter = YELLOW_TIME;
    int redCounter = RED_TIME;
    int currentState = 1; // 1 for green, 2 for yellow, 3 for red

    while(1)
    {
        if(currentState == 1)
        {
            printf("Green light is on.\n");
            while(greenCounter > 0)
            {
                printf("%d seconds left until switch to yellow.\n", greenCounter);
                sleep(1);
                greenCounter--;
            }
            currentState = 2;
        }

        if(currentState == 2)
        {
            printf("Yellow light is on.\n");
            while(yellowCounter > 0)
            {
                printf("%d seconds left until switch to red.\n", yellowCounter);
                sleep(1);
                yellowCounter--;
            }
            currentState = 3;
        }

        if(currentState == 3)
        {
            printf("Red light is on.\n");
            while(redCounter > 0)
            {
                printf("%d seconds left until switch to green.\n", redCounter);
                sleep(1);
                redCounter--;
            }
            currentState = 1;
        }
    }

    return 0;
}