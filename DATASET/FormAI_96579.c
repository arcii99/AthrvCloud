//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random signal strength values
int generate_signal_strength() {
    int signal_strength = rand() % 101;
    return signal_strength;
}

// Function to print the Wi-Fi signal strength analyzer report
void print_report(int signal_strength) {
    printf("Wi-Fi Signal Strength Analyzer Report:\n");
    printf("-------------------------------------\n");
    printf("Signal Strength: %d%%\n", signal_strength);
    if (signal_strength >= 70) {
        printf("Signal strength is excellent!\n");
    } else if (signal_strength >= 50 && signal_strength < 70) {
        printf("Signal strength is good.\n");
    } else if (signal_strength >= 30 && signal_strength < 50) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }
}

// Main function
int main() {
    // Generate a random seed
    srand(time(NULL));
    
    // Generate a random signal strength value
    int signal_strength = generate_signal_strength();
    
    // Print the Wi-Fi signal strength analyzer report
    print_report(signal_strength);
    
    return 0;
}