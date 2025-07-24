//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int genomeSize, numSequences, i, j, k;
    char *genome;

    srand(time(NULL));

    printf("Enter the size of the genome: ");
    scanf("%d", &genomeSize);

    genome = (char*) malloc(sizeof(char) * (genomeSize+1));
    genome[genomeSize] = '\0';

    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);

    for (i = 0; i < numSequences; i++) {
        for (j = 0; j < genomeSize; j++) {
            k = rand() % 4;
            if (k == 0) genome[j] = 'A';
            else if (k == 1) genome[j] = 'C';
            else if (k == 2) genome[j] = 'G';
            else if (k == 3) genome[j] = 'T';
        }
        printf("Sequence %d: %s\n", i+1, genome);
    }

    free(genome);
    return 0;
}