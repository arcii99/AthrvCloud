//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
 * This program simulates an internet speed test by generating random download and upload speeds,
 * and calculating the average speed.
 */

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random download and upload speeds
    double download_speed = (rand() % 51) + 50; // Between 50 and 100 Mbps
    double upload_speed = (rand() % 21) + 10; // Between 10 and 30 Mbps

    // Calculate the average speed
    double average_speed = (download_speed + upload_speed) / 2;

    // Print the results
    printf("\n------------------------");
    printf("\nInternet Speed Test Results");
    printf("\n------------------------");
    printf("\nDownload speed: %.2f Mbps", download_speed);
    printf("\nUpload speed: %.2f Mbps", upload_speed);
    printf("\nAverage speed: %.2f Mbps", average_speed);
    printf("\n------------------------\n\n");

    return 0;
}