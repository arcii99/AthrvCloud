//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int red = 1, yellow = 2, green = 3;
    int signal;
    srand(time(NULL)); // Seed the random number generator with current time

    while(1) {
        signal = rand() % 3 + 1; // Get a random number between 1 and 3
        switch(signal) {
            case 1: // Red light
                printf("STOP\n");
                sleep(5); // Wait for 5 seconds
                break;
            case 2: // Yellow light
                printf("Prepare to stop\n");
                sleep(3); // Wait for 3 seconds
                break;
            case 3: // Green light
                printf("GO\n");
                sleep(7); // Wait for 7 seconds
                break;
        }
    }

    return 0;
}