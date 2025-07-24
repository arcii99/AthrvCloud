//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int generate_random(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// main function
int main() {
    srand(time(NULL)); // initialize random seed

    int traffic_light = generate_random(1, 3); // generate random number for traffic light
    int time_remaining = generate_random(10, 30); // generate random number for time remaining

    // print initial status
    printf("Traffic light: %d\n", traffic_light);
    printf("Time remaining: %d\n", time_remaining);

    // loop until time remaining is zero
    while (time_remaining > 0) {
        // check traffic light and update time remaining accordingly
        switch (traffic_light) {
            case 1: // green light
                printf("Green light - proceed with caution\n");
                time_remaining -= generate_random(5, 10);
                break;
            case 2: // yellow light
                printf("Yellow light - slow down\n");
                time_remaining -= generate_random(2, 5);
                break;
            case 3: // red light
                printf("Red light - stop\n");
                time_remaining -= generate_random(15, 25);
                break;
        }

        // generate new random number for traffic light
        traffic_light = generate_random(1, 3);

        // print updated status
        printf("Traffic light: %d\n", traffic_light);
        printf("Time remaining: %d\n", time_remaining);
    }

    printf("Time is up - program exiting\n");

    return 0;
}