//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MUTATION_RATE 0.05
#define NUMBER_OF_GENOMES 10
#define OFFSPRING_PER_GENOME 2
#define TOURNAMENT_SIZE 10

int genome_pool[NUMBER_OF_GENOMES][SEQUENCE_LENGTH];

void generateGenome(int *genome) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        genome[i] = rand() % 4;
    }
}

void mutateGenome(int *genome) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = rand() % 4;
        }
    }
}

double calculateFitness(int *genome, char *targetSequence) {
    int mismatchCount = 0;
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (genome[i] != targetSequence[i]) {
            mismatchCount++;
        }
    }
    return 1.0 / (mismatchCount + 1);
}

void randomSelection(int *tournament) {
    for (int i = 0; i < TOURNAMENT_SIZE; i++) {
        tournament[i] = rand() % NUMBER_OF_GENOMES;
    }
}

int tournamentSelection(int **population) {
    int tournament[TOURNAMENT_SIZE];
    randomSelection(tournament);
    int winner = 0;
    double bestFitness = 0;
    for (int i = 0; i < TOURNAMENT_SIZE; i++) {
        double fitness = calculateFitness(population[tournament[i]], "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA");
        if (fitness > bestFitness) {
            winner = tournament[i];
            bestFitness = fitness;
        }
    }
    return winner;
}

void crossover(int *parent1, int *parent2, int *child1, int *child2) {
    int crossoverPoint = rand() % SEQUENCE_LENGTH;
    for (int i = 0; i < crossoverPoint; i++) {
        child1[i] = parent1[i];
        child2[i] = parent2[i];
    }
    for (int i = crossoverPoint; i < SEQUENCE_LENGTH; i++) {
        child1[i] = parent2[i];
        child2[i] = parent1[i];
    }
}

void generatePopulation(int **population) {
    for (int i = 0; i < NUMBER_OF_GENOMES; i++) {
        generateGenome(population[i]);
    }
}

void evolvePopulation(int **population) {
    for (int i = 0; i < NUMBER_OF_GENOMES; i += 2) {
        int parent1 = tournamentSelection(population);
        int parent2 = tournamentSelection(population);
        int child1[SEQUENCE_LENGTH];
        int child2[SEQUENCE_LENGTH];
        crossover(population[parent1], population[parent2], child1, child2);
        mutateGenome(child1);
        mutateGenome(child2);
        if (calculateFitness(child1, "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA") > calculateFitness(population[parent1], "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA")) {
            memcpy(population[parent1], child1, sizeof(int) * SEQUENCE_LENGTH);
        }
        if (calculateFitness(child2, "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA") > calculateFitness(population[parent2], "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA")) {
            memcpy(population[parent2], child2, sizeof(int) * SEQUENCE_LENGTH);
        }
    }
}

int main() {
    srand(time(0));
    int *population[NUMBER_OF_GENOMES];
    for (int i = 0; i < NUMBER_OF_GENOMES; i++) {
        population[i] = genome_pool[i];
    }
    generatePopulation(population);
    for (int generation = 0; generation < 1000; generation++) {
        evolvePopulation(population);
        double bestFitness = 0;
        int fittestGenome = 0;
        for (int i = 0; i < NUMBER_OF_GENOMES; i++) {
            double fitness = calculateFitness(population[i], "ACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGACCTGA");
            if (fitness > bestFitness) {
                bestFitness = fitness;
                fittestGenome = i;
            }
        }
        printf("Generation: %d\tFitness: %.6f\n", generation, bestFitness);
        for (int i = 0; i < SEQUENCE_LENGTH; i++) {
            printf("%d", population[fittestGenome][i]);
        }
        printf("\n\n");
    }
    return 0;
}