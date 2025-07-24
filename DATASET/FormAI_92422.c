//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for signal strength
#define EXCELLENT 80
#define GOOD 60
#define AVERAGE 40
#define POOR 20

int main() {
    // Seed random number generator with current time
    srand((unsigned) time(NULL));

    int signal_strength = 0;

    // Print retro style header
    printf("*******************************************\n");
    printf("***** Wi-Fi Signal Strength Analyzer *****\n");
    printf("*******************************************\n\n");

    // Generate random signal strength for demonstration purposes
    signal_strength = rand() % 101;

    // Print signal strength and interpretation in retro style
    printf("Current signal strength: %d%%\n", signal_strength);
    printf("  |");
    if (signal_strength >= EXCELLENT) {
        printf("OOOOO");
    } else if (signal_strength >= GOOD) {
        printf("OOOO_");
    } else if (signal_strength >= AVERAGE) {
        printf("OOO__");
    } else if (signal_strength >= POOR) {
        printf("OO___");
    } else {
        printf("O____");
    }
    printf("|\n");
    printf("  |");
    if (signal_strength >= EXCELLENT) {
        printf("OOOOO");
    } else if (signal_strength >= GOOD) {
        printf("_OOOO");
    } else if (signal_strength >= AVERAGE) {
        printf("__OOO");
    } else if (signal_strength >= POOR) {
        printf("___OO");
    } else {
        printf("____O");
    }
    printf("|\n");
    printf("  |");
    if (signal_strength >= EXCELLENT) {
        printf("OOOOO");
    } else if (signal_strength >= GOOD) {
        printf("__OOO");
    } else if (signal_strength >= AVERAGE) {
        printf("___OO");
    } else if (signal_strength >= POOR) {
        printf("____O");
    } else {
        printf("_____");
    }
    printf("|\n");
    printf("  |");
    if (signal_strength >= EXCELLENT) {
        printf("OOOOO");
    } else if (signal_strength >= GOOD) {
        printf("___OO");
    } else if (signal_strength >= AVERAGE) {
        printf("____O");
    } else {
        printf("_____");
    }
    printf("|\n");
    printf("  |");
    if (signal_strength >= EXCELLENT) {
        printf("OOOOO");
    } else if (signal_strength >= GOOD) {
        printf("____O");
    } else {
        printf("_____");
    }
    printf("|\n\n");

    // Print interpretation of signal strength in retro style
    printf("Interpretation:\n");
    if (signal_strength >= EXCELLENT) {
        printf("Excellent signal strength!\n");
    } else if (signal_strength >= GOOD) {
        printf("Good signal strength.\n");
    } else if (signal_strength >= AVERAGE) {
        printf("Average signal strength.\n");
    } else if (signal_strength >= POOR) {
        printf("Poor signal strength.\n");
    } else {
        printf("No signal.\n");
    }

    return 0;
}