//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h> // for rand() function

int main() {
    int probability = rand() % 101; // Generate random number between 0-100
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Based on our calculations, the probability of an alien invasion today is %d%%\n", probability);

    if (probability == 0) {
        printf("There is no chance of an alien invasion today. We are safe!\n");
    } else if (probability < 50) {
        printf("The probability of an alien invasion is low, but not impossible. Keep your eyes to the skies!\n");
    } else if (probability < 80) {
        printf("The probability of an alien invasion is moderate. We should take precautions.\n");
    } else if (probability < 95) {
        printf("The probability of an alien invasion is high. We need to prepare ourselves for the worst.\n");
    } else {
        printf("The probability of an alien invasion is extremely high! Brace yourselves for impact!\n");
    }

    return 0;
}