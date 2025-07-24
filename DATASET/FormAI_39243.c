//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, count = 0;
    time_t start_time, end_time;

    start_time = time(NULL); // get start time

    // generating random numbers to simulate traffic flow
    srand(time(0));
    for(i = 0; i < 50; i++)
    {
        printf("Vehicle %d entered the road\n", i+1);
        if(rand() % 2 == 0)
        {
            printf("Vehicle %d stopped at the signal\n", i+1);
            count++;
        }
        else
        {
            printf("Vehicle %d passed the signal smoothly\n", i+1);
        }
    }

    end_time = time(NULL); // get end time

    printf("\n\nTotal %d vehicles crossed the signal in %ld seconds\n", 50-count, end_time-start_time);

    return 0;
}