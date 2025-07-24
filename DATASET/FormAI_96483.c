//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.05

char random_base(void);

int main(void) {
    srand(time(NULL)); // seed random number generator
    
    // Initialize genome with random bases
    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_base();
    }
    
    // Print the original genome
    printf("Original genome:\n%s\n", genome);
    
    // Simulate mutations in the genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float r = (float) rand() / RAND_MAX; // generate random number between 0 and 1
        
        if (r < MUTATION_RATE) {
            // Mutate the base
            genome[i] = random_base();
            
            // Print a message indicating the mutation
            printf("Mutation at position %d - new genome: %s\n", i, genome);
        }
    }
    
    // Print the final genome
    printf("Final genome:\n%s\n", genome);
    
    return 0;
}

char random_base(void) {
    char bases[] = {'A', 'C', 'G', 'T'};
    int random_index = rand() % 4; // generate random index between 0 and 3
    return bases[random_index];
}