//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

char nucleotides[4] = {'A', 'C', 'G', 'T'};

int main() {
    srand(time(NULL));

    // initialize genome with random nucleotides
    char genome[GENOME_LENGTH+1];
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[GENOME_LENGTH] = '\0';

    // print initial genome
    printf("Initial genome:\n");
    printf("%s\n", genome);

    // select random mutation location based on mutation rate
    int mutation_location = rand() % GENOME_LENGTH;
    if ((rand() % 1000) / 1000.0 > MUTATION_RATE) {
        // replace nucleotide with random one
        char new_nucleotide = nucleotides[rand() % 4];
        genome[mutation_location] = new_nucleotide;
        printf("\nMutation at location %d: '%c' -> '%c'\n", mutation_location, genome[mutation_location], new_nucleotide);
    } else {
        printf("\nNo mutation occurred.\n");
    }

    // print mutated genome
    printf("\nMutated genome:\n");
    printf("%s\n", genome);

    return 0;
}