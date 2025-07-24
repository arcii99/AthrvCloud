//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare and initialize variables
    int red = 1;
    int yellow = 0;
    int green = 0;
    int count = 0;
    int maxCount = 10;

    while(count < maxCount)
    {
        // Generate a random number between 1 and 3 to determine which light to turn on
        srand(time(NULL));
        int light = rand() % 3 + 1;

        // Turn on the appropriate light according to the random number generated
        if(light == 1)
        {
            printf("Red Light\n");
            red = 1;
            yellow = 0;
            green = 0;
        }
        else if(light == 2)
        {
            printf("Yellow Light\n");
            red = 0;
            yellow = 1;
            green = 0;
        }
        else
        {
            printf("Green Light\n");
            red = 0;
            yellow = 0;
            green = 1;
        }

        // Increment count
        count++;

        // Delay for two seconds
        sleep(2);
    }

    return 0;
}