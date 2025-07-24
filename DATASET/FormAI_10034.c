//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000

int main()
{
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    int i, j, mutation_rate;
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int nucleotides_len = sizeof(nucleotides) / sizeof(nucleotides[0]);

    // Generate initial random genome
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = nucleotides[rand() % nucleotides_len];
    }

    // Simulate mutations
    printf("Initial genome:\n");
    printf("%s\n", genome);
    printf("\nSimulating mutations...\n");
    mutation_rate = rand() % 10 + 1; // Mutations occur in 1-10% of nucleotides
    for (i = 0; i < GENOME_LENGTH; i++) {
        if (rand() % 100 + 1 <= mutation_rate) {
            // Mutate nucleotide
            j = rand() % nucleotides_len;
            while (genome[i] == nucleotides[j]) {
                j = rand() % nucleotides_len;
            }
            genome[i] = nucleotides[j];
        }
    }
    printf("Mutated genome:\n");
    printf("%s\n", genome);
    return 0;
}