//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHROMOSOMES 50
#define MAX_GENES 100
#define MAX_BASE_PAIRS 4
#define CHROMOSOME_LEN 1000

int main()
{
    srand(time(NULL));

    char chromosomes[MAX_CHROMOSOMES][CHROMOSOME_LEN];
    char basePairs[MAX_BASE_PAIRS] = {'A', 'C', 'G', 'T'};

    // Initialize chromosomes with random genes
    for (int i = 0; i < MAX_CHROMOSOMES; i++)
    {
        for (int j = 0; j < CHROMOSOME_LEN; j++)
        {
            chromosomes[i][j] = basePairs[rand() % MAX_BASE_PAIRS];
        }
    }

    // Print out the chromosomes
    for (int i = 0; i < MAX_CHROMOSOMES; i++)
    {
        printf("Chromosome %d: ", i+1);
        for (int j = 0; j < CHROMOSOME_LEN; j++)
        {
            printf("%c", chromosomes[i][j]);
        }
        printf("\n");
    }

    // Find a random gene in a random chromosome
    int randChromosome = rand() % MAX_CHROMOSOMES;
    int randGene = rand() % CHROMOSOME_LEN;
    printf("Random gene: %c found in chromosome %d\n", chromosomes[randChromosome][randGene], randChromosome + 1);

    // Mutate a random gene in a random chromosome
    int mutateChromosome = rand() % MAX_CHROMOSOMES;
    int mutateGene = rand() % CHROMOSOME_LEN;
    char mutateTo = basePairs[rand() % MAX_BASE_PAIRS];
    chromosomes[mutateChromosome][mutateGene] = mutateTo;
    printf("Mutated gene %d in chromosome %d to %c\n", mutateGene, mutateChromosome + 1, mutateTo);

    return 0;
}