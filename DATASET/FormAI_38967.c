//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define minimum and maximum signal strengths for classification
#define MIN_SIGNAL_STRENGTH 0
#define MAX_SIGNAL_STRENGTH 100
// Define signal strength categories
#define CATEGORY_EXCELLENT "Excellent"
#define CATEGORY_GOOD "Good"
#define CATEGORY_FAIR "Fair"
#define CATEGORY_POOR "Poor"
#define CATEGORY_NO_SIGNAL "No Signal"

int main() {
    // Declare variables
    int signal_strength;
    char* category;

    // Read signal strength value from user
    printf("Enter the Wi-Fi signal strength (between 0 and 100): ");
    scanf("%d", &signal_strength);

    // Classify the signal strength based on the defined categories
    if (signal_strength < MIN_SIGNAL_STRENGTH) {
        category = CATEGORY_NO_SIGNAL;
    } else if (signal_strength >= MIN_SIGNAL_STRENGTH && signal_strength <= 30) {
        category = CATEGORY_POOR;
    } else if (signal_strength > 30 && signal_strength <= 60) {
        category = CATEGORY_FAIR;
    } else if (signal_strength > 60 && signal_strength <= 80) {
        category = CATEGORY_GOOD;
    } else if (signal_strength > 80 && signal_strength <= MAX_SIGNAL_STRENGTH) {
        category = CATEGORY_EXCELLENT;
    } else {
        category = CATEGORY_NO_SIGNAL;
    }

    // Display the category result to the user
    printf("\nThe Wi-Fi signal strength is classified as: %s\n", category);

    return 0;
}