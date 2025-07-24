//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    float probability, total_probability = 0;

    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("How many planets are in your solar system?\n");
    scanf("%d", &n);

    printf("Calculating probability for %d planets...\n", n);

    for (i = 1; i <= n; i++) {
        probability = ((float) rand() / RAND_MAX); // generate random probability
        
        printf("The probability of alien invasion on planet %d is %f\n", i, probability);

        total_probability += probability;
    }

    printf("The total probability of an alien invasion in your solar system is %f\n", total_probability);

    if (total_probability <= 0.5) {
        printf("Congratulations, your solar system is safe from alien invasion!\n");
    } else {
        printf("Warning: Your solar system has a high chance of being invaded by aliens. Please take necessary precautions.\n");
    }

    return 0;
}