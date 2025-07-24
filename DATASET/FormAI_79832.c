//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Internet Speed Test Application!\n\n");
    printf("Press 'Enter' to start the test...");
    getchar();

    printf("\n\nTesting your internet speed...\n");
    printf("This may take a few seconds...\n");

    // Simulating internet speed test by generating random download and upload speeds
    srand(time(NULL));
    int download_speed = rand() % 101; // Generate random download speed between 0 - 100 Mbps
    int upload_speed = rand() % 101; // Generate random upload speed between 0 - 100 Mbps

    printf("\n\nDownload speed: %d Mbps", download_speed);
    printf("\nUpload speed: %d Mbps", upload_speed);

    if (download_speed >= 50 && upload_speed >= 50)
    {
        printf("\n\nCongratulations! Your internet speed is excellent.");
    }
    else if (download_speed >= 30 && upload_speed >= 30)
    {
        printf("\n\nYour internet speed is good, but could be better.");
    }
    else
    {
        printf("\n\nYour internet speed is poor. You may need to contact your service provider.");
    }

    return 0;
}