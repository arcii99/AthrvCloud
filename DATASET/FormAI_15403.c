//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

void print_signal_strength(int signal_strength) {
    int i;
    printf("\nSignal Strength: %d%% [", signal_strength);
    int num_filled_blocks = signal_strength / 10;
    for(i = 0; i < num_filled_blocks; i++) {
        printf("█");
    }
    for(i = num_filled_blocks; i < 10; i++) {
        printf("░");
    }
    printf("]\n");
}

double calculate_distance_from_signal_strength(int signal_strength) {
    double distance = pow(10, ((27.55 - (20 * log10(2400)) + fabs(signal_strength)) / 20.0));
    return distance;
}

int main() {
    char ssid[20] = "Turing Wi-Fi";
    int signal_strength = 65;
    double distance = calculate_distance_from_signal_strength(signal_strength);

    printf("Connecting to SSID: %s\n", ssid);
    print_signal_strength(signal_strength);
    printf("Distance from Access Point: %f meters\n", distance);

    return 0;
}