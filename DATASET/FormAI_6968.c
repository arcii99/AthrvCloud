//FormAI DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int max_time = 10; // max time to wait for response in seconds
    int response_received = 0;

    printf("Preparing to send galactic ping...\n");

    sleep(2); // simulate preparation

    printf("Sending signal...\n");

    // simulate signal travel time across lightyears
    int travel_time = (rand() % 10) + 1; // between 1 and 10 seconds
    sleep(travel_time);

    printf("Signal received.\n");

    // simulate random chance of response
    int response_chance = rand() % 10; // between 0 and 9
    if (response_chance < 5) { // 50% chance of response
        response_received = 1;
        printf("Response received after %d seconds.\n", travel_time);
    } else {
        printf("No response received after %d seconds.\n", max_time);
    }

    return 0;
}