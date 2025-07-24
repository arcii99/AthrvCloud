//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define THRESHOLD 50

int get_random_signal_strength() {
    int signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
    return signal_strength;
}

void find_strength_range(int signal_strength) {
    if (signal_strength > THRESHOLD) {
        printf("The Wi-Fi signal strength is strong.\n");
    } else {
        printf("The Wi-Fi signal strength is weak.\n");
    }
}

int main() {
    srand(time(NULL)); // initialize random seed

    int signal_strength = get_random_signal_strength();

    printf("Current Wi-Fi signal strength: %d\n", signal_strength);

    find_strength_range(signal_strength);

    return 0;
}