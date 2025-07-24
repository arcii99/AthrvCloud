//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This program simulates an internet speed test by generating a random download and upload speed
 * and displaying the results to the user.
 */
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate random download and upload speeds between 1 and 100 Mbps
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;

    // Display the results to the user
    printf("Internet Speed Test\n");
    printf("-------------------\n");
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);

    return 0;
}