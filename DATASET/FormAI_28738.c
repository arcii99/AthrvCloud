//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

int main(void)
{
    char genome[GENOME_LENGTH];
    int i;

    // Randomly generate genome
    srand(time(NULL));
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = 'A' + rand() % 4;
    }

    // Mutate genome
    for (i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = 'A' + rand() % 4;
        }
    }

    // Print genome
    printf("Genome: ");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}