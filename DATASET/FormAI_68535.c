//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed, latency;
    srand(time(0));
    download_speed = rand() % 101; // Generate random download speed from 0 to 100 Mbps
    upload_speed = rand() % 101; // Generate random upload speed from 0 to 100 Mbps
    latency = rand() % 101; // Generate random latency from 0 to 100 ms
    
    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("Testing your internet speed...\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Latency: %d ms\n", latency);
    
    // Determine internet speed quality based on download and upload speeds
    if(download_speed >= 50 && upload_speed >= 10)
    {
        printf("\nYour internet speed is excellent!\n");
    }
    else if(download_speed >= 30 && upload_speed >= 5)
    {
        printf("\nYour internet speed is good.\n");
    }
    else if(download_speed >= 10 && upload_speed >= 2)
    {
        printf("\nYour internet speed is fair.\n");
    }
    else
    {
        printf("\nYour internet speed is poor. Please contact your ISP.\n");
    }
    
    // Check latency
    if(latency <= 20)
    {
        printf("\nYour internet connection has low latency. This is great for online gaming and video conferencing.\n");
    }
    else if(latency <= 50)
    {
        printf("\nYour internet connection has average latency. This is sufficient for web browsing and video streaming.\n");
    }
    else
    {
        printf("\nYour internet connection has high latency. This may cause lag during online gaming and video conferencing.\n");
    }
    
    return 0;
}