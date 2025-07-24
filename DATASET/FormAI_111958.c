//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 50
#define MAX_ITER 1000
#define MUTATION_RATE 0.1
#define NUM_COLORS 4

int graph[10][10], colors[10], fitness[POP_SIZE];
int best_fitness, best_solution[10];

void generate_initial_population(int population[][10]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < POP_SIZE; i++) {
        for (j = 0; j < 10; j++) {
            population[i][j] = rand() % NUM_COLORS;
        }
    }
}

int calculate_fitness(int solution[]) {
    int i, j, fitness = 0;
    for (i = 0; i < 10; i++) {
        for (j = i+1; j < 10; j++) {
            if (graph[i][j] && solution[i] == solution[j]) {
                fitness++;
            }
        }
    }
    return fitness;
}

void evaluate_population(int population[][10]) {
    int i;
    for (i = 0; i < POP_SIZE; i++) {
        fitness[i] = calculate_fitness(population[i]);
        if (fitness[i] < best_fitness) {
            best_fitness = fitness[i];
            memcpy(best_solution, population[i], sizeof(best_solution));
        }
    }
}

void crossover(int parent1[], int parent2[], int child[]) {
    int i, crossover_point;
    crossover_point = rand() % 9 + 1;
    for (i = 0; i < crossover_point; i++) {
        child[i] = parent1[i];
    }
    for (i = crossover_point; i < 10; i++) {
        child[i] = parent2[i];
    }
}

void mutate(int solution[]) {
    int i;
    for (i = 0; i < 10; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            solution[i] = rand() % NUM_COLORS;
        }
    }
}

void selection(int population[][10], int parents[][10]) {
    int i, j, k, fitness_sum = 0, wheel_position = 0;
    int roulette_wheel[POP_SIZE], cumulative_fitness[POP_SIZE];
    for (i = 0; i < POP_SIZE; i++) {
        fitness_sum += fitness[i];
        roulette_wheel[i] = 0;
        parents[i][0] = parents[i][9] = -1;
    }
    for (i = 0; i < POP_SIZE; i++) {
        cumulative_fitness[i] = roulette_wheel[i] = fitness_sum - fitness[i] + 1;
        if (i > 0) cumulative_fitness[i] += cumulative_fitness[i-1];
    }
    for (i = 0; i < POP_SIZE; i++) {
        j = rand() % fitness_sum + 1;
        for (k = 0; k < POP_SIZE; k++) {
            if (j <= cumulative_fitness[k]) {
                memcpy(parents[i], population[k], sizeof(parents[i]));
                break;
            }
        }
    }
}

void genetic_algorithm() {
    int i, j, child[10], parents[POP_SIZE][10], population[POP_SIZE][10];
    generate_initial_population(population);
    evaluate_population(population);
    for (i = 0; i < MAX_ITER; i++) {
        selection(population, parents);
        for (j = 0; j < POP_SIZE; j++) {
            crossover(parents[j], parents[(j+1)%POP_SIZE], child);
            mutate(child);
            memcpy(population[j], child, sizeof(population[j]));
        }
        evaluate_population(population);
        if (best_fitness == 0) break;
    }
}

int main() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = i+1; j < 10; j++) {
            graph[i][j] = graph[j][i] = rand() % 2;
        }
    }
    genetic_algorithm();
    printf("Best solution found:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", best_solution[i]);
    }
    printf("\nBest fitness: %d\n", best_fitness);
    return 0;
}