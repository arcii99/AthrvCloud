//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red_light_time = 5, green_light_time = 12, yellow_light_time = 2;
    int countdown_timer = 0;

    srand(time(NULL));
    int random_number = rand()%3;

    switch(random_number)
    {
        case 0:
            printf("Initiating Cyberpunk Traffic Light System - Green Light\n\n");
            countdown_timer = green_light_time;
            break;

        case 1:
            printf("Initiating Cyberpunk Traffic Light System - Yellow Light\n\n");
            countdown_timer = yellow_light_time;
            break;

        case 2:
            printf("Initiating Cyberpunk Traffic Light System - Red Light\n\n");
            countdown_timer = red_light_time;
            break;
    }

    while(countdown_timer > 0)
    {
        printf("Time Remaining: %d seconds\n", countdown_timer);
        countdown_timer--;
        sleep(1);
    }

    printf("\n");

    switch(random_number)
    {
        case 0:
            printf("Green Light Time Up! Switching to Yellow Light...\n");
            countdown_timer = yellow_light_time;
            break;

        case 1:
            printf("Yellow Light Time Up! Switching to Red Light...\n");
            countdown_timer = red_light_time;
            break;

        case 2:
            printf("Red Light Time Up! Switching to Green Light...\n");
            countdown_timer = green_light_time;
            break;
    }

    while(countdown_timer > 0)
    {
        printf("Time Remaining: %d seconds\n", countdown_timer);
        countdown_timer--;
        sleep(1);
    }

    printf("\n");

    return 0;
}