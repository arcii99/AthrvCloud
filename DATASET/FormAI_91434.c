//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// Function to simulate internet speed test
void simulateSpeedTest() {
    // Generate random download and upload speeds between 1-100 Mbps
    int downloadSpeed = rand() % 100 + 1;
    int uploadSpeed = rand() % 100 + 1;

    // Display download and upload speeds
    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n", uploadSpeed);
}

// Function to calculate time difference between two timespec structures
double getTimeDifference(struct timespec start, struct timespec end) {
    double difference = (double)(end.tv_sec - start.tv_sec) * 1000.0;
    difference += (double)(end.tv_nsec - start.tv_nsec) / 1000000.0;
    return difference;
}

// Main function
int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Store start time
    struct timespec startTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    // Simulate speed test
    simulateSpeedTest();

    // Store end time
    struct timespec endTime;
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    // Calculate time elapsed during speed test
    double elapsedTime = getTimeDifference(startTime, endTime);

    // Display time elapsed
    printf("Time Elapsed: %.2f ms\n", elapsedTime);

    // Return 0 to indicate successful program execution
    return 0;
}