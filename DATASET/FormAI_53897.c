//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHROMOSOME_SIZE 1000
#define MUTATION_RATE 0.05

// Struct that holds a chromosome, with a value and its fitness score
typedef struct {
    int value[MAX_CHROMOSOME_SIZE]; // 0 or 1 for each allele
    float fitness; // score based on similarity to target genome
} Chromosome;

// Generates a random chromosome
void generate_chromosome(Chromosome *c) {
    for (int i = 0; i < MAX_CHROMOSOME_SIZE; i++) {
        c->value[i] = rand() % 2;
    }
}

// Calculates the fitness score for a chromosome, based on similarity to target genome
void calculate_fitness(Chromosome *c, int target_genome[MAX_CHROMOSOME_SIZE]) {
    float score = 0;
    for (int i = 0; i < MAX_CHROMOSOME_SIZE; i++) {
        if (c->value[i] == target_genome[i]) {
            score++;
        }
    }
    c->fitness = score / MAX_CHROMOSOME_SIZE;
}

// Generates a new generation of chromosomes by selecting the fittest and breeding them
void generate_new_generation(Chromosome *population, int population_size, int target_genome[MAX_CHROMOSOME_SIZE]) {
    Chromosome new_population[population_size];
    for (int i = 0; i < population_size; i++) {
        int parent1_i = rand() % population_size;
        int parent2_i = rand() % population_size;
        Chromosome parent1 = population[parent1_i];
        Chromosome parent2 = population[parent2_i];
        
        Chromosome child;
        for (int j = 0; j < MAX_CHROMOSOME_SIZE; j++) {
            // Take random alleles from both parents
            if (rand() % 2 == 0) {
                child.value[j] = parent1.value[j];
            } else {
                child.value[j] = parent2.value[j];
            }
            
            // Introduce mutation
            if (((float) rand() / RAND_MAX) < MUTATION_RATE) {
                child.value[j] = !child.value[j];
            }
        }
        
        // Calculate fitness score for child and add to new population
        calculate_fitness(&child, target_genome);
        new_population[i] = child;
    }
    
    // Copy new population back into original population
    for (int i = 0; i < population_size; i++) {
        population[i] = new_population[i];
    }
}

// Main function to run simulation
int main() {
    srand(time(NULL));
    
    // Define target genome
    int target_genome[MAX_CHROMOSOME_SIZE];
    for (int i = 0; i < MAX_CHROMOSOME_SIZE; i++) {
        if (i % 4 == 0) {
            target_genome[i] = 1;
        } else {
            target_genome[i] = 0;
        }
    }
    
    // Initialize population
    int population_size = 1000;
    Chromosome population[population_size];
    for (int i = 0; i < population_size; i++) {
        generate_chromosome(&population[i]);
        calculate_fitness(&population[i], target_genome);
    }
    
    // Run simulation for 100 generations
    int num_generations = 100;
    for (int i = 0; i < num_generations; i++) {
        printf("Generation %d - max fitness: %f\n", i, population[0].fitness);
        generate_new_generation(population, population_size, target_genome);
    }
    
    // Print final result (the fittest chromosome)
    printf("Final chromosome:\n");
    for (int i = 0; i < MAX_CHROMOSOME_SIZE; i++) {
        printf("%d", population[0].value[i]);
    }
    printf("\nFitness score: %f\n", population[0].fitness);
    
    return 0;
}