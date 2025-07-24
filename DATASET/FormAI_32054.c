//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define GENOME_SIZE 100
#define MUTATION_RATE 0.2
#define CROSSOVER_RATE 0.8
#define POPULATION_SIZE 100
#define GENERATION_NUM 50

struct genome {
    char sequence[GENOME_SIZE];
    float fitness;
};

struct population {
    struct genome individuals[POPULATION_SIZE];
};

float calculate_fitness(struct genome* gptr[]) {
    float fitness_sum = 0;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < GENOME_SIZE; j++) {
            if (gptr[i]->sequence[j] == 'G') {
                fitness_sum++;
            }
        }
        gptr[i]->fitness = fitness_sum / GENOME_SIZE;
    }
}

void mutate(struct genome* gptr) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        float mutate_chance = (float) rand() / (float) RAND_MAX;
        if (mutate_chance < MUTATION_RATE) {
            if (gptr->sequence[i] == 'A') {
                gptr->sequence[i] = 'T';
            } else if (gptr->sequence[i] == 'T') {
                gptr->sequence[i] = 'A';
            } else if (gptr->sequence[i] == 'C') {
                gptr->sequence[i] = 'G';
            } else if (gptr->sequence[i] == 'G') {
                gptr->sequence[i] = 'C';
            }
        }
    }
}

struct genome* crossover(struct genome* parent1, struct genome* parent2) {
    struct genome* child = malloc(sizeof(struct genome));
    for (int i = 0; i < GENOME_SIZE; i++) {
        float crossover_chance = (float) rand() / (float) RAND_MAX;
        if (crossover_chance < CROSSOVER_RATE) {
            child->sequence[i] = parent1->sequence[i];
        } else {
            child->sequence[i] = parent2->sequence[i];
        }
    }
    return child;
}

void sort_population(struct genome* gptr[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = i + 1; j < POPULATION_SIZE; j++) {
            if (gptr[j]->fitness > gptr[i]->fitness) {
                struct genome* temp = gptr[j];
                gptr[j] = gptr[i];
                gptr[i] = temp;
            }
        }
    }
}

void generate_initial_population(struct genome* gptr[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < GENOME_SIZE; j++) {
            float random_num = (float) rand() / (float) RAND_MAX;
            if (random_num < 0.25) {
                gptr[i]->sequence[j] = 'A';
            } else if (random_num < 0.5) {
                gptr[i]->sequence[j] = 'T';
            } else if (random_num < 0.75) {
                gptr[i]->sequence[j] = 'C';
            } else {
                gptr[i]->sequence[j] = 'G';
            }
        }
    }
}

void print_population(struct genome* gptr[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < GENOME_SIZE; j++) {
            printf("%c", gptr[i]->sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    struct genome* population[POPULATION_SIZE];
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = malloc(sizeof(struct genome));
    }
    generate_initial_population(population);
    for (int generation = 0; generation < GENERATION_NUM; generation++) {
        calculate_fitness(population);
        sort_population(population);
        struct genome* new_population[POPULATION_SIZE];
        for (int i = 0; i < POPULATION_SIZE; i++) {
            struct genome* parent1 = population[i];
            struct genome* parent2 = population[rand() % POPULATION_SIZE];
            struct genome* child = crossover(parent1, parent2);
            mutate(child);
            new_population[i] = child;
        }
        for (int i = 0; i < POPULATION_SIZE; i++) {
            free(population[i]);
            population[i] = new_population[i];
        }
    }
    calculate_fitness(population);
    sort_population(population);
    printf("Population after %d generations:\n", GENERATION_NUM);
    print_population(population);
    return 0;
}