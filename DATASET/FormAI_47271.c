//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 20
#define CHROMOSOME_LENGTH 10
#define MUTATION_RATE 0.1
#define CROSSOVER_RATE 0.8
#define NUM_GENERATIONS 100

typedef struct {
    int genes[CHROMOSOME_LENGTH];
    int fitness;
} chromosome;

chromosome population[POPULATION_SIZE];

int calc_fitness(int genes[]) {
    // Fitness function to calculate the fitness of a chromosome
    int fitness = 0;
    for (int i = 0; i < CHROMOSOME_LENGTH; i++) {
        if (genes[i] == 1) {
            fitness++;
        }
    }
    return fitness;
}

void init_population() {
    // Initialize the population with random chromosomes
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
            population[i].genes[j] = rand() % 2;
        }
        population[i].fitness = calc_fitness(population[i].genes);
    }
}

void mutate(chromosome* c) {
    // Mutate a single gene in the chromosome
    int index = rand() % CHROMOSOME_LENGTH;
    c->genes[index] = !c->genes[index];
    c->fitness = calc_fitness(c->genes);
}

void crossover(chromosome* c1, chromosome* c2) {
    // Perform crossover between two chromosomes
    int index = rand() % CHROMOSOME_LENGTH;
    for (int i = index; i < CHROMOSOME_LENGTH; i++) {
        int temp = c1->genes[i];
        c1->genes[i] = c2->genes[i];
        c2->genes[i] = temp;
        c1->fitness = calc_fitness(c1->genes);
        c2->fitness = calc_fitness(c2->genes);
    }
}

void selection() {
    // Select the best chromosomes to survive
    chromosome new_population[POPULATION_SIZE];
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int index1 = rand() % POPULATION_SIZE;
        int index2 = rand() % POPULATION_SIZE;
        if (population[index1].fitness > population[index2].fitness) {
            new_population[i] = population[index1];
        } else {
            new_population[i] = population[index2];
        }
    }
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = new_population[i];
    }
}

void print_population() {
    // Print the population for debugging purposes
    for (int i = 0; i < POPULATION_SIZE; i++) {
        printf("[%d]: ", population[i].fitness);
        for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
            printf("%d ", population[i].genes[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    init_population();
    for (int generation = 0; generation < NUM_GENERATIONS; generation++) {
        for (int i = 0; i < POPULATION_SIZE; i++) {
            if ((double)rand() / RAND_MAX < MUTATION_RATE) {
                mutate(&population[i]);
            }
            if ((double)rand() / RAND_MAX < CROSSOVER_RATE) {
                int index = rand() % POPULATION_SIZE;
                crossover(&population[i], &population[index]);
            }
        }
        selection();
    }
    print_population();
    return 0;
}