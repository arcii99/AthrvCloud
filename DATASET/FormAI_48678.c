//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    //Initializing variables
    int red_time = rand() % 10 + 1;
    int yellow_time = rand() % 5 + 1;
    int green_time = rand() % 10 + 1;
    int time_limit = rand() % 600 + 1; //For a cycle of 10 mins
    
    printf("Welcome to the Traffic Signal controller program!\n");
    printf("The red light will be on for %d seconds.\n", red_time);
    printf("The yellow light will be on for %d seconds.\n", yellow_time);
    printf("The green light will be on for %d seconds.\n", green_time);
    printf("The total time for a signal cycle will be %d seconds.\n", time_limit);
    printf("\n");

    int timer = 0; //Initializing a timer to keep track of time

    //Infinite loop to keep the signal running
    while(1)
    {
        printf("Red light ON!\n");
        for(int i=0; i<red_time; i++)
        {
            printf("Time left for green light: %d\n", red_time-i);
            timer++;
            if(timer == time_limit)
            {
                printf("Timeout! Resetting timer...\n\n");
                timer = 0;
                red_time = rand() % 10 + 1;
                yellow_time = rand() % 5 + 1;
                green_time = rand() % 10 + 1;
                time_limit = rand() % 600 + 1;
                printf("The red light will be on for %d seconds.\n", red_time);
                printf("The yellow light will be on for %d seconds.\n", yellow_time);
                printf("The green light will be on for %d seconds.\n", green_time);
                printf("The total time for a signal cycle will be %d seconds.\n", time_limit);
                printf("\n");
                break;
            }
        }

        printf("Yellow light ON!\n");
        for(int i=0; i<yellow_time; i++)
        {
            printf("Time left for green light: %d\n", yellow_time-i);
            timer++;
            if(timer == time_limit)
            {
                printf("Timeout! Resetting timer...\n\n");
                timer = 0;
                red_time = rand() % 10 + 1;
                yellow_time = rand() % 5 + 1;
                green_time = rand() % 10 + 1;
                time_limit = rand() % 600 + 1;
                printf("The red light will be on for %d seconds.\n", red_time);
                printf("The yellow light will be on for %d seconds.\n", yellow_time);
                printf("The green light will be on for %d seconds.\n", green_time);
                printf("The total time for a signal cycle will be %d seconds.\n", time_limit);
                printf("\n");
                break;
            }
        }

        printf("Green light ON!\n");
        for(int i=0; i<green_time; i++)
        {
            printf("Time left for red light: %d\n", green_time-i);
            timer++;
            if(timer == time_limit)
            {
                printf("Timeout! Resetting timer...\n\n");
                timer = 0;
                red_time = rand() % 10 + 1;
                yellow_time = rand() % 5 + 1;
                green_time = rand() % 10 + 1;
                time_limit = rand() % 600 + 1;
                printf("The red light will be on for %d seconds.\n", red_time);
                printf("The yellow light will be on for %d seconds.\n", yellow_time);
                printf("The green light will be on for %d seconds.\n", green_time);
                printf("The total time for a signal cycle will be %d seconds.\n", time_limit);
                printf("\n");
                break;
            }
        }
    }

    return 0;
}