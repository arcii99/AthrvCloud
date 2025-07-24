//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    // Define signal strength levels
    int excellent = 80;
    int good = 60;
    int fair = 40;
    int poor = 20;
    
    // Define array of signal strength readings
    int signal_strength[5];
    
    // Generate random signal strength values between 0 and 100
    for (int i = 0; i < 5; i++) {
        signal_strength[i] = rand() % 101;
    }
    
    // Output signal strength readings and corresponding levels
    printf("Signal Strength Readings:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", signal_strength[i]);
    }
    printf("\n");
    printf("Signal Strength Levels:\n");
    for (int i = 0; i < 5; i++) {
        if (signal_strength[i] >= excellent) {
            printf("Excellent\n");
        } else if (signal_strength[i] >= good) {
            printf("Good\n");
        } else if (signal_strength[i] >= fair) {
            printf("Fair\n");
        } else if (signal_strength[i] >= poor) {
            printf("Poor\n");
        } else {
            printf("No Signal\n");
        }
    }
    
    return 0;
}