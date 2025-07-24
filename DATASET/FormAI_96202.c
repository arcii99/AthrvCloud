//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int calories = 0, steps = 0, min = 0, sec = 0;

    time_t start, end;
    double time_taken;

    // get current time
    time(&start);

    printf("Starting Fitness Tracker...\n");

    // loop for 10 minutes
    while (time_taken < 600) {
        // generate random number of steps
        int new_steps = rand() % 500;

        // calculate calories burned
        calories += new_steps / 20;

        // update total steps
        steps += new_steps;

        // update time elapsed
        time(&end);
        time_taken = difftime(end, start);

        // display progress every minute
        if (time_taken > min * 60) {
            printf("\n--------------------\n");
            printf("Time: %d:%d\n", min, sec);
            printf("Steps: %d\n", steps);
            printf("Calories Burned: %d\n", calories);
            printf("--------------------\n");
            min++;
        }

        // wait one second before looping again
        sleep(1);
        sec++;
    }

    printf("\nSession complete!\n");

    return 0;
}