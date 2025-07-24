//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initial variables
    int red = 1;
    int yellow = 0;
    int green = 0;

    srand(time(NULL));
    int random_time = rand() % 11 + 5; // Random time between 5-15 seconds

    while(1)
    {
        // Control Red Light
        if(red == 1)
        {
            printf("RED LIGHT\n");
            sleep(3);
            red = 0;
            yellow = 1;
        }

        // Control Yellow Light
        else if(yellow == 1)
        {
            printf("YELLOW LIGHT\n");
            sleep(1);
            yellow = 0;
            green = 1;
        }

        // Control Green Light
        else if(green == 1)
        {
            printf("GREEN LIGHT\n");
            sleep(random_time);
            green = 0;
            yellow = 1;
        }
    }

    return 0;
}