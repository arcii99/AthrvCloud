//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int strength = rand() % 101; // generate random strength value from 0-100
    char* signal;

    if (strength >= 90) {
        signal = "towering";
    } else if (strength >= 70) {
        signal = "strong";
    } else if (strength >= 50) {
        signal = "acceptable";
    } else if (strength >= 30) {
        signal = "weak";
    } else if (strength >= 10) {
        signal = "faint";
    } else {
        signal = "non-existent";
    }

    printf("Thou art using a Wi-Fi connection of %d%% strength. Verily, it is %s.\n", strength, signal);

    return 0;
}