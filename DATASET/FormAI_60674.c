//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the states of the traffic lights */
enum state { GREEN, YELLOW, RED };
enum state states[3] = { GREEN, YELLOW, RED };

/* Define the duration of each state */
int times[3] = { 10, 3, 15 };

int main()
{
    int i, j;

    printf("Starting traffic light controller...\n");

    while (1) {
        /* Display the current state of the traffic light */
        printf("\nTraffic Light Status:\n");
        for (i = 0; i < 3; i++) {
            printf("%sLight: %d%s\n", states[i] == GREEN ? "\033[1;32m" :
                                        states[i] == YELLOW ? "\033[1;33m" :
                                                              "\033[1;31m",
                   i + 1, "\033[0m");
        }

        /* Wait for the specified amount of time */
        sleep(times[states[0]]);

        /* Update the state of the traffic light */
        states[0] = (states[0] + 1) % 3;

        /* Randomize the duration of the yellow light */
        srand(time(NULL));
        times[1] = rand() % 6 + 2;

        /* Wait for the specified amount of time */
        sleep(times[states[0]]);

        /* Update the state of the traffic light */
        states[0] = (states[0] + 1) % 3;
    }

    return 0;
}