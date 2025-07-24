//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("Welcome to the Internet Speed Test Application\n");

    // Random number generation
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;

    // Display speeds
    printf("\nYour download speed is: %d Mbps", download_speed);
    printf("\nYour upload speed is: %d Mbps", upload_speed);

    // Speed comparison
    if (download_speed >= 50 && upload_speed >= 50)
    {
        printf("\n\nCongratulations! You have an excellent internet speed.");
    }
    else if (download_speed >= 25 && upload_speed >= 25)
    {
        printf("\n\nYour internet speed is good, but it could be better.");
    }
    else
    {
        printf("\n\nYour internet speed is not up to par. Consider upgrading.");
    }

    // Thank you message
    printf("\n\nThank you for using the Internet Speed Test Application");

    return 0;
}