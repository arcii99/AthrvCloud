//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define SWITCH_TIME 2 // 2 seconds for each light

int main()
{
    int current_state = RED;
    
    while(1) // Infinite loop for continuous control
    {
        // Change state of traffic light
        if(current_state == RED)
        {
            printf("\nRED light is ON!\n");
            sleep(SWITCH_TIME);
            current_state = GREEN;
        }
        else if(current_state == GREEN)
        {
            printf("\nGREEN light is ON!\n");
            sleep(SWITCH_TIME);
            current_state = YELLOW;
        }
        else if(current_state == YELLOW)
        {
            printf("\nYELLOW light is ON!\n");
            sleep(SWITCH_TIME);
            current_state = RED;
        }
    }
    return 0;
}