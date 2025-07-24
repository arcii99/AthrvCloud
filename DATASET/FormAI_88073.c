//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Initialize random number generator
    
    int red_time = 5; //Time in seconds for red light
    int yellow_time = 2; //Time in seconds for yellow light
    int green_time = 5; //Time in seconds for green light
    int duration = 30; //Total duration of the traffic light system
    
    printf("Welcome to the Grateful Traffic Light Controller System\n\n");
    sleep(1);
    printf("Starting traffic light sequence for duration of %d seconds...\n\n", duration);
    sleep(1);

    for(int i = 1; i <= duration; i++)
    {
        int random_number = rand() % 3 + 1; //Generate random number between 1-3
        
        if(random_number == 1) //Red Light
        {
            printf("Red Light\n");
            sleep(red_time);
        }
        else if(random_number == 2) //Yellow Light
        {
            printf("Yellow Light\n");
            sleep(yellow_time);
        }
        else if(random_number == 3) //Green Light
        {
            printf("Green Light\n");
            sleep(green_time);
        }
    }
    printf("\nThank you for using the Grateful Traffic Light Controller System!\n");

    return 0;
}