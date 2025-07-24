//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define GENOME_SIZE 100
#define MUTATION_PROBABILITY 0.01
#define MAX_MUTATION_VALUE 10

typedef struct genome {
    int code[GENOME_SIZE];
} Genome;

void generateRandomGenome(Genome* g)
{
    for (int i = 0; i < GENOME_SIZE; i++) {
        g->code[i] = rand() % 2;
    }
}

void printGenome(Genome g)
{
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%d ", g.code[i]);
    }
    printf("\n");
}

void mutateGenome(Genome* g)
{
    for (int i = 0; i < GENOME_SIZE; i++) {
        if (((double)rand() / (double)RAND_MAX) < MUTATION_PROBABILITY) {
            g->code[i] += (rand() % (2 * MAX_MUTATION_VALUE)) - MAX_MUTATION_VALUE;
            if (g->code[i] < 0) {
                g->code[i] = 0;
            }
            if (g->code[i] > 1) {
                g->code[i] = 1;
            }
        }
    }
}

void genomeSequencing()
{
    srand(time(NULL));

    Genome g;
    generateRandomGenome(&g);
    printGenome(g);

    for (int i = 0; i < 1000; i++) {
        mutateGenome(&g);
        printGenome(g);
    }
}

int main()
{
    genomeSequencing();
    return 0;
}