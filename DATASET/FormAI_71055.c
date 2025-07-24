//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed;
    srand(time(NULL)); // Seed random number generator
    
    // Generate random numbers for download and upload speeds between 1 and 100 Mbps
    download_speed = rand() % 100 + 1;
    upload_speed = rand() % 100 + 1; 
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Testing your internet speed...\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    
    return 0;
}