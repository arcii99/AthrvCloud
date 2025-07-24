//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ALIEN INVASION PROBABILITY CALCULATOR */

float calculateProbability(int n) {
    int i;
    float probability = 0.0;
    float factor = 0.5;
    float numerator = 1.0;
    float denominator = 1.0;

    for (i = 1; i <= n; i++) {
        numerator *= i;
        denominator *= factor;
        probability += numerator / denominator;
        factor += 1.0;
    }

    return probability;
}

int main() {
    int years;
    float probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of years you want to calculate the probability for: ");
    scanf("%d", &years);

    probability = calculateProbability(years);

    printf("The probability of an alien invasion in %d years is: %f\n", years, probability);

    return 0;
}