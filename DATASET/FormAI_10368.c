//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100000 // The length of the genome sequence to be generated
#define MUTATION_PROBABILITY 0.05 // The probability of a base being mutated

char getRandomBase() {
    int randomInt = rand() % 4;
    if (randomInt == 0) {
        return 'A';
    } else if (randomInt == 1) {
        return 'C';
    } else if (randomInt == 2) {
        return 'G';
    } else {
        return 'T';
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomBase();
    }

    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_PROBABILITY) {
            genome[i] = getRandomBase();
        }
    }

    printf("Genome Sequence:\n%s\n", genome);

    return 0;
}