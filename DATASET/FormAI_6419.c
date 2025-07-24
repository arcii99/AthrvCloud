//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MB 1048576 // 1 MB in bytes
#define KB 1024 // 1 KB in bytes

// Function to generate random internet speed
float generateRandomSpeed() {
    float speed = (rand() % 10) + 1; // Generate a random integer between 1 and 10
    return speed;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize variables
    int file_size = 50; // in MB
    float speed = generateRandomSpeed(); // in Mbps

    // Calculate download time
    float download_time = (file_size * MB) / (speed * MB / 8);

    // Convert download time into seconds, minutes and hours
    int hours = download_time / 3600;
    int minutes = (download_time - (hours * 3600)) / 60;
    int seconds = download_time - (hours * 3600) - (minutes * 60);

    // Print download details
    printf("Your internet speed is: %.2f Mbps\n", speed);
    printf("Downloading a %d MB file...\n", file_size);
    printf("Estimated download time: ");
    if (hours > 0) {
        printf("%d hour(s), ", hours);
    }
    if (minutes > 0) {
        printf("%d minute(s) and ", minutes);
    }
    printf("%d second(s).\n", seconds);

    return 0;
}