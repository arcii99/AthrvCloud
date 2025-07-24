//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LEN 1000 // Length of genome to be sequenced
#define MUTATION_RATE 0.1 // Mutation rate
#define MAX_MUTATIONS 10 // Maximum number of mutations that can occur

char *generate_random_genome() {
    char *genome = (char *) malloc(GENOME_LEN * sizeof(char));
    int i;
    for (i = 0; i < GENOME_LEN; i++) {
        genome[i] = "ACGT"[rand() % 4];
    }
    return genome;
}

char *mutate_genome(char *genome) {
    char *mutated_genome = (char *) malloc(GENOME_LEN * sizeof(char));
    memcpy(mutated_genome, genome, GENOME_LEN * sizeof(char));
    int num_mutations = 0;
    int i;
    for (i = 0; i < GENOME_LEN; i++) {
        if (((double) rand() / RAND_MAX) <= MUTATION_RATE) { // Randomly mutate a nucleotide
            mutated_genome[i] = "ACGT"[rand() % 4];
            num_mutations++;
            if (num_mutations >= MAX_MUTATIONS) {
                break;
            }
        }
    }
    return mutated_genome;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    
    char *original_genome = generate_random_genome();
    printf("Original genome: %s\n", original_genome);
    
    char *mutated_genome = mutate_genome(original_genome);
    printf("Mutated genome: %s\n", mutated_genome);
    
    free(original_genome);
    free(mutated_genome);
    
    return 0;
}