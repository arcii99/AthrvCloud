//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define NUM_TESTS 5
#define MAX_SPEED 1000

// function to simulate internet speed test
int test_speed() {
    // generate random speed between 0 and MAX_SPEED
    int speed = rand() % (MAX_SPEED + 1);
    return speed;
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize variables
    int speeds[NUM_TESTS];
    int total_speed = 0;
    float avg_speed;

    // run speed tests
    for (int i = 0; i < NUM_TESTS; i++) {
        speeds[i] = test_speed();
        total_speed += speeds[i];
        printf("Test %d: %d Mbps\n", i+1, speeds[i]);
    }

    // calculate average speed
    avg_speed = (float) total_speed / NUM_TESTS;

    // print results
    printf("\nAverage speed: %.2f Mbps\n", avg_speed);

    return 0;
}