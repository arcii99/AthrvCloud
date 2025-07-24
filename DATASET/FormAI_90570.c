//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed;
    srand(time(0)); // seed the random number generator with current time
    
    // generate random internet speeds between 1 Mbps and 1000 Mbps
    download_speed = rand() % 1000 + 1;
    upload_speed = rand() % 1000 + 1;
    
    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("Please wait while the application measures your internet speed...\n\n");
    printf("Your download speed is: %d Mbps\n", download_speed);
    printf("Your upload speed is: %d Mbps\n", upload_speed);
    
    // calculate quality of connection based on download speed
    if (download_speed < 10)
    {
        printf("Your internet connection is very poor.\n");
    }
    else if (download_speed < 50)
    {
        printf("Your internet connection is poor.\n");
    }
    else if (download_speed < 100)
    {
        printf("Your internet connection is average.\n");
    }
    else if (download_speed < 500)
    {
        printf("Your internet connection is good.\n");
    }
    else
    {
        printf("Your internet connection is excellent!\n");
    }
    
    // calculate latency
    int latency = rand() % 100 + 1;
    printf("Your latency is: %d ms\n", latency);
    
    // calculate jitter
    int jitter = rand() % 50 + 1;
    printf("Your jitter is: %d ms\n", jitter);
    
    // suggest improvements based on results
    if (download_speed < 10 && latency > 100)
    {
        printf("We recommend upgrading your internet service to improve your connection.\n");
    }
    else if (download_speed < 50 && latency > 50)
    {
        printf("We recommend contacting your internet service provider to fix your connection issues.\n");
    }
    else
    {
        printf("Your internet connection seems to be working fine!\n");
    }
    
    return 0;
}