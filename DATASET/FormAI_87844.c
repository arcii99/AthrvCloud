//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main()
{
    int traffic_light[3] = {0};
    int timer = 0;

    printf("\nStarting Traffic Light Controller\n\n");

    while(1)
    {
        timer++;

        // check for Green Light
        if(traffic_light[GREEN] && timer == 20)
        {
            traffic_light[GREEN] = 0;
            traffic_light[YELLOW] = 1;
            timer = 0;
        }
        // check for Yellow Light
        else if(traffic_light[YELLOW] && timer == 5)
        {
            traffic_light[YELLOW] = 0;
            traffic_light[RED] = 1;
            timer = 0;
        }
        // check for Red Light
        else if(traffic_light[RED] && timer == 15)
        {
            traffic_light[RED] = 0;
            traffic_light[GREEN] = 1;
            timer = 0;
        }

        // Display Traffic Light Colors
        if(traffic_light[RED])
            printf("%d seconds - RED Light\n", timer);
        else if(traffic_light[YELLOW])
            printf("%d seconds - YELLOW Light\n", timer);
        else if(traffic_light[GREEN])
            printf("%d seconds - GREEN Light\n", timer);

        // Pause for 1 Second
        sleep(1);
    }

    return 0;
}