//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
/*
* Traffic Light Controller program
* Ken Thompson style example
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int green_time = 10;
    int yellow_time = 3;
    int red_time = 15;
    int total_time = green_time + yellow_time + red_time;

    for (int i = 1; i <= 5; i++) {
        printf("Cycle %d:\n", i);

        // Green light
        printf("Green light on for %d seconds.\n", green_time);
        for (int j = 1; j <= green_time; j++) {
            printf("%d ", j);
            fflush(stdout);  // flush output so it doesn't get buffered
            sleep(1);
        }
        printf("\n");

        // Yellow light
        printf("Yellow light on for %d seconds.\n", yellow_time);
        for (int j = 1; j <= yellow_time; j++) {
            printf("%d ", j);
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        // Red light
        printf("Red light on for %d seconds.\n", red_time);
        for (int j = 1; j <= red_time; j++) {
            printf("%d ", j);
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        printf("Total time for this cycle: %d seconds.\n\n", total_time);
    }

    return 0;
}