//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the C Internet Speed Test Application!\n\n");
    
    // Generate random download and upload speeds
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    
    printf("Testing download speed... %d Mbps\n", download_speed);
    sleep(2); // simulate testing download speed
    printf("Testing upload speed... %d Mbps\n", upload_speed);
    sleep(2); // simulate testing upload speed
    
    printf("\nResults:\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    
    // Determine internet connection quality based on speed
    if (download_speed >= 75 && upload_speed >= 25)
    {
        printf("\nWow! Your internet speed is lightning fast!\n");
    }
    else if (download_speed >= 50 && upload_speed >= 10)
    {
        printf("\nYour internet connection is good!\n");
    }
    else if (download_speed >= 25 && upload_speed >= 5)
    {
        printf("\nYour internet connection is average.\n");
    }
    else
    {
        printf("\nYour internet connection is slow.\n");
    }
    
    return 0;
}