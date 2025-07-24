//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int green_time = 20; // set green light time to 20 seconds
    int yellow_time = 5; // set yellow light time to 5 seconds
    int red_time = 25; // set red light time to 25 seconds

    int timer = 0;

    int green_count = 0;
    int yellow_count = 0;
    int red_count = 0;

    while (1) // loop infinitely until program is terminated
    {
        int random_number = rand() % 3; // generate random number between 0 and 2

        switch (random_number)
        {
            case 0: // green light
                if(timer < green_time)
                {
                    printf("Green Light\n");
                    green_count++;
                    printf("Green light count: %d\n", green_count);
                }
                else if(timer < green_time + yellow_time)
                {
                    printf("Yellow Light\n");
                    yellow_count++;
                    printf("Yellow light count: %d\n", yellow_count);
                }
                else
                {
                    printf("Red Light\n");
                    red_count++;
                    printf("Red light count: %d\n", red_count);
                    timer = 0; // reset timer for next cycle
                }
                break;
            case 1: // yellow light
                if(timer < yellow_time)
                {
                    printf("Yellow Light\n");
                    yellow_count++;
                    printf("Yellow light count: %d\n", yellow_count);
                }
                else
                {
                    printf("Red Light\n");
                    red_count++;
                    printf("Red light count: %d\n", red_count);
                    timer = 0; // reset timer for next cycle
                }
                break;
            case 2: // red light
                if(timer < red_time)
                {
                    printf("Red Light\n");
                    red_count++;
                    printf("Red light count: %d\n", red_count);
                }
                else
                {
                    printf("Green Light\n");
                    green_count++;
                    printf("Green light count: %d\n", green_count);
                    timer = 0; // reset timer for next cycle
                }
                break;
        }

        timer++; // increment timer

        while(timer < 1000); // delay to slow down display speed
    }

    return 0;
}