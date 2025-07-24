//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIGNALS 100 // Maximum number of signals to analyze
#define MIN_SIGNAL_STRENGTH 0 // Minimum signal strength
#define MAX_SIGNAL_STRENGTH 100 // Maximum signal strength
#define MIN_SIGNAL_DISTANCE 0 // Minimum signal distance
#define MAX_SIGNAL_DISTANCE 1000 // Maximum signal distance

struct signal {
    float x; // X coordinate of the signal location
    float y; // Y coordinate of the signal location
    int strength; // Strength of the signal (0-100)
} signals[MAX_SIGNALS];

int main() {
    int num_signals; // Number of signals to analyze
    printf("Enter the number of signals to analyze (1-100): ");
    scanf("%d", &num_signals);

    // Validate number of signals
    if(num_signals < 1 || num_signals > MAX_SIGNALS) {
        printf("Invalid number of signals.\n");
        return 1;
    }

    // Get signal info
    printf("\nEnter the signal information:\n");
    for(int i = 0; i < num_signals; i++) {
        printf("Signal %d:\n", i+1);
        printf("X: ");
        scanf("%f", &signals[i].x);
        printf("Y: ");
        scanf("%f", &signals[i].y);
        printf("Signal Strength (0-100): ");
        scanf("%d", &signals[i].strength);

        // Validate signal strength and distance
        if(signals[i].strength < MIN_SIGNAL_STRENGTH || signals[i].strength > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength.\n");
            return 1;
        }
        float distance = sqrt(pow(signals[i].x, 2) + pow(signals[i].y, 2));
        if(distance < MIN_SIGNAL_DISTANCE || distance > MAX_SIGNAL_DISTANCE) {
            printf("Invalid signal distance.\n");
            return 1;
        }
    }

    // Analyze signal strength and location
    printf("\nAnalyzing signals...\n");
    float total_strength = 0;
    float x_sum = 0;
    float y_sum = 0;
    for(int i = 0; i < num_signals; i++) {
        total_strength += signals[i].strength; // Calculate total strength
        x_sum += signals[i].x * signals[i].strength; // Calculate weighted X sum
        y_sum += signals[i].y * signals[i].strength; // Calculate weighted Y sum
    }
    float avg_x = x_sum / total_strength; // Calculate average X
    float avg_y = y_sum / total_strength; // Calculate average Y
    printf("\nResult:\n");
    printf("Average Signal Location: (%.2f, %.2f)\n", avg_x, avg_y);
    printf("Average Signal Strength: %.2f\n", total_strength / num_signals);

    return 0;
}