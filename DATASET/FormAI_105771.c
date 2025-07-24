//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random signal strength value
int generate_signal_strength() {
    return rand() % 101; // return a value between 0 and 100 (inclusive)
}

// function to analyze the signal strength and classify it into categories
void analyze_signal_strength(int signal_strength) {
    if (signal_strength >= 80) {
        printf("Excellent signal strength\n");
    } else if (signal_strength >= 60) {
        printf("Good signal strength\n");
    } else if (signal_strength >= 40) {
        printf("Average signal strength\n");
    } else {
        printf("Poor signal strength\n");
    }
}

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // generate random signal strength values and analyze them
    int signal_strength;
    for (int i = 0; i < 10; i++) {
        signal_strength = generate_signal_strength();
        printf("Signal strength: %d\n", signal_strength);
        analyze_signal_strength(signal_strength);
        printf("\n");
    }
    
    return 0;
}