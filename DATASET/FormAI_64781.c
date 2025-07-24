//FormAI DATASET v1.0 Category: Date and time ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_WAIT_TIME 60 // In seconds

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Get the current time
    time_t now = time(NULL);
    printf("Current time: %s", ctime(&now));

    // Get a random wait time
    int wait_time = rand() % MAX_WAIT_TIME + 1;
    printf("Waiting for %d seconds...\n", wait_time);

    // Simulate waiting
    for(int i = 0; i < wait_time; i++) {
        printf(".");
        fflush(stdout); // Force the output to print
        sleep(1); // Wait for 1 second
    }

    // Get the new time
    now = time(NULL);
    printf("\n\nNew time: %s", ctime(&now));

    return 0;
}