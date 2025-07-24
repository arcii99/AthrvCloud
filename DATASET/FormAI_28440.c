//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int num_simulations = 1000000;
    int num_success = 0;

    for (int i = 0; i < num_simulations; i++) {
        double r1 = (double)rand() / (double)RAND_MAX;
        double r2 = (double)rand() / (double)RAND_MAX;
        double r3 = (double)rand() / (double)RAND_MAX;
        double r4 = (double)rand() / (double)RAND_MAX;

        if (r1 < 0.05 && r2 < 0.02 && r3 < 0.005 && r4 < 0.001) {
            num_success++;
        }
    }

    double probability = (double)num_success / (double)num_simulations;

    printf("The probability of an alien invasion in the next year is %f%%\n", probability * 100);

    return 0;
}