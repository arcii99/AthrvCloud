//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 100 /* length of the genome */
#define MUTATION_RATE 0.01 /* probability of a mutation occurring */

/* returns a random nucleotide (A, C, G, or T) */
char random_nucleotide() {
    int r = rand() % 4;
    if (r == 0) return 'A';
    if (r == 1) return 'C';
    if (r == 2) return 'G';
    return 'T';
}

int main() {
    srand(time(NULL)); /* seed random number generator */

    /* generate random DNA sequence */
    char genome[DNA_LENGTH+1];
    for (int i = 0; i < DNA_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
    genome[DNA_LENGTH] = '\0'; /* null terminate string */

    /* simulate genome sequencing */
    char sequence[DNA_LENGTH+1];
    for (int i = 0; i < DNA_LENGTH; i++) {
        if (rand()/(double)RAND_MAX < MUTATION_RATE) {
            /* introduce a mutation */
            sequence[i] = random_nucleotide();
        } else {
            /* copy nucleotide from genome */
            sequence[i] = genome[i];
        }
    }
    sequence[DNA_LENGTH] = '\0'; /* null terminate string */

    /* print results */
    printf("Genome: %s\n", genome);
    printf("Sequence: %s\n", sequence);

    return 0;
}