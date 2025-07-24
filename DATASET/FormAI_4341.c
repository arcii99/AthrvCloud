//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void setLights(int red, int yellow, int green);
void runTrafficLight();

int main()
{
    runTrafficLight();

    return 0;
}

void setLights(int red, int yellow, int green)
{
    printf("\n************************************\n");

    if (red)
        printf("*\t\tRED LIGHT ON\t\t *\n");

    if (yellow)
        printf("*\tYELLOW LIGHT ON FOR 2 SECONDS\t *\n");

    if (green)
        printf("*\t\tGREEN LIGHT ON\t\t *\n");

    printf("************************************\n\n");
}

void runTrafficLight()
{
    srand(time(NULL));
    int light = rand() % 3;
    int previousLight = -1;

    while (1)
    {
        switch (light)
        {
        case RED:
            if (previousLight != RED)
                setLights(1, 0, 0);

            sleep(5); // red light stays on for 5 seconds
            previousLight = RED;
            light = YELLOW;
            setLights(0, 1, 0);

            break;
        case YELLOW:
            if (previousLight == RED)
                sleep(2); // yellow light stays on for 2 seconds if coming from red
            else
                sleep(3); // yellow light stays on for 3 seconds if coming from green

            previousLight = YELLOW;
            light = GREEN;
            setLights(0, 0, 1);

            break;
        case GREEN:
            if (previousLight != GREEN)
                setLights(0, 0, 1);

            sleep(5); // green light stays on for 5 seconds
            previousLight = GREEN;
            light = YELLOW;
            setLights(0, 1, 0);

            break;
        }
    }
}