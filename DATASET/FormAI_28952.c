//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SPEED 1   // Minimum Speed in Mbps
#define MAX_SPEED 100 // Maximum Speed in Mbps

int main()
{
    int internetSpeed;

    // Generating a random internet speed between MIN_SPEED and MAX_SPEED
    srand(time(0));
    internetSpeed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;

    // Displaying the internet speed
    printf("Your internet speed is %d Mbps\n", internetSpeed);

    // Checking the internet speed status
    if (internetSpeed < 10)
        printf("Your internet speed is too slow. Please contact your internet service provider.\n");
    else if (internetSpeed < 50)
        printf("Your internet speed is moderate. You can browse websites and use social media platforms without any issues.\n");
    else if (internetSpeed < 100)
        printf("Your internet speed is fast. You can stream HD videos and play online games without any buffering.\n");
    else
        printf("Your internet speed is blazing fast. You can download large files and stream 4K videos without any issues.\n");

    return 0;
}