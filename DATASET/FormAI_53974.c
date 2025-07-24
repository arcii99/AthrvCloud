//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 100 
#define MUTATION_RATE 0.1 
#define POPULATION_SIZE 10 

char target[SEQUENCE_LENGTH + 1]; // the target genome sequence
char population[POPULATION_SIZE][SEQUENCE_LENGTH + 1]; // the population of genome sequences
int fitness[POPULATION_SIZE]; // the fitness score of each genome sequence

// generates a random genome sequence
void generate_sequence(char* genome)
{
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
    genome[SEQUENCE_LENGTH] = '\0';
}

// calculates the fitness score of a genome sequence
int calculate_fitness(char* genome)
{
    int score = 0;
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (genome[i] == target[i]) {
            score++;
        }
    }
    return score;
}

// generates the initial population of genome sequences
void generate_population()
{
    for (int i = 0; i < POPULATION_SIZE; i++) {
        generate_sequence(population[i]);
        fitness[i] = calculate_fitness(population[i]);
    }
}

// performs a single mutation on a random genome sequence
void mutate(char* genome)
{
    int index = rand() % SEQUENCE_LENGTH;
    int r = rand() % 4;
    switch (r) {
        case 0:
            genome[index] = 'A';
            break;
        case 1:
            genome[index] = 'C';
            break;
        case 2:
            genome[index] = 'G';
            break;
        case 3:
            genome[index] = 'T';
            break;
    }
}

// selects a genome sequence for reproduction based on fitness score
int select_parent()
{
    int total_fitness = 0;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        total_fitness += fitness[i];
    }
    int r = rand() % total_fitness;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        if (r < fitness[i]) {
            return i;
        }
        r -= fitness[i];
    }
    return 0;
}

// produces a new genome sequence via crossover between two parent sequences
void crossover(char* parent1, char* parent2, char* child)
{
    int index = rand() % SEQUENCE_LENGTH;
    for (int i = 0; i < index; i++) {
        child[i] = parent1[i];
    }
    for (int i = index; i < SEQUENCE_LENGTH; i++) {
        child[i] = parent2[i];
    }
}

// advances the simulation by one generation
int next_generation()
{
    char new_population[POPULATION_SIZE][SEQUENCE_LENGTH + 1];
    int new_fitness[POPULATION_SIZE];
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int parent1 = select_parent();
        int parent2 = select_parent();
        crossover(population[parent1], population[parent2], new_population[i]);
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            mutate(new_population[i]);
        }
        new_fitness[i] = calculate_fitness(new_population[i]);
        if (new_fitness[i] == SEQUENCE_LENGTH) {
            printf("Found matching sequence: %s\n", new_population[i]);
            return 1;
        }
    }
    memcpy(population, new_population, sizeof(population));
    memcpy(fitness, new_fitness, sizeof(fitness));
    return 0;
}

int main()
{
    srand(time(NULL));
    strcpy(target, "CGCTCCTTAATTCCAGGGCTTGTTGCATTGTTAGAGCCTCGGCGCAATTGTCACCGTAGCGAGATTCCCCGCAAG");
    generate_population();

    int generation = 0;
    while (!next_generation()) {
        generation++;
        if (generation % 100 == 0) {
            printf("Generation %d best fitness: %d\n", generation, fitness[0]);
        }
    }
    
    return 0;
}