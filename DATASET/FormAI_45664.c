//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main()
{
    int state = RED; // Start with red light
    int timeCounter = 0;
    int maxTime = 10; // Number of seconds of each light's duration
    srand(time(0)); // Seed the random number generator with current time

    while(1) // Loop indefinitely
    {
        switch(state)
        {
            case RED:
                printf("Red light\n");
                timeCounter = 0;
                while(timeCounter < maxTime)
                {
                    // Wait for the duration of the red light
                    printf("%d\n", timeCounter);
                    sleep(1);
                    timeCounter++;
                }
                state = GREEN; // Change to green light
                break;
            case YELLOW:
                printf("Yellow light\n");
                timeCounter = 0;
                while(timeCounter < maxTime)
                {
                    // Wait for the duration of the yellow light
                    printf("%d\n", timeCounter);
                    sleep(1);
                    timeCounter++;
                }
                if(rand()%2) // Randomly decide to change to green or red
                {
                    state = GREEN; // Change to green light
                }
                else
                {
                    state = RED; // Change to red light
                }
                break;
            case GREEN:
                printf("Green light\n");
                timeCounter = 0;
                while(timeCounter < maxTime)
                {
                    // Wait for the duration of the green light
                    printf("%d\n", timeCounter);
                    sleep(1);
                    timeCounter++;
                }
                state = YELLOW; // Change to yellow light
                break;
        }
    }

    return 0;
}