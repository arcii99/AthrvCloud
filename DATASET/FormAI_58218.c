//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int red = 0;
    int yellow = 0;
    int green = 0;
    int count = 0;

    while(1)
    {
        if(count == 0 || count == 3) // Red light
        {
            red = 1;
            yellow = 0;
            green = 0;
            printf("Red light is on\n");
            sleep(5); // Pause for 5 seconds
            count = 1;
        }
        else if(count == 1) // Red and yellow lights
        {
            red = 1;
            yellow = 1;
            green = 0;
            printf("Red and yellow lights are on\n");
            sleep(2); // Pause for 2 seconds
            count = 2;
        }
        else if(count == 2) // Green light
        {
            red = 0;
            yellow = 0;
            green = 1;
            printf("Green light is on\n");
            sleep(5); // Pause for 5 seconds
            count = 3;
        }
        else
        {
            printf("Error: invalid count value\n");
            exit(1);
        }
    }

    return 0;
}