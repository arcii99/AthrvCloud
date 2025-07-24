//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0

int main() {
    int signal_strength;

    // Infinite Loop
    while(1) {
        // Simulate Wi-Fi Signal Strength
        signal_strength = rand() % (MAX_SIGNAL - MIN_SIGNAL + 1) + MIN_SIGNAL;

        // Print Signal Strength
        printf("Wi-Fi Signal Strength: %d%%\n", signal_strength);

        // Determine Signal Quality and Print
        if(signal_strength >= 70) {
            printf("Signal Quality: Excellent\n\n");
        } else if(signal_strength >= 50) {
            printf("Signal Quality: Good\n\n");
        } else if(signal_strength >= 30) {
            printf("Signal Quality: Fair\n\n");
        } else {
            printf("Signal Quality: Poor\n\n");
        }

        // Simulate Delay
        int delay = rand() % 10 + 1;
        sleep(delay);
    }

    return 0;
}