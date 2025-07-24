//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void print_traffic_lights(int red, int yellow, int green)
{
    for (int i=0; i<3; i++)
    {
        if (red == i)
        {
            printf("RED ");
        }
        else if (yellow == i)
        {
            printf("YELLOW ");
        }
        else if (green == i)
        {
            printf("GREEN ");
        }
    }
    printf("\n");
}

int main()
{
    int red, yellow, green;
    red = yellow = green = 0; // initialize all lights to off
    
    while (1) // infinite loop
    {
        print_traffic_lights(red, yellow, green);
        
        // wait for 1 second
        sleep(1);
        
        // randomize the lights
        srand(time(0));
        int random = rand() % 3;
        
        if (random == 0)
        {
            red = 0;
            yellow = 1;
            green = 2;
        }
        else if (random == 1)
        {
            red = 2;
            yellow = 0;
            green = 1;
        }
        else if (random == 2)
        {
            red = 1;
            yellow = 2;
            green = 0;
        }
    }
    
    return 0;
}