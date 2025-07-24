//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int downloadSpeed, uploadSpeed;
    int downloadTime, uploadTime;

    srand(time(NULL)); // srand function makes sure that the random number generated is completely random.

    downloadSpeed = rand()%200 + 1; // Generating random download speed between 1 and 200 Mbps.
    uploadSpeed = rand()%100 + 1; // Generating random upload speed between 1 and 100 Mbps.

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Your internet download speed is: %d Mbps.\n", downloadSpeed);
    printf("Your internet upload speed is: %d Mbps.\n", uploadSpeed);

    printf("\nStarting download speed test...");
    printf("\nPlease wait...\n");
    downloadTime = rand()%5 + 1; // Generating random download time between 1 and 5 seconds.
    printf("Download speed test completed in %d seconds!\n", downloadTime);

    printf("\nStarting upload speed test...");
    printf("\nPlease wait...\n");
    uploadTime = rand()%3 + 1; // Generating random upload time between 1 and 3 seconds.
    printf("Upload speed test completed in %d seconds!\n", uploadTime);

    printf("\nThank you for using the Internet Speed Test Application!\n");

    return 0;
}