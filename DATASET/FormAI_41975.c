//FormAI DATASET v1.0 Category: Computer Biology ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define CITY_COUNT 10
#define POPULATION_SIZE 50
#define GENERATION_LIMIT 100

typedef struct {
    int city_order[CITY_COUNT];
    float fitness;
} chromosome_t;

int distance[CITY_COUNT][CITY_COUNT];


/*
 * Calculates the distance between two cities using their coordinates.
 */
int calculate_distance(int x1, int y1, int x2, int y2) {
    return (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


/*
 * Initializes the city distance matrix with random numbers from 1 to 100.
 */
void initialize_distance_matrix() {
    srand(time(NULL));
    for (int i = 0; i < CITY_COUNT; i++) {
        for (int j = i; j < CITY_COUNT; j++) {
            if (i == j) {
                distance[i][j] = 0;
            } else {
                int value = rand() % 100 + 1;
                distance[i][j] = distance[j][i] = value;
            }
        }
    }
}


/*
 * Initializes a chromosome with a random city order, and calculates its fitness.
 */
void initialize_chromosome(chromosome_t *chromosome) {
    for (int i = 0; i < CITY_COUNT; i++) {
        chromosome->city_order[i] = i;
    }
    for (int i = CITY_COUNT - 1; i > 0; i--) {
        int j = rand() % i;
        int temp = chromosome->city_order[i];
        chromosome->city_order[i] = chromosome->city_order[j];
        chromosome->city_order[j] = temp;
    }
    int total_distance = 0;
    for (int i = 0; i < CITY_COUNT; i++) {
        int from_city = chromosome->city_order[i];
        int to_city = chromosome->city_order[(i + 1) % CITY_COUNT];
        total_distance += distance[from_city][to_city];
    }
    chromosome->fitness = 1.0 / total_distance;
}


/*
 * Calculates the fitness of all chromosomes in the population.
 */
void calculate_fitness(chromosome_t population[POPULATION_SIZE]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int total_distance = 0;
        for (int j = 0; j < CITY_COUNT; j++) {
            int from_city = population[i].city_order[j];
            int to_city = population[i].city_order[(j + 1) % CITY_COUNT];
            total_distance += distance[from_city][to_city];
        }
        population[i].fitness = 1.0 / total_distance;
    }
}


/*
 * Selects two parents from the population using tournament selection, and returns their index.
 */
void tournament_selection(chromosome_t population[POPULATION_SIZE], int *parent_index1, int *parent_index2) {
    int index1 = rand() % POPULATION_SIZE;
    int index2 = rand() % POPULATION_SIZE;
    if (population[index1].fitness > population[index2].fitness) {
        *parent_index1 = index1;
    } else {
        *parent_index1 = index2;
    }
    index1 = rand() % POPULATION_SIZE;
    index2 = rand() % POPULATION_SIZE;
    if (population[index1].fitness > population[index2].fitness) {
        *parent_index2 = index1;
    } else {
        *parent_index2 = index2;
    }
}


/*
 * Performs crossover between two parents using the ordered crossover technique, and returns the child chromosome.
 */
void ordered_crossover(chromosome_t parent1, chromosome_t parent2, chromosome_t *child) {
    int start_index = rand() % CITY_COUNT;
    int end_index = rand() % CITY_COUNT;
    if (start_index > end_index) {
        int temp = start_index;
        start_index = end_index;
        end_index = temp;
    }
    int used_cities[CITY_COUNT] = {0};
    for (int i = start_index; i <= end_index; i++) {
        child->city_order[i] = parent1.city_order[i];
        used_cities[child->city_order[i]] = 1;
    }
    int index = end_index + 1;
    for (int i = 0; i < CITY_COUNT; i++) {
        if (index == CITY_COUNT) {
            index = 0;
        }
        if (!used_cities[parent2.city_order[i]]) {
            child->city_order[index++] = parent2.city_order[i];
        }
    }
}


/*
 * Performs mutation on a chromosome using the swap mutation technique.
 */
void swap_mutation(chromosome_t *chromosome) {
    int index1 = rand() % CITY_COUNT;
    int index2 = rand() % CITY_COUNT;
    int temp = chromosome->city_order[index1];
    chromosome->city_order[index1] = chromosome->city_order[index2];
    chromosome->city_order[index2] = temp;
}


/*
 * Evolutionary algorithm that optimizes the traveling salesman problem using genetic operators.
 */
void evolutionary_algorithm() {
    chromosome_t population[POPULATION_SIZE];
    for (int i = 0; i < POPULATION_SIZE; i++) {
        initialize_chromosome(&population[i]);
    }
    calculate_fitness(population);
    float best_fitness = INT_MIN;
    int best_index;
    for (int i = 0; i < GENERATION_LIMIT; i++) {
        int parent_index1, parent_index2;
        tournament_selection(population, &parent_index1, &parent_index2);
        chromosome_t child_chromosome;
        ordered_crossover(population[parent_index1], population[parent_index2], &child_chromosome);
        if (rand() % 100 < 10) {
            swap_mutation(&child_chromosome);
        }
        calculate_fitness(&child_chromosome);
        int worst_index = 0;
        float worst_fitness = INT_MAX;
        for (int j = 0; j < POPULATION_SIZE; j++) {
            if (population[j].fitness < worst_fitness) {
                worst_fitness = population[j].fitness;
                worst_index = j;
            }
        }
        if (child_chromosome.fitness > worst_fitness) {
            population[worst_index] = child_chromosome;
        }
        float average_fitness = 0;
        for (int j = 0; j < POPULATION_SIZE; j++) {
            average_fitness += population[j].fitness;
            if (population[j].fitness > best_fitness) {
                best_fitness = population[j].fitness;
                best_index = j;
            }
        }
        average_fitness /= POPULATION_SIZE;
        printf("Generation: %d, Best Fitness: %f, Average Fitness: %f\n", i + 1, best_fitness, average_fitness);
    }
    printf("Best Tour Order: ");
    for (int i = 0; i < CITY_COUNT; i++) {
        printf("%d ", population[best_index].city_order[i]);
    }
    printf("\nBest Tour Distance: %d", (int)(1.0 / best_fitness));
}


/*
 * Main entry point of the program. Initializes the city distance matrix, and starts the evolutionary algorithm.
 */
int main() {
    initialize_distance_matrix();
    evolutionary_algorithm();
    return 0;
}