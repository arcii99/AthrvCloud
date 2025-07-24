//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 100000000 // Test size of 100MB
#define TEST_TIME 5 // Test duration of 5 seconds

int main() {

    // Seed random number generator
    srand(time(NULL));

    // Allocate test buffer
    char* buffer = (char*) malloc(TEST_SIZE);

    // Start the timer
    clock_t start = clock();

    // Begin the test
    while (clock() - start < TEST_TIME * CLOCKS_PER_SEC) {
        // Generate random data to fill the buffer
        for (int i = 0; i < TEST_SIZE; i++) {
            buffer[i] = rand() % 256;
        }
    }

    // Stop the timer and calculate the speed
    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    double speed = (double) TEST_SIZE * 8 / elapsed_time / 1000000;

    // Display the result
    printf("Speed test complete!\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Data size: %.2f MB (%.0f bytes)\n", (double) TEST_SIZE / 1000000, (double) TEST_SIZE);
    printf("Speed: %.2f Mbps\n", speed);

    // Free the buffer
    free(buffer);

    return 0;
}