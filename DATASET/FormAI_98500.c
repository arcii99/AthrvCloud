//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define MAX_NUM_OF_TESTS 10

int wifi_signal_strength(void);

int main(void)
{
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_NUM_OF_TESTS; i++) {
        printf("Test %d\tSignal strength: %d%%\n", i + 1, wifi_signal_strength());
    }

    return 0;
}

int wifi_signal_strength(void)
{
    static int prev_strength = -1;
    int strength;

    while ((strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH) != prev_strength);

    prev_strength = strength;

    return strength;
}