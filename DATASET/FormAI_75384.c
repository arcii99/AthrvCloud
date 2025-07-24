//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed, min_speed = 1, max_speed = 50;

    // Set a random seed for generating random speed test results
    srand(time(NULL));

    // Generate a random internet speed between 1 and 50 mbps
    speed = rand() % (max_speed - min_speed + 1) + min_speed;

    // Display the internet speed test result to the user
    printf("Your internet speed is: %d Mbps\n", speed);

    // Determine the quality of the internet speed based on the speed range
    if (speed >= 40)
    {
        printf("Your internet speed is excellent!\n");
    }
    else if (speed >= 20 && speed < 40)
    {
        printf("Your internet speed is good.\n");
    }
    else if (speed >= 10 && speed < 20)
    {
        printf("Your internet speed is average.\n");
    }
    else if (speed >= 1 && speed < 10)
    {
        printf("Your internet speed is poor.\n");
    }
    else
    {
        printf("Oops, something went wrong. Please try again later.\n");
    }

    return 0;
}