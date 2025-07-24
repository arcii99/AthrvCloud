//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

int main() {
    srand(time(NULL));
    
    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4 + 'A';
    }
    
    printf("Initial genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    char base_pairs[4] = {'A', 'C', 'G', 'T'};
    int num_mutations = 0;
    while (num_mutations < GENOME_LENGTH * MUTATION_RATE) {
        int index = rand() % GENOME_LENGTH;
        char mutation = base_pairs[rand() % 4];
        if (genome[index] != mutation) {
            genome[index] = mutation;
            num_mutations++;
        }
    }
    
    printf("Mutated genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}