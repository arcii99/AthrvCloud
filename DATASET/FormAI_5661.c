//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int num_of_aliens = rand() % 1000 + 1;
    int num_of_defenders = rand() % 500 + 1;
    int num_of_bases = rand() % 20 + 1;

    printf("Number of Aliens: %d\n", num_of_aliens);
    printf("Number of Defenders: %d\n", num_of_defenders);
    printf("Number of Bases: %d\n", num_of_bases);

    float base_probability = 0.2;
    float defender_probability = 0.5;
    float total_probability;

    total_probability = 1 - (1 - base_probability) * (1 - defender_probability);

    float alien_invasion_probability = 1 - pow(total_probability, num_of_bases);

    printf("The probability of an alien invasion is %.2f%%\n", alien_invasion_probability*100);

    return 0;
}