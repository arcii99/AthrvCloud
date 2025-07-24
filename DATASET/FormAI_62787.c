//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BARS 10 // Maximum number of bars to display
#define MAX_SIGNAL 100 // Maximum signal strength

void print_bars(int signal_strength);

int main(int argc, char* argv[]) {
    int signal_strength = 0;
    int n = 0;
    char input[10] = "";

    // Prompt user for signal strength
    printf("Enter signal strength (0-100): ");
    fgets(input, 10, stdin);
    signal_strength = atoi(input);

    // Validate input
    if (signal_strength < 0 || signal_strength > 100) {
        printf("Invalid input. Please enter a value between 0 and 100.\n");
        return 1; // Exit program with error status
    }

    // Calculate number of bars to display
    n = signal_strength / (MAX_SIGNAL / MAX_BARS);

    // Print bars
    print_bars(n);

    return 0;
}

void print_bars(int signal_strength) {
    int i = 0;

    printf("[");
    for (i = 0; i < MAX_BARS; i++) {
        if (i < signal_strength) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] (%d%%)\n", signal_strength * (MAX_SIGNAL / MAX_BARS));
}