//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength[10];
    int i,j;
    srand(time(0));
    printf("Analyzing Wi-Fi signal strengths...\n");
    for(i = 0; i < 10; i++) {
        signal_strength[i] = rand() % 101;
        printf("Signal strength %d: %d%%\n", i+1, signal_strength[i]);
    }
    printf("\nCalculating average signal strength...\n");
    int sum = 0;
    for(i = 0; i < 10; i++) {
        sum += signal_strength[i];
    }
    int average_strength = sum / 10;
    printf("Average signal strength: %d%%\n\n", average_strength);
    printf("Determining signal quality...\n");
    for(i = 0; i < 10; i++) {
        printf("Signal %d: ", i+1);
        if(signal_strength[i] >= 75) {
            printf("Excellent\n");
        }
        else if(signal_strength[i] >= 50) {
            printf("Good\n");
        }
        else if(signal_strength[i] >= 25) {
            printf("Fair\n");
        }
        else {
            printf("Poor\n");
        }
    }   
    return 0;
}