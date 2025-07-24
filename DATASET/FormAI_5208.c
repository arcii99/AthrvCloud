//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

void displayLights(int light)
{
    switch(light)
    {
        case GREEN:
            printf("Green Light\n");
            break;
        case YELLOW:
            printf("Yellow Light\n");
            break;
        case RED:
            printf("Red Light\n");
            break;
        default:
            printf("Invalid Input\n");
    }
}

int main()
{
    int light = GREEN;
    int timer = 0;
    srand(time(0));
    
    while(1)
    {
        if(light == GREEN)
        {
            timer = rand() % 10 + 1; // Random timer from 1 to 10 seconds
            printf("Green Light for %d seconds...\n", timer);
            displayLights(GREEN);
            sleep(timer);
            light = YELLOW;
        }
        else if(light == YELLOW)
        {
            timer = rand() % 5 + 1; // Random timer from 1 to 5 seconds
            printf("Yellow Light for %d seconds...\n", timer);
            displayLights(YELLOW);
            sleep(timer);
            light = RED;
        }
        else
        {
            timer = rand() % 15 + 1; // Random timer from 1 to 15 seconds
            printf("Red Light for %d seconds...\n", timer);
            displayLights(RED);
            sleep(timer);
            light = GREEN;
        }
    }
    
    return 0;
}