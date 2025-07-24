//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int internetSpeed;
    time_t currentTime;
    int totalTime = 0;
    int count = 0;

    // Set seed for random number generation
    srand(time(NULL));

    // Get current time
    time(&currentTime);

    // Welcome message
    printf("Welcome to the Internet Speed Test Application!\n\n");

    // Loop through 5 speed tests
    for (int i = 1; i <= 5; i++) {
        // Generate random internet speed between 1 and 100 Mbps
        internetSpeed = rand() % 100 + 1;
        printf("Speed Test %d: %d Mbps\n", i, internetSpeed);

        // Add speed test time to total time
        totalTime += time(NULL) - currentTime;

        // Update current time for next speed test
        time(&currentTime);

        // Increase count of completed speed tests
        count++;
    }

    // Calculate average speed test time
    double avgTime = totalTime / (double)count;

    // Display results
    printf("\n-------------------------\n");
    printf("Speed Test Results:\n");
    printf("-------------------------\n");
    printf("Total Time Taken: %d seconds\n", totalTime);
    printf("Average Time per Test: %.2lf seconds\n", avgTime);
    printf("Thank you for using the Internet Speed Test Application!\n");

    return 0;
}