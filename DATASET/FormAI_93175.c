//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main() {
    char network_name[20];
    int signal_strength;

    printf("Enter the network name: ");
    scanf("%s", network_name);

    // Generate random signal strength between 0 and 100
    srand(time(NULL));
    signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;

    printf("\nAnalyzing Wi-Fi signal strength for network %s...\n", network_name);
    printf("Signal strength: %d\n", signal_strength);

    // Analyze signal strength
    if (signal_strength >= 80) {
        printf("Signal strength is excellent!\n");
    } else if (signal_strength >= 60) {
        printf("Signal strength is good.\n");
    } else if (signal_strength >= 40) {
        printf("Signal strength is fair.\n");
    } else if (signal_strength >= 20) {
        printf("Signal strength is poor.\n");
    } else {
        printf("Signal strength is very poor.\n");
    }

    return 0;
}