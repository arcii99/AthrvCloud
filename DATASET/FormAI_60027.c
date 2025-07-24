//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Internet Speed Test!\n");

    // measuring download speed
    printf("\nTesting download speed...");
    srand(time(NULL)); // seeding random number generator
    int download_speed = rand() % 101; // generating a random integer between 0 and 100 for download speed
    printf("\nYour download speed is %d Mbps.", download_speed);

    // measuring upload speed
    printf("\n\nTesting upload speed...");
    int upload_speed = rand() % 101; // generating a random integer between 0 and 100 for upload speed
    printf("\nYour upload speed is %d Mbps.", upload_speed);

    // determining internet speed based on download and upload speeds
    printf("\n\nAnalyzing data...");
    if(download_speed >= 50 && upload_speed >= 50) // if both download and upload speeds are >= 50 Mbps
    {
        printf("\nYour internet speed is extremely fast!");
    }
    else if(download_speed >= 25 && upload_speed >= 25) // if both download and upload speeds are >= 25 Mbps
    {
        printf("\nYour internet speed is fast.");
    }
    else if(download_speed < 25 && upload_speed < 25) // if both download and upload speeds are < 25 Mbps
    {
        printf("\nYour internet speed is slow.");
    }
    else // if neither of the above conditions are met
    {
        printf("\nYour internet speed is average.");
    }

    // providing tips for improving internet speed
    printf("\n\nTips for improving your internet speed:");
    if(download_speed < 10 || upload_speed < 10) // if either download or upload speed is < 10 Mbps
    {
        printf("\n- Consider upgrading your internet plan for faster speeds.");
    }
    if(download_speed >= 50 && upload_speed >= 50) // if both download and upload speeds are >= 50 Mbps
    {
        printf("\n- Keep your internet equipment up to date, including your modem and router.");
    }
    printf("\n- Limit the number of devices connected to your network at once.");

    printf("\n\nThank you for using the Internet Speed Test!");
    return 0;
}