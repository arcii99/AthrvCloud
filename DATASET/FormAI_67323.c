//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    int invasion_prob = rand() % 101; // Generate random number between 0 and 100
    printf("The probability of an alien invasion is %d%%\n", invasion_prob);

    if (invasion_prob >= 50) {
        printf("ALERT! There is a high probability of an alien invasion. Please take precautions.\n");
    } else {
        printf("The probability of an alien invasion is low. No need to panic.\n");
    }

    return 0;
}