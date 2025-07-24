//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for measuring time

int main()
{
    printf("Welcome to the Internet Speed Test Application!\n\n");

    // Getting user input
    int downloadSpeed, uploadSpeed;
    printf("Enter your download speed in Mbps: ");
    scanf("%d", &downloadSpeed);
    printf("Enter your upload speed in Mbps: ");
    scanf("%d", &uploadSpeed);

    // Generating random data size and calculating time taken for download/upload
    srand(time(0)); // Setting seed for random number generator
    int dataSize = rand() % (1024 - 100 + 1) + 100; // Generating random data size between 100KB and 1MB (1024KB)
    float downloadTime = (dataSize * 8.0) / (downloadSpeed * 1000000.0); // Converting download speed to Mbps and calculating time taken
    float uploadTime = (dataSize * 8.0) / (uploadSpeed * 1000000.0); // Converting upload speed to Mbps and calculating time taken

    // Displaying results
    printf("\nCalculating download speed...");
    printf("\nDownload speed: %d Mbps\nData size: %d KB\nTime taken: %f seconds\n", downloadSpeed, dataSize, downloadTime);
    printf("\nCalculating upload speed...");
    printf("\nUpload speed: %d Mbps\nData size: %d KB\nTime taken: %f seconds\n", uploadSpeed, dataSize, uploadTime);

    return 0;
}