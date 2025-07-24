//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed;
    int downloadTime, uploadTime;
    int downloadSpeedArray[10], uploadSpeedArray[10];

    printf("Welcome to the Internet Speed Test!\n\n");

    // Download speed test
    printf("Testing download speed...\n");
    for (int i = 0; i < 10; i++) {
        srand(time(NULL)); // Seed random number generator
        downloadSpeed = rand() % 100; // Generate random download speed between 0 and 100 Mbps
        downloadSpeedArray[i] = downloadSpeed;
        downloadTime = 1000 / downloadSpeed; // Calculate estimated download time in seconds
        printf("Test #%d: Download speed is %d Mbps. Estimated download time is %d seconds.\n", i+1, downloadSpeed, downloadTime);
    }

    // Upload speed test
    printf("\nTesting upload speed...\n");
    for (int i = 0; i < 10; i++) {
        srand(time(NULL)); // Seed random number generator
        uploadSpeed = rand() % 100; // Generate random upload speed between 0 and 100 Mbps
        uploadSpeedArray[i] = uploadSpeed;
        uploadTime = 1000 / uploadSpeed; // Calculate estimated upload time in seconds
        printf("Test #%d: Upload speed is %d Mbps. Estimated upload time is %d seconds.\n", i+1, uploadSpeed, uploadTime);
    }

    // Calculate average speeds
    int downloadSum = 0, uploadSum = 0;
    for (int i = 0; i < 10; i++) {
        downloadSum += downloadSpeedArray[i];
        uploadSum += uploadSpeedArray[i];
    }
    double downloadAvg = (double) downloadSum / 10;
    double uploadAvg = (double) uploadSum / 10;

    // Print average speeds
    printf("\nAverage download speed is %.2f Mbps.\n", downloadAvg);
    printf("Average upload speed is %.2f Mbps.\n", uploadAvg);

    return 0;
}