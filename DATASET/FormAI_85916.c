//FormAI DATASET v1.0 Category: Computer Biology ; Style: thoughtful
// This C program demonstrates a genetic algorithm for optimizing a simple function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the parameters of the genetic algorithm
#define POP_SIZE 100    // population size
#define GEN_LENGTH 20   // length of each individual's DNA
#define MUTATION_RATE 0.01  // probability of each gene mutating
#define TARGET_FITNESS 0    // target fitness function value
#define MAX_GENERATIONS 1000    // maximum number of generations to run

// Define the function to be optimized
double fitness(char* dna) {
    int i, n = strlen(dna), count = 0;
    for (i = 0; i < n; i++) {
        if (dna[i] == '1') {
            count++;
        }
    }
    double x = (double)count / (double)n;
    return fabs(x - TARGET_FITNESS);
}

// Define the main routine
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the initial population
    char population[POP_SIZE][GEN_LENGTH+1];
    int i, j;
    for (i = 0; i < POP_SIZE; i++) {
        for (j = 0; j < GEN_LENGTH; j++) {
            population[i][j] = (rand() % 2) ? '1' : '0';
        }
        population[i][GEN_LENGTH] = '\0';
    }

    // Run the genetic algorithm
    int generation = 0;
    while (generation < MAX_GENERATIONS) {
        // Evaluate the fitness of each individual
        double fitnesses[POP_SIZE];
        double total_fitness = 0;
        for (i = 0; i < POP_SIZE; i++) {
            fitnesses[i] = fitness(population[i]);
            total_fitness += fitnesses[i];
        }

        // Select parents for the next generation using roulette wheel selection
        char parents[2][GEN_LENGTH+1];
        for (i = 0; i < 2; i++) {
            double target = rand() / (double)RAND_MAX * total_fitness;
            double sum = 0;
            for (j = 0; j < POP_SIZE; j++) {
                sum += fitnesses[j];
                if (sum >= target) {
                    strcpy(parents[i], population[j]);
                    break;
                }
            }
        }

        // Create the offspring by crossover and mutation
        char offspring[2][GEN_LENGTH+1];
        for (i = 0; i < 2; i++) {
            // Perform single-point crossover
            int crossover_point = rand() % GEN_LENGTH;
            for (j = 0; j < GEN_LENGTH; j++) {
                if (j < crossover_point) {
                    offspring[i][j] = parents[0][j];
                } else {
                    offspring[i][j] = parents[1][j];
                }
            }

            // Perform mutation
            for (j = 0; j < GEN_LENGTH; j++) {
                if (rand() / (double)RAND_MAX < MUTATION_RATE) {
                    offspring[i][j] = (offspring[i][j] == '1') ? '0' : '1';
                }
            }
            offspring[i][GEN_LENGTH] = '\0';
        }

        // Replace the two worst individuals with the offspring
        int worst_index1 = 0, worst_index2 = 0;
        for (i = 0; i < POP_SIZE; i++) {
            if (fitnesses[i] > fitnesses[worst_index1]) {
                worst_index1 = i;
            }
        }
        for (i = 0; i < POP_SIZE; i++) {
            if (i != worst_index1 && fitnesses[i] > fitnesses[worst_index2]) {
                worst_index2 = i;
            }
        }
        strcpy(population[worst_index1], offspring[0]);
        strcpy(population[worst_index2], offspring[1]);

        // Update the generation counter
        generation++;
    }

    // Print the best individual found
    double best_fitness = fitness(population[0]);
    int best_index = 0;
    for (i = 1; i < POP_SIZE; i++) {
        double cur_fitness = fitness(population[i]);
        if (cur_fitness < best_fitness) {
            best_fitness = cur_fitness;
            best_index = i;
        }
    }
    printf("Best individual found after %d generations: %s\n", MAX_GENERATIONS, population[best_index]);

    return 0;
}