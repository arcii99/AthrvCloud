//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main()
{
    int state = RED; // start with the red light on

    while (1) // loop indefinitely
    {
        system("clear"); // clear the console window
        printf("Traffic Light Controller\n\n");

        // display the current state of the traffic light
        switch (state)
        {
            case RED:
                printf("RED light on\n");
                printf("YELLOW light off\n");
                printf("GREEN light off\n");
                break;
            case YELLOW:
                printf("RED light off\n");
                printf("YELLOW light on\n");
                printf("GREEN light off\n");
                break;
            case GREEN:
                printf("RED light off\n");
                printf("YELLOW light off\n");
                printf("GREEN light on\n");
                break;
        }

        // change the state of the traffic light after a delay
        switch (state)
        {
            case RED:
                sleep(5); // stay red for 5 seconds
                state = GREEN; // switch to green
                break;
            case YELLOW:
                sleep(2); // stay yellow for 2 seconds
                state = RED; // switch to red
                break;
            case GREEN:
                sleep(5); // stay green for 5 seconds
                state = YELLOW; // switch to yellow
                break;
        }
    }

    return 0;
}