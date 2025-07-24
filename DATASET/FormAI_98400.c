//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a post-apocalyptic style Internet Speed Test Application.
// It simulates a test of internet speed in an environment with limited resources, where the connection speed is crucial for survival.

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int download_speed = rand() % 10 + 1; // Obtain a random download speed from 1 to 10 Mbps
    int upload_speed = rand() % 5 + 1; // Obtain a random upload speed from 1 to 5 Mbps

    printf("Welcome to the post-apocalyptic Internet Speed Test!\n");
    printf("Your connection download speed is: %d Mbps\n", download_speed);
    printf("Your connection upload speed is: %d Mbps\n", upload_speed);

    // Check if the download and upload speeds are above critical levels
    if (download_speed >= 5 && upload_speed >= 3) {
        printf("Congratulations, your internet connection is fast enough to survive in the post-apocalyptic world!\n");
    }
    else {
        printf("Your internet connection is too slow to survive in the post-apocalyptic world. Please upgrade your connection before it's too late!\n");
    }

    return 0;
}