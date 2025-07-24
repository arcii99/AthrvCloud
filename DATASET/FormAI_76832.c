//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

// Constant Value
#define MAX_SIGNAL_LEVEL 100

// Function to scan signal
int scan_signal_level(void) {
    // Randomly Generate Signal Strength
    return rand() % (MAX_SIGNAL_LEVEL + 1);
}

int main(void) {
    int signal_strengths [5];
    // Loop through the signal strength array
    for(int i = 0; i < sizeof(signal_strengths) / sizeof(int); i++)
    {
        signal_strengths[i] = scan_signal_level();
    }
    printf("Scanning WiFi Signal Strengths:\n\n");
    for(int i = 0; i < sizeof(signal_strengths) / sizeof(int); i++)
    {
        printf("Signal Strength %d: %d%%\n", i+1, signal_strengths[i]);
    }

    // Analyze Signal Strengths
    printf("\nAnalyzing Signal Strengths...\n\n");

    int highest_signal_strength = 0;
    int lowest_signal_strength = MAX_SIGNAL_LEVEL;
    int total_signal_strength = 0;

    for(int i = 0; i < sizeof(signal_strengths) / sizeof(int); i++)
    {
        total_signal_strength += signal_strengths[i];
        if(signal_strengths[i] > highest_signal_strength)
        {
            highest_signal_strength = signal_strengths[i];
        }
        if(signal_strengths[i] < lowest_signal_strength)
        {
            lowest_signal_strength = signal_strengths[i];
        }
    }

    int average_signal_strength = total_signal_strength / (sizeof(signal_strengths) / sizeof(int));

    // Display Results
    printf("Highest Signal Strength: %d%%\n", highest_signal_strength);
    printf("Lowest Signal Strength: %d%%\n", lowest_signal_strength);
    printf("Average Signal Strength: %d%%\n", average_signal_strength);

    return 0;
}