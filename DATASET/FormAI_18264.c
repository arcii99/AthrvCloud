//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GB 1024*1024*1024
#define MB 1024*1024
#define KB 1024

int main()
{
    int data_size = 10*MB; // amount of data to be downloaded
    int speed = 0; // initial internet speed in Mbps
    double download_time = 0; // download time in seconds
    double download_rate = 0; // download rate in Mbps

    // prompt user to enter internet speed in Mbps
    printf("Enter your internet speed in Mbps: ");
    scanf("%d", &speed);

    // calculate download time and download rate
    download_time = (double)data_size / ((double)speed/8);
    download_rate = ((double)data_size / download_time) / (double)MB;
    
    // display results
    printf("\n\nDOWNLOAD SPEED TEST\n");
    printf("====================\n");
    printf("Internet speed:\t %d Mbps\n", speed);
    printf("Data size:\t %d MB\n", data_size/MB);
    printf("Download time:\t %.2f seconds\n", download_time);
    printf("Download rate:\t %.2f MB/s\n", download_rate);
    printf("====================\n");

    return 0;
}