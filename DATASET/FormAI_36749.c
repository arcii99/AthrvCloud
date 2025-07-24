//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int green_time = 5;
    int yellow_time = 2;
    int red_time = 5;
    int total_time = 0;
    time_t start_time, end_time;
    
    printf("Traffic light controller started...\n");
    
    while(1)
    {
        //Green light
        printf("Green light on\n");
        start_time = time(NULL);
        while(total_time < green_time)
        {
            end_time = time(NULL);
            total_time = (int) difftime(end_time, start_time);
        }
        total_time = 0;
        
        //Yellow light
        printf("Yellow light on\n");
        start_time = time(NULL);
        while(total_time < yellow_time)
        {
            end_time = time(NULL);
            total_time = (int) difftime(end_time, start_time);
        }
        total_time = 0;
        
        //Red light
        printf("Red light on\n");
        start_time = time(NULL);
        while(total_time < red_time)
        {
            end_time = time(NULL);
            total_time = (int) difftime(end_time, start_time);
        }
        total_time = 0;
    }
    
    return 0;
}