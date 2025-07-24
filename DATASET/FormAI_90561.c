//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to generate random speed in Mbps
int generateSpeed() {
    return (rand() % 100) + 1;
}

// Function to simulate internet speed test and return result in Mbps
int internetSpeedTest() {
    printf("Starting internet speed test...\n");
    sleep(2); // Simulating network delay
    int speed = generateSpeed();
    printf("Your internet speed is %d Mbps.\n", speed);
    return speed;
}

int main() {
    srand(time(NULL)); // Initializing random number generator
    
    int speed = internetSpeedTest();
    
    // Checking the speed against standard values
    if (speed >= 50) {
        printf("Your internet speed is excellent!\n");
    } else if (speed >= 25) {
        printf("Your internet speed is good.\n");
    } else if (speed >= 10) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is below average.\n");
    }
    
    return 0;
}