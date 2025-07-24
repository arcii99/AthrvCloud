//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Surrealist Traffic Light Controller */

int main()
{
    srand(time(NULL));
    int red = rand() % 10, green = rand() % 10, yellow = rand() % 10;

    printf("Welcome to the Surrealist Traffic Light Controller!\n");

    while (1)
    {
        if (red > green && red > yellow)
        {
            printf("The traffic light is now red.\n");
            green = 0;
            yellow = rand() % 10;
            red = rand() % 10;
        }
        else if (green > red && green > yellow)
        {
            printf("The traffic light is now green.\n");
            red = 0;
            yellow = rand() % 10;
            green = rand() % 10;
        }
        else if (yellow > green && yellow > red)
        {
            printf("The traffic light is now yellow.\n");
            red = rand() % 10;
            green = rand() % 10;
            yellow = 0;
        }
        else
        {
            printf("The traffic light is now a surreal mix of colors.\n");
            red = rand() % 10;
            green = rand() % 10;
            yellow = rand() % 10;
        }

        printf("Waiting...\n");
        sleep(1);
    }

    return 0;
}