//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MIN_DBM -100
#define MAX_DBM -40
#define NUM_READINGS 10

int main(void) {
    int readings[NUM_READINGS];
    int total = 0;
    int average;
    int i;
    srand(time(NULL));

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("=============================\n");

    for (i = 0; i < NUM_READINGS; i++) {
        readings[i] = rand() % (MAX_DBM - MIN_DBM + 1) + MIN_DBM;
        total += readings[i];
        printf("Reading #%d: %d dBm\n", i+1, readings[i]);
        sleep(1);
    }

    average = total / NUM_READINGS;
    printf("Average signal strength: %d dBm\n", average);

    if (average >= -50) {
        printf("Signal strength is excellent.\n");
    } else if (average >= -70) {
        printf("Signal strength is good.\n");
    } else if (average >= -80) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }

    return 0;
}