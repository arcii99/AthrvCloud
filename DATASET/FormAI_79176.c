//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength = 0;
    srand(time(NULL));
    // generate random signal strength between 0 and 100
    signal_strength = rand() % 101;
    printf("Current Wi-Fi Signal Strength: %d\n", signal_strength);
    if (signal_strength >= 75) {
        printf("Signal Strength: Excellent\n");
    } else if (signal_strength >= 50) {
        printf("Signal Strength: Good\n");
    } else if (signal_strength >= 25) {
        printf("Signal Strength: Fair\n");
    } else {
        printf("Signal Strength: Poor\n");
    }
    return 0;
}