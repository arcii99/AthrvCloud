//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100 // Maximum internet speed in Mbps.

// Function to generate a random internet speed between 0 and the maximum speed.
float generateRandomSpeed() {
    return (float)rand()/(RAND_MAX/MAX_SPEED);
}

// Function to simulate the internet speed test and return the speed in Mbps.
float runInternetSpeedTest() {
    float speed = generateRandomSpeed(); // Generate a random speed.
    printf("Testing Internet Speed...\n");
    printf("Download Speed: %.2f Mbps\n", speed);
    return speed;
}

int main() {
    srand(time(NULL)); // Seed the random number generator.
    float downloadSpeed = runInternetSpeedTest(); // Run the internet speed test.
    printf("Your internet download speed is %.2f Mbps.\n", downloadSpeed);
    return 0;
}