//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int red, yellow, green;
    red = rand() % 10 + 1;
    yellow = rand() % 10 + 1;
    green = rand() % 10 + 1;
    
    printf("Surprise! This is a unique Traffic Light Controller program!\n");
    printf("Here's the time duration for each light:\n");
    printf("Red light: %d seconds\nYellow light: %d seconds\nGreen light: %d seconds\n", red, yellow, green);
    
    while(1)
    {
        printf("\nRed light\n");
        sleep(red); // wait for red light duration
        printf("\nYellow light\n");
        sleep(yellow); // wait for yellow light duration
        printf("\nGreen light\n");
        sleep(green); // wait for green light duration
    }
    return 0;
}