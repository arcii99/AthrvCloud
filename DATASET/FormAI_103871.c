//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
// Welcome to the exciting world of computer biology!
// In this program, we will explore genetic mutation and natural selection.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 100 // population size
#define GENE_SIZE 50 // gene size

char population[POP_SIZE][GENE_SIZE]; // store population
char target[GENE_SIZE] = "HELLO WORLD!"; // target gene

// generate random gene
void rand_gene(char gene[]) {
    int i;

    for (i = 0; i < GENE_SIZE; i++) {
        gene[i] = (rand() % 94) + 32; // ascii characters from 32 to 126
    }
}

// calculate fitness of gene
int fitness(char gene[]) {
    int i, score = 0;

    for (i = 0; i < GENE_SIZE; i++) {
        if (gene[i] == target[i]) {
            score++;
        }
    }

    return score;
}

// natural selection
void selection(char selected[]) {
    int i, j, max_fitness = 0, max_index = 0, score;

    // find best fit gene
    for (i = 0; i < POP_SIZE; i++) {
        score = fitness(population[i]);

        if (score > max_fitness) {
            max_fitness = score;
            max_index = i;
        }
    }

    // select best fit gene
    for (i = 0; i < GENE_SIZE; i++) {
        selected[i] = population[max_index][i];
    }
}

// mutation
void mutation(char gene[]) {
    int i, j;

    for (i = 0; i < GENE_SIZE; i++) {
        if (rand() % 100 < 5) { // 5% chance of mutation
            gene[i] = (rand() % 94) + 32;
        }
    }
}

int main() {
    int i, j, generation = 0, max_fitness;
    char selected[GENE_SIZE], temp[GENE_SIZE];

    srand(time(NULL));

    // initialize population
    for (i = 0; i < POP_SIZE; i++) {
        rand_gene(population[i]);
    }

    // loop until target gene is found
    while (1) {
        generation++;

        // selection
        selection(selected);

        // check target gene
        if (fitness(selected) == GENE_SIZE) {
            printf("Target gene found in generation %d: %s\n", generation, selected);
            break;
        }

        // display generation and best fit gene
        max_fitness = fitness(selected);
        printf("Generation %d: ", generation);
        for (i = 0; i < GENE_SIZE; i++) {
            printf("%c", selected[i]);
        }
        printf(" (fitness: %d)\n", max_fitness);

        // mutation and population update
        for (i = 0; i < POP_SIZE; i++) {
            mutation(selected);

            for (j = 0; j < GENE_SIZE; j++) {
                temp[j] = selected[j];
            }

            mutation(temp);
            fitness(temp);

            if (fitness(temp) > fitness(population[i])) {
                for (j = 0; j < GENE_SIZE; j++) {
                    population[i][j] = temp[j];
                }
            }
        }
    }

    return 0;
}