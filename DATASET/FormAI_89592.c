//FormAI DATASET v1.0 Category: Computer Biology ; Style: imaginative
/* The following code demonstrates a program for simulating the effects of natural selection on a population 
of organisms in a changing environment. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 100 // Size of the population.
#define GENE_COUNT 10 // Number of genes per organism.
#define GENE_RANGE 100 // Possible range of gene values.
#define MUTATION_RATE 0.01 // Probability of a gene mutation.

/* Structure representing an organism. */
typedef struct {
    int genes[GENE_COUNT];
    double fitness;
} Organism;

/* The population of organisms. */
Organism pop[POP_SIZE];

/* Evaluates the fitness of an organism. */
double evaluate_fitness(Organism org) {
    double fitness = 0.0;
    int i;

    for (i = 0; i < GENE_COUNT; i++) {
        fitness += (double)org.genes[i] / GENE_RANGE;
    }

    return fitness;
}

/* Initializes the population with random genes. */
void initialize_population() {
    int i, j;

    for (i = 0; i < POP_SIZE; i++) {
        for (j = 0; j < GENE_COUNT; j++) {
            pop[i].genes[j] = rand() % GENE_RANGE;
        }

        pop[i].fitness = evaluate_fitness(pop[i]);
    }
}

/* Mutates the genes of an organism with a given probability. */
void mutate(Organism *org) {
    int i;

    for (i = 0; i < GENE_COUNT; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            org->genes[i] = rand() % GENE_RANGE;
        }
    }

    org->fitness = evaluate_fitness(*org);
}

/* Applies natural selection to the population. */
void natural_selection() {
    int i, j, k;
    Organism new_pop[POP_SIZE];
    double total_fitness = 0.0, accum_fitness = 0.0, r;

    /* Calculate the total fitness of the population. */
    for (i = 0; i < POP_SIZE; i++) {
        total_fitness += pop[i].fitness;
    }

    /* Select organisms for the new population. */
    for (i = 0; i < POP_SIZE; i++) {
        /* Select an organism with a probability proportional to its fitness. */
        r = (double)rand() / RAND_MAX * total_fitness;

        for (j = 0; j < POP_SIZE; j++) {
            accum_fitness += pop[j].fitness;

            if (accum_fitness >= r) {
                /* Copy the selected organism into the new population. */
                for (k = 0; k < GENE_COUNT; k++) {
                    new_pop[i].genes[k] = pop[j].genes[k];
                }

                break;
            }
        }
    }

    /* Apply mutation to the new population. */
    for (i = 0; i < POP_SIZE; i++) {
        mutate(&new_pop[i]);
    }

    /* Replace the old population with the new one. */
    for (i = 0; i < POP_SIZE; i++) {
        pop[i] = new_pop[i];
    }
}

int main() {
    int i, j;
    srand(time(NULL));

    initialize_population();

    for (i = 0; i < 100; i++) {
        printf("Generation %d:\n", i);

        for (j = 0; j < POP_SIZE; j++) {
            printf("%.2f ", pop[j].fitness);
        }

        printf("\n");

        natural_selection();
    }

    return 0;
}