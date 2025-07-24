//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 1 and 100
int generateRandomNumber() {
    return (rand() % 100) + 1;
}

// Function to simulate internet speed test
void runInternetSpeedTest() {
    // Generate random numbers for download and upload speed
    int downloadSpeed = generateRandomNumber();
    int uploadSpeed = generateRandomNumber();

    // Print download and upload speed
    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n", uploadSpeed);

    // Determine internet speed based on download speed
    if (downloadSpeed >= 50) {
        printf("Your internet speed is excellent!\n");
    } else if (downloadSpeed >= 25) {
        printf("Your internet speed is good.\n");
    } else if (downloadSpeed >= 10) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is poor.\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Run internet speed test
    runInternetSpeedTest();

    return 0;
}