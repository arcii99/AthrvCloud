//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed_rand = rand() % 100; // Generates a random speed between 0 and 99
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("We are testing your download speed...\n");
    printf("Your download speed is: %d Mbps\n", speed_rand);
    if (speed_rand < 10) // If download speed is very slow
    {
        printf("Oh no! Your download speed is very slow. Please contact your internet service provider.\n");
    }
    else if (speed_rand < 50) // If download speed is slow to average
    {
        printf("Your download speed is average. You may want to consider upgrading your internet plan for faster speeds.\n");
    }
    else if (speed_rand < 80) // If download speed is above average
    {
        printf("Congratulations! Your download speed is above average.\n");
    }
    else // If download speed is very fast
    {
        printf("WOW! Your download speed is lightning-fast!\n");
    }
    return 0;
}