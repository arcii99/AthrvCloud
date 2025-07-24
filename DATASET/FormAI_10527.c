//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIGNAL_STRENGTH 100

int main() {

    int signal_strength;
    bool is_valid_signal_strength = false;

    do {
        printf("Please enter the signal strength in dBm (between 0 and 100): ");
        scanf("%d", &signal_strength);

        if (signal_strength >= 0 && signal_strength <= MAX_SIGNAL_STRENGTH) {
            is_valid_signal_strength = true;
        }
        else {
            printf("Invalid signal strength. Please enter a number between 0 and 100.\n");
        }
    } while (!is_valid_signal_strength);

    if (signal_strength == 0) {
        printf("No signal detected.\n");
    }
    else {
        printf("Signal strength: %d dBm\n", signal_strength);
        
        if (signal_strength >= 70) {
            printf("The signal is very strong.\n");
        }
        else if (signal_strength >= 50 && signal_strength < 70) {
            printf("The signal is strong.\n");
        }
        else if (signal_strength >= 30 && signal_strength < 50) {
            printf("The signal is weak.\n");
        }
        else {
            printf("The signal is very weak.\n");
        }
    }

    return EXIT_SUCCESS;
}