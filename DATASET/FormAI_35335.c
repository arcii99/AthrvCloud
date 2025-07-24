//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // For randomness of probability

    float alien_probability = (float) rand() / (float) RAND_MAX; // Range: 0.0 - 1.0
    float invasion_probability = pow(alien_probability, 3); // Example probability formula

    printf("The probability of an alien invasion is: %f%%\n", invasion_probability * 100);

    return 0;
}