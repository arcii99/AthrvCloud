//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");

    // Get current time
    time_t start_time = time(NULL);

    // Sleep for random time between 3-10 seconds to simulate internet speed test
    srand(time(NULL));
    int sleep_time = rand() % 8 + 3;
    printf("Simulating internet speed test...\n");
    sleep(sleep_time);

    // Get current time after sleep
    time_t end_time = time(NULL);

    // Calculate internet speed
    double speed = (double) (rand() % 90 + 10); // Generate random speed between 10-100 Mbps

    // Print results
    double time_taken = difftime(end_time, start_time);
    printf("Your internet speed is: %.2f Mbps\n", speed);
    printf("Time taken to complete speed test: %.0f seconds\n", time_taken);

    return 0;
}