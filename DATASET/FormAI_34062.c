//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that returns a random internet speed
double getSpeed() {
    return (double)(rand() % 300) + ((double)(rand() % 10) / 10);
}

int main() {
    // Set up seed for random number generation
    srand(time(0));
    // Initialize variables
    double speed, min = 301, max = -1, avg = 0;
    int i, samples = 10;
    // Get samples of internet speed
    for (i = 0; i < samples; i++) {
        speed = getSpeed();
        printf("Sample %d: %.1f Mbps\n", i + 1, speed);
        // Update min and max speeds
        if (speed < min) min = speed;
        if (speed > max) max = speed;
        // Update average speed
        avg += speed;
    }
    // Calculate average speed
    avg /= samples;
    printf("\n");
    // Display statistics
    printf("Minimum speed: %.1f Mbps\n", min);
    printf("Maximum speed: %.1f Mbps\n", max);
    printf("Average speed: %.1f Mbps\n", avg);
    return 0;
}