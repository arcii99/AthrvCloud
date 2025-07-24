//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_READ_INTERVAL 1
#define TEMP_READ_DURATION 5

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int temp;
    int elapsed_time = 0;

    printf("Temperature Monitor starting...\n");

    while(elapsed_time < TEMP_READ_DURATION) {
        temp = rand() % (MAX_TEMP + 1 - MIN_TEMP) + MIN_TEMP; // Generate a random temperature between MIN_TEMP and MAX_TEMP
        printf("Temperature reading: %d C\n", temp);
        elapsed_time += TEMP_READ_INTERVAL; // Increment the elapsed time by the interval
        sleep(TEMP_READ_INTERVAL); // Pause the program for the interval duration
    }

    printf("Temperature Monitor shutting down...\n");

    return 0;
}