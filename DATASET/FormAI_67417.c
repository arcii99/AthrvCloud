//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Welcome Message
    printf("Welcome to the Internet Speed Test App!\n");
    printf("Press Enter to Start the Test...\n");
    getchar();

    // Initialize Variables
    double downloadSpeed, uploadSpeed;
    clock_t startTime, endTime;
    long dataSize = 1000000000; // 1GB in bytes

    // Start Download Test
    printf("Starting Download Test...\n");
    startTime = clock(); // Start Timer
    char* downloadData = (char*)malloc(dataSize); // Allocate Memory
    for(long i=0;i<dataSize;i++)
    {
        downloadData[i] = '0'; // Fill with dummy data
    }
    endTime = clock(); // End Timer
    downloadSpeed = (double)dataSize / ((double)(endTime - startTime) / (double)CLOCKS_PER_SEC); // Calculate Download Speed

    // Start Upload Test
    printf("Starting Upload Test...\n");
    startTime = clock(); // Start Timer
    for(long i=0;i<dataSize;i++)
    {
        // Do nothing, just wait
    }
    endTime = clock(); // End Timer
    uploadSpeed = (double)dataSize / ((double)(endTime - startTime) / (double)CLOCKS_PER_SEC); // Calculate Upload Speed

    // Print Results
    printf("Download Speed: %0.2f Mbps\n", (downloadSpeed*8)/1000000);
    printf("Upload Speed: %0.2f Mbps\n", (uploadSpeed*8)/1000000);

    // Free Memory and Exit
    free(downloadData);
    return 0;
}