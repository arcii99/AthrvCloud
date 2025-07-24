//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
// Brave Traffic Light Controller Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 30
#define YELLOW 5
#define RED 20

int main()
{
    srand(time(NULL)); // seed the random number generator 

    int current_color = -1; // initialize current traffic light color
    int next_color; // declare next traffic light color
    int time_remaining = 0; // declare time remaining variable

    printf("---- TRAFFIC LIGHT CONTROLLER ----\n\n");

    while(1) // infinite loop
    {
        // update current color
        current_color = next_color;

        // generate next color
        do {
            next_color = rand() % 3; // 0 for green, 1 for yellow, 2 for red
        } while (next_color == current_color);

        switch (next_color)
        {
            case 0: // green state
                printf("GREEN light is ON\n");
                time_remaining = GREEN;
                break;
            case 1: // yellow state
                printf("YELLOW light is ON\n");
                time_remaining = YELLOW;
                break;
            case 2: // red state
                printf("RED light is ON\n");
                time_remaining = RED;
                break;
        }

        // countdown timer
        while (time_remaining > 0) {
            printf("Time remaining: %d seconds\n", time_remaining);
            time_remaining--;
            sleep(1); // sleep for 1 second
        }

        printf("\n");
    }

    return 0;
}