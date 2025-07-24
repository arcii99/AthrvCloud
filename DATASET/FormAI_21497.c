//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define NUMBER_OF_SAMPLES 100

int main(void) {
    int samples[NUMBER_OF_SAMPLES];
    int max_strength = MIN_SIGNAL_STRENGTH;
    int min_strength = MAX_SIGNAL_STRENGTH;
    int total_strength = 0;
    int avg_strength = 0;

    // Seed the random number generator with current time
    srand(time(0));

    // Generate random signal strengths and store them in the samples array
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
        samples[i] = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
        
        // Update min and max strength values
        if (samples[i] > max_strength) {
            max_strength = samples[i];
        }
        if (samples[i] < min_strength) {
            min_strength = samples[i];
        }
        
        // Add current strength to the total strength
        total_strength += samples[i];
    }

    // Calculate the average strength
    avg_strength = total_strength / NUMBER_OF_SAMPLES;

    // Print the results
    printf("Maximum signal strength:\t%d\n", max_strength);
    printf("Minimum signal strength:\t%d\n", min_strength);
    printf("Average signal strength:\t%d\n", avg_strength);

    return 0;
}