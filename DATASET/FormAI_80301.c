//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength = 0;
    int min_strength = -100;
    int max_strength = 0;
    int average_strength = 0;
    int num_readings = 0;
    int sum_strengths = 0;
    int i;

    srand(time(NULL));

    printf("Starting Wi-Fi Signal Strength Analyzer...\n\n");

    for (i = 1; i <= 10; i++) {
        signal_strength = rand() % 101 - 100; // generating a random signal strength between -100 and 0

        printf("Reading #%d: Signal strength = %d dBm\n", i, signal_strength);

        if (signal_strength > max_strength) {
            max_strength = signal_strength;
        }

        if (signal_strength < min_strength) {
            min_strength = signal_strength;
        }

        sum_strengths += signal_strength;
        num_readings++;
    }

    average_strength = sum_strengths / num_readings;

    printf("\nTotal number of readings: %d\n", num_readings);
    printf("Maximum signal strength: %d dBm\n", max_strength);
    printf("Minimum signal strength: %d dBm\n", min_strength);
    printf("Average signal strength: %d dBm\n", average_strength);

    return 0;
}