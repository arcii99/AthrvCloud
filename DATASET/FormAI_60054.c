//FormAI DATASET v1.0 Category: Computer Biology ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program simulates a genetic algorithm that finds the optimal sequence of
// genes that spells out a given word.

typedef struct Chromosome {
  char *genes;
  int fitness;
} Chromosome;

const int POPULATION_SIZE = 100;
const char TARGET[] = "HELLO_WORLD";
const int TARGET_LENGTH = strlen(TARGET);

void generate_random_genes(char *genes, int length) {
  for (int i = 0; i < length; ++i) {
    genes[i] = (char) (rand() % 26 + 'A');
  }
}

int calculate_fitness(const char *genes) {
  int fitness = 0;
  for (int i = 0; i < TARGET_LENGTH; ++i) {
    fitness += (genes[i] == TARGET[i]) ? 1 : 0;
  }
  return fitness;
}

void mutate_genes(char *genes, int length) {
  int mutation_index = rand() % length;
  genes[mutation_index] = (char) (rand() % 26 + 'A');
}

void create_new_generation(Chromosome *population, int population_size) {
  Chromosome *new_population = malloc(sizeof(Chromosome) * population_size);
  int fitness_sum = 0;
  for (int i = 0; i < population_size; ++i) {
    fitness_sum += population[i].fitness;
  }
  for (int i = 0; i < population_size; ++i) {
    // Select two parents
    int parent_index1 = 0;
    int parent_index2 = 0;
    int roulette_wheel_position = rand() % fitness_sum;
    int partial_sum = 0;
    for (int j = 0; j < population_size; ++j) {
      partial_sum += population[j].fitness;
      if (partial_sum >= roulette_wheel_position) {
        parent_index1 = j;
        break;
      }
    }
    partial_sum = 0;
    roulette_wheel_position = rand() % fitness_sum;
    for (int j = 0; j < population_size; ++j) {
      partial_sum += population[j].fitness;
      if (partial_sum >= roulette_wheel_position) {
        parent_index2 = j;
        break;
      }
    }
    // Perform crossover
    int crossover_point = rand() % TARGET_LENGTH;
    char *child_genes = malloc(sizeof(char) * TARGET_LENGTH);
    memcpy(child_genes, population[parent_index1].genes, crossover_point);
    memcpy(child_genes + crossover_point, population[parent_index2].genes + crossover_point, TARGET_LENGTH - crossover_point);
    // Perform mutation
    if (rand() % 100 < 5) {
      mutate_genes(child_genes, TARGET_LENGTH);
    }
    // Add child to new population
    new_population[i].genes = child_genes;
    new_population[i].fitness = calculate_fitness(child_genes);
  }
  // Replace old population with new one
  for (int i = 0; i < population_size; ++i) {
    free(population[i].genes);
  }
  free(population);
  population = new_population;
}

int main() {
  // Seed random number generator
  srand(12345);

  // Initialize population
  Chromosome *population = malloc(sizeof(Chromosome) * POPULATION_SIZE);
  for (int i = 0; i < POPULATION_SIZE; ++i) {
    char *genes = malloc(sizeof(char) * TARGET_LENGTH);
    generate_random_genes(genes, TARGET_LENGTH);
    int fitness = calculate_fitness(genes);
    population[i].genes = genes;
    population[i].fitness = fitness;
  }

  // Evolution loop
  for (int i = 0; i < 10000; ++i) {
    // Sort population by fitness
    for (int j = 0; j < POPULATION_SIZE - 1; ++j) {
      for (int k = j + 1; k < POPULATION_SIZE; ++k) {
        if (population[j].fitness < population[k].fitness) {
          Chromosome temp = population[j];
          population[j] = population[k];
          population[k] = temp;
        }
      }
    }
    // Check if we have found the target sequence
    if (population[0].fitness == TARGET_LENGTH) {
      printf("Found the target sequence after %d generations!\n", i);
      break;
    }
    // Create new generation
    create_new_generation(population, POPULATION_SIZE);
  }

  // Print results
  printf("Best sequence found: %s\n", population[0].genes);
  printf("Fitness: %d\n", population[0].fitness);

  // Clean up
  for (int i = 0; i < POPULATION_SIZE; ++i) {
    free(population[i].genes);
  }
  free(population);

  return 0;
}