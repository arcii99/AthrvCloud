//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_SIGNAL_STRENGTH 100

int wifi_signal_strength[MAX_WIFI_SIGNAL_STRENGTH];
int current_signal_strength;
int average_signal_strength;

void analyze_signal_strength(int num_samples) {
    current_signal_strength = rand() % 100;
    wifi_signal_strength[num_samples] = current_signal_strength;
    int total_signal_strength = 0;
    for (int i = 0; i <= num_samples; i++) {
        total_signal_strength += wifi_signal_strength[i];
    }
    average_signal_strength = total_signal_strength / (num_samples + 1);
    printf("Current signal strength: %d\n", current_signal_strength);
    printf("Average signal strength: %d\n", average_signal_strength);
}

int main(void) {
    memset(wifi_signal_strength, 0, MAX_WIFI_SIGNAL_STRENGTH * sizeof(int));
    srand(time(NULL));
    int num_samples = 0;
    char input[10];
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("=====================================\n");
    printf("How many samples would you like to take? ");
    fgets(input, sizeof(input), stdin);
    num_samples = atoi(input);
    if (num_samples <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    for (int i = 1; i <= num_samples; i++) {
        printf("Sample #%d\n", i);
        analyze_signal_strength(i - 1);
    }
    return 0;
}