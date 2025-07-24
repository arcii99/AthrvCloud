//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int threshold = 70; // Probability threshold in percentage
    
    // Generate random value between 0 and 100
    srand(time(NULL));
    int probability = rand() % 101;
    
    printf("Alien invasion probability: %d%%\n", probability);
    
    if (probability >= threshold) {
        printf("Alien invasion is likely to happen.\n");
    } else {
        printf("Alien invasion is unlikely to happen.\n");
    }
    
    return 0;
}