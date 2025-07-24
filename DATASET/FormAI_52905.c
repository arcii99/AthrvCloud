//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Genome Sequencing Simulator!\n");

    srand(time(NULL));

    char genome[10000];
    char nucleotides[] = {'A', 'C', 'T', 'G'};

    int i;
    for (i = 0; i < 10000; i++) {
        int index = rand() % 4;
        genome[i] = nucleotides[index];
    }

    printf("Generated genome:\n%s\n", genome);

    int num_mutations = rand() % 4;

    printf("Generating %d mutations...\n", num_mutations);

    for (i = 0; i < num_mutations; i++) {
        int index = rand() % 10000;
        char original = genome[index];
        char new_nucleotide = nucleotides[rand() % 4];
        while (new_nucleotide == original) {
            new_nucleotide = nucleotides[rand() % 4];
        }
        genome[index] = new_nucleotide;
        printf("Mutation at index %d: %c -> %c\n", index, original, new_nucleotide);
    }

    printf("Mutated genome:\n%s\n", genome);

    return 0;
}