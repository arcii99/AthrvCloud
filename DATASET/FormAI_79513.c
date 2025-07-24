//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength, min_signal_strength = 0, max_signal_strength = 100;
    int num_samples, sample_count = 1;
    float average_strength = 0;
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    while(sample_count <= num_samples) {
        // Generate a random signal strength value within the range min_signal_strength and max_signal_strength
        signal_strength = (rand() % (max_signal_strength + 1 - min_signal_strength)) + min_signal_strength;
        printf("Sample %d - Signal strength: %d\n", sample_count, signal_strength);
        average_strength += (float)signal_strength / num_samples; // Calculate the running average
        sample_count++;
    }
    
    printf("\nAverage signal strength over %d samples: %.2f\n", num_samples, average_strength);
    if(average_strength < 60) {
        printf("The Wi-Fi signal strength is very weak!\n");
    }
    else if(average_strength < 80) {
        printf("The Wi-Fi signal strength is moderate.\n");
    }
    else {
        printf("The Wi-Fi signal strength is strong!\n");
    }
    
    return 0;
}