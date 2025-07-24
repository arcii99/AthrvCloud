//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random signal strength value
int generate_signal_strength() {
    return rand() % 100 + 1; // Generate a random value between 1-100
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define an array to store the signal strength values
    int signal_strengths[10];

    // Generate 10 random signal strength values and store them in the array
    for (int i = 0; i < 10; i++) {
        signal_strengths[i] = generate_signal_strength();
    }

    // Print the signal strength values
    printf("Signal Strength Analyzer\n\n");
    for (int i = 0; i < 10; i++) {
        printf("Signal Strength: %d\n", signal_strengths[i]);
    }

    // Calculate the average signal strength
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += signal_strengths[i];
    }
    int avg = sum / 10;

    // Determine the overall signal strength
    char* overall_strength;
    if (avg >= 90) {
        overall_strength = "Excellent";
    } else if (avg >= 70 && avg < 90) {
        overall_strength = "Good";
    } else if (avg >= 50 && avg < 70) {
        overall_strength = "Fair";
    } else {
        overall_strength = "Weak";
    }

    // Print the average and overall signal strength
    printf("\nAverage Signal Strength: %d\nOverall Signal Strength: %s\n", avg, overall_strength);

    return 0;
}