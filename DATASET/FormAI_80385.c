//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nucleotides[] = {'A', 'C', 'T', 'G'};
    int genomeSize;
    printf("Welcome to Genome Sequencing Simulator!\n");
    printf("Enter the size of the genome: ");
    scanf("%d", &genomeSize);
    char genome[genomeSize + 1];
    srand(time(0));

    for (int i = 0; i < genomeSize; i++) {
        int randIndex = rand() % 4; // There are only 4 nucleotides
        genome[i] = nucleotides[randIndex];
    }
    genome[genomeSize] = '\0';
    printf("Your genome sequence is:\n%s\n", genome);

    // Generate random mutations
    int numMutations;
    printf("Enter the number of mutations you want to generate: ");
    scanf("%d", &numMutations);

    for (int i = 0; i < numMutations; i++) {
        int mutationIndex = rand() % genomeSize;
        int randIndex = rand() % 4; // There are only 4 nucleotides
        while (genome[mutationIndex] == nucleotides[randIndex]) {
            randIndex = rand() % 4; // Generate a different nucleotide than the original
        }
        genome[mutationIndex] = nucleotides[randIndex];
    }
    printf("Your mutated genome sequence is:\n%s\n", genome);
    return 0;
}