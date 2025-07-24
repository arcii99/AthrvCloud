//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int timeElapsed = 0;
    int greenTime, yellowTime, redTime;
    int remainingTime;

    // set the random seed based on current time
    srand(time(NULL));

    // generate random times for green, yellow and red lights
    greenTime = rand() % 61 + 30;
    yellowTime = rand() % 6 + 3;
    redTime = 90 - greenTime - yellowTime;

    // iterate for 10 time units
    for (int i = 1; i <= 10; i++) {

        // calculate remaining time
        remainingTime = timeElapsed % (greenTime + yellowTime + redTime);

        // output the state of the traffic light for the current time
        printf("Time elapsed: %d seconds\n", timeElapsed);
        if (remainingTime < greenTime) {
            printf("Green light\n");
        } else if (remainingTime < greenTime + yellowTime) {
            printf("Yellow light\n");
        } else {
            printf("Red light\n");
        }

        // increment the timeElapsed variable
        timeElapsed++;

        // wait for 1 second before moving to next iteration
        sleep(1);
    }

    return 0;
}