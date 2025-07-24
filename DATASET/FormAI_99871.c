//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int speeds[4] = {0};
    int max_speed = 0;
    int min_speed = 99999;
    int avg_speed = 0;
    int random_num;
    
    srand(time(0)); //seed for random number generator
    
    printf("Welcome to the Post-Apocalyptic Internet Speed Test!\n");
    printf("Initiating test...\n");
    
    for(int i = 0; i < 4; i++)
    {
        //generating random number between 1 and 1000
        random_num = (rand() % 1000) + 1;
        speeds[i] = random_num;
        printf("Test #%d: Download speed: %d Mbps\n", i+1, speeds[i]);
        
        if(speeds[i] > max_speed)
        {
            max_speed = speeds[i];
        }
        
        if(speeds[i] < min_speed)
        {
            min_speed = speeds[i];
        }
        
        avg_speed += speeds[i]; //adding up speeds to calculate average
    }
    
    avg_speed /= 4; //dividing by number of tests to get average speed
    
    printf("\nTest results:\n");
    printf("Maximum speed: %d Mbps\n", max_speed);
    printf("Minimum speed: %d Mbps\n", min_speed);
    printf("Average speed: %d Mbps\n\n", avg_speed);
    
    if(avg_speed < 50)
    {
        printf("Your internet is barely functional...try scavenging for better equipment!\n");
    }
    else if(avg_speed >= 50 && avg_speed < 100)
    {
        printf("Your internet is moderately functional, but upgrading wouldn't hurt.\n");
    }
    else if(avg_speed >= 100 && avg_speed < 500)
    {
        printf("Your internet is performing well, good job!\n");
    }
    else
    {
        printf("Your internet is lightning fast, congratulations on your valuable resources!\n");
    }
    
    return 0;
}