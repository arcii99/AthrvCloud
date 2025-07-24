//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Creating variables to hold bandwidth and latency values
    float bandwidth, latency;

    // Generating random numbers for bandwidth and latency
    srand(time(NULL)); // Using current time as seed for random number generation

    bandwidth = (rand() % 90) + 10; // Random bandwidth value between 10 - 100 Mbps
    latency = (rand() % 100) + 1; // Random latency value between 1 - 100 ms

    // Printing the generated values
    printf("Your internet speed test results:\n");
    printf("Bandwidth: %.2f Mbps\n", bandwidth);
    printf("Latency: %d ms\n", (int)latency);

    // Determining the quality of the internet connection based on the generated values
    if (bandwidth >= 50 && latency <= 20) {
        printf("Your internet connection is excellent!\n");
    } else if (bandwidth >= 30 && latency <= 50) {
        printf("Your internet connection is good.\n");
    } else {
        printf("Your internet connection needs improvement.\n");
    }

    return 0;
}