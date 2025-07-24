//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int green_time = 10;
    int yellow_time = 4;
    int red_time = 14;

    int current_signal = 1;
    int total_time_elapsed = 0;

    while(total_time_elapsed < 1800)
    {
        switch(current_signal)
        {
            case 1:
                printf("Green Light for %d seconds\n", green_time);
                total_time_elapsed += green_time;
                current_signal = 2;
                break;

            case 2:
                printf("Yellow Light for %d seconds\n", yellow_time);
                total_time_elapsed += yellow_time;
                current_signal = 3;
                break;

            case 3:
                printf("Red Light for %d seconds\n", red_time);
                total_time_elapsed += red_time;
                current_signal = 1;
                break;

            default:
                printf("Invalid Signal\n");
                break;
        }
    }

    printf("Traffic Light Program Completed\n");
    
    return 0;
}