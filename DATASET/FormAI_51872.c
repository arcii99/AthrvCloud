//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int green = 1, yellow = 2, red = 3; // Traffic light colors assigned to values
    
    int state = red; // Initial state of traffic light is red
    
    printf("Traffic Light is Red\n");
    
    while(1)
    {
        if(state == green)
        {
            printf("Traffic Light is Green\n");
            state = yellow; // Change state to yellow after green
            sleep(5); // Traffic light should stay green for 5 seconds
        }
        else if(state == yellow)
        {
            printf("Traffic Light is Yellow\n");
            state = red; // Change state to red after yellow
            sleep(2); // Traffic light should stay yellow for 2 seconds
        }
        else if(state == red)
        {
            printf("Traffic Light is Red\n");
            state = green; // Change state to green after red
            sleep(5); // Traffic light should stay red for 5 seconds
        }
    }
    
    return 0;
}