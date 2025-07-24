//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000
#define MUTATION_RATE 0.01

void init_genome(char genome[]) {
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4 + 'A'; // randomly initialize genome with A, C, G, T
    }
}

void mutate_genome(char genome[]) {
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        if ((double)rand() / (RAND_MAX + 1.0) < MUTATION_RATE) {
            genome[i] = rand() % 4 + 'A'; // randomly mutate a gene with equal probability
        }
    }
}

void print_genome(char genome[]) {
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    char genome[GENOME_SIZE];
    
    printf("Initial genome:\n");
    init_genome(genome);
    print_genome(genome);
    
    printf("Mutated genome:\n");
    mutate_genome(genome);
    print_genome(genome);
    
    return 0;
}