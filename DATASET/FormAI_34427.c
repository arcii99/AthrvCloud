//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate async task
void simulateAsyncTask() {
    // generate a random number between 1 and 5 to simulate delay
    int delay = rand() % 5 + 1;
    printf("Async task started\n");
    printf("Waiting for %d seconds...\n", delay);
    // sleep for 'delay' seconds to simulate async task
    sleep(delay);
    printf("Async task completed\n");
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    // start the space adventure
    printf("*** Welcome to Procedural Space Adventure ***\n");
    printf("You are a space explorer on a mission to discover new planets\n");
    printf("Launching...\n");
    // simulate async task
    simulateAsyncTask();
    // arrive at first planet
    printf("Arrived at planet 1...\n");
    // simulate async task
    simulateAsyncTask();
    // collect samples from first planet
    printf("Collecting samples from planet 1...\n");
    // simulate async task
    simulateAsyncTask();
    // analyze samples from first planet
    printf("Analyzing samples from planet 1...\n");
    // simulate async task
    simulateAsyncTask();
    // arrive at second planet
    printf("Arrived at planet 2...\n");
    // simulate async task
    simulateAsyncTask();
    // collect samples from second planet
    printf("Collecting samples from planet 2...\n");
    // simulate async task
    simulateAsyncTask();
    // analyze samples from second planet
    printf("Analyzing samples from planet 2...\n");
    // simulate async task
    simulateAsyncTask();
    // return to Earth
    printf("Mission completed! Returning to Earth...\n");
    // simulate async task
    simulateAsyncTask();
    // end the adventure
    printf("*** Procedural Space Adventure ended ***\n");
    return 0;
}