//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator
    int i, j, k, delay;

    while (1) {
        // Set phase 1 (Green Light)
        printf("Cars heading South and North may proceed\n");
        printf("Cars heading East and West should stop\n");
        for (i = 10; i > 0; i--) {
            printf("Green  :    %d\n", i);
            delay = rand() % 2 + 1; // Generate random delay between 1-2 seconds
            sleep(delay);
        }

        // Set phase 2 (Yellow Light)
        printf("Cars heading South and North should prepare to stop\n");
        printf("Cars heading East and West should prepare to proceed\n");
        for (j = 3; j > 0; j--) {
            printf("Yellow :    %d\n", j);
            sleep(1);
        }

        // Set phase 3 (Red Light)
        printf("Cars heading South and North should stop\n");
        printf("Cars heading East and West may proceed\n");
        for (k = 15; k > 0; k--) {
            printf("Red    :    %d\n", k);
            delay = rand() % 2 + 1; // Generate random delay between 1-2 seconds
            sleep(delay);
        }

        // Set phase 4 (Yellow Light)
        printf("Cars heading South and North should prepare to proceed\n");
        printf("Cars heading East and West should prepare to stop\n");
        for (j = 3; j > 0; j--) {
            printf("Yellow :    %d\n", j);
            sleep(1);
        }
    }
    return 0;
}