//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate internet speed test
float speedTest() {
    // Generate random integers between 1 and 1000 to simulate download and upload speed
    int downloadSpeed = rand() % 1000 + 1;
    int uploadSpeed = rand() % 1000 + 1;

    // Calculate the average speed
    float avgSpeed = (downloadSpeed + uploadSpeed) / 2.0;

    return avgSpeed;
}

int main() {
    // Set the seed for random number generator
    srand(time(NULL));

    // Call speedTest function to get the average speed
    float speed = speedTest();
    
    // Print the speed to the console
    printf("Your internet speed is: %.2f Mbps", speed);

    return 0;
}