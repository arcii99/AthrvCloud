//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

int main()
{
    int currentLight = GREEN; //initial state is green
    int greenDuration = 10; //duration for green light
    int yellowDuration = 5; //duration for yellow light
    int redDuration = 15; //duration for red light
    time_t startTime = time(NULL); //start time of the program

    while(1) //loop infinitely
    {
        system("clear"); //clear the screen
        time_t currentTime = time(NULL); //get the current time
        int elapsedSeconds = difftime(currentTime, startTime); //calculate the elapsed seconds

        printf("-- Traffic Light Controller --\n\n");

        switch(currentLight)
        {
            case GREEN:
                printf("GREEN LIGHT ON\n");
                printf("Duration: %d seconds\n", greenDuration);
                if(elapsedSeconds >= greenDuration) //if green duration is over, switch to yellow
                {
                    currentLight = YELLOW;
                    startTime = time(NULL);
                }
                break;

            case YELLOW:
                printf("YELLOW LIGHT ON\n");
                printf("Duration: %d seconds\n", yellowDuration);
                if(elapsedSeconds >= yellowDuration) //if yellow duration is over, switch to red
                {
                    currentLight = RED;
                    startTime = time(NULL);
                }
                break;

            case RED:
                printf("RED LIGHT ON\n");
                printf("Duration: %d seconds\n", redDuration);
                if(elapsedSeconds >= redDuration) //if red duration is over, switch to green
                {
                    currentLight = GREEN;
                    startTime = time(NULL);
                }
                break;
        }
    }

    return 0;
}