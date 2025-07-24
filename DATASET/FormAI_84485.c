//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define DEFAULT_TEST_SIZE 50

// Test function that simulates network speed by waiting for random amount of time
double networkTest() {
    int waitTime = rand() % 100 + 10; // Simulate network delay of 10-110 ms
    double result = (double) rand() / RAND_MAX; // Random value between 0 and 1
    printf("Waiting for %dms...\n", waitTime);
    usleep(waitTime * 1000); // Wait for specified number of milliseconds
    return result;
}

// Function that performs speed test and returns average speed in Mb/s
double speedTest(int testSize) {
    double sum = 0.0;
    printf("Performing speed test with %d iterations...\n", testSize);
    for (int i = 0; i < testSize; i++) {
        double result = networkTest();
        sum += result;
        printf("Test %d: %.2f Mb/s\n", i+1, result*100);
    }
    double avgSpeed = (sum / testSize) * 100;
    printf("Average speed: %.2f Mb/s\n", avgSpeed);
    return avgSpeed;
}

int main(int argc, char** argv) {
    srand(time(NULL)); // Seed random number generator
    
    int testSize = DEFAULT_TEST_SIZE; // Set default number of iterations
    if (argc > 1) { // Check if command line arguments were provided
        testSize = atoi(argv[1]); // Convert input argument to integer
        if (testSize <= 0) { // Check if input is valid
            printf("Invalid input: %s\n", argv[1]);
            return 1;
        }
    }
    
    // Perform speed test and output result
    double avgSpeed = speedTest(testSize);
    printf("Speed test complete. Average speed: %.2f Mb/s\n", avgSpeed);
    
    return 0;
}