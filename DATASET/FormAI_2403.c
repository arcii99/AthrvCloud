//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
// Retro style Wi-Fi Signal Strength Analyzer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    printf("Retro Wi-Fi Signal Strength Analyzer\n\n");
    printf("Scanning...\n");

    int strength = rand() % 100; // simulate Wi-Fi signal strength with a random number between 0 and 99
    printf("Signal strength: %d%%\n", strength);

    if (strength >= 80) {
        printf("Signal strength is excellent!\n");
    } else if (strength >= 60) {
        printf("Signal strength is good.\n");
    } else if (strength >= 40) {
        printf("Signal strength is fair.\n");
    } else if (strength >= 20) {
        printf("Signal strength is poor.\n");
    } else {
        printf("Signal strength is very poor.\n");
    }

    printf("\nThank you for using Retro Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}