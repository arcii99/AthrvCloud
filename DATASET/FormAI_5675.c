//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.05
#define POPULATION_SIZE 10
#define NUM_GENERATIONS 50

// Defines a genome as a string of 1s and 0s
typedef struct {
    int genome[GENOME_LENGTH];
    float fitness;
} Genome;

// Computes the fitness of a genome
float compute_fitness(Genome *genome) {
    float sum = 0.0;

    for (int i = 0; i < GENOME_LENGTH; i++) {
        sum += genome->genome[i];
    }

    genome->fitness = sum / GENOME_LENGTH;
    return genome->fitness;
}

// Initializes the population with random genomes
void initialize_population(Genome *population) {
    srand(time(NULL));

    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < GENOME_LENGTH; j++) {
            population[i].genome[j] = rand() % 2;
        }
        compute_fitness(&population[i]);
    }
}

// Performs single-point crossover between two genomes
void crossover(Genome *parent1, Genome *parent2, Genome *child) {
    int crossover_point = rand() % GENOME_LENGTH;

    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (i < crossover_point) {
            child->genome[i] = parent1->genome[i];
        } else {
            child->genome[i] = parent2->genome[i];
        }
    }
}

// Mutates the genome by flipping bits with a probability of MUTATION_RATE
void mutate(Genome *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float rand_num = (float) rand() / (float) RAND_MAX;

        if (rand_num < MUTATION_RATE) {
            genome->genome[i] = !(genome->genome[i]);
        }
    }
}

// Finds the fittest genome in the population
Genome *find_fittest(Genome *population) {
    Genome *fittest = &population[0];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        if (population[i].fitness > fittest->fitness) {
            fittest = &population[i];
        }
    }

    return fittest;
}

// Performs one generation of genetic algorithm
void perform_generation(Genome *population) {
    Genome offspring;

    for (int i = 0; i < POPULATION_SIZE / 2; i++) {
        Genome *parent1 = &population[rand() % POPULATION_SIZE];
        Genome *parent2 = &population[rand() % POPULATION_SIZE];

        crossover(parent1, parent2, &offspring);
        mutate(&offspring);
        compute_fitness(&offspring);

        // Replace the least fit parent with the offspring
        Genome *least_fit = parent1;

        if (parent2->fitness < parent1->fitness) {
            least_fit = parent2;
        }

        if (offspring.fitness > least_fit->fitness) {
            *least_fit = offspring;
        }
    }
}

int main() {
    Genome population[POPULATION_SIZE];
    initialize_population(population);

    for (int i = 0; i < NUM_GENERATIONS; i++) {
        perform_generation(population);
        Genome *fittest = find_fittest(population);

        printf("Generation %d: Fittest genome has fitness %f\n", i, fittest->fitness);
    }

    return 0;
}