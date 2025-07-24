//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100000 // Size of the genome to simulate
#define MUTATION_RATE 0.01 // Probability of a base mutation

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Generate the initial genome
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = 'A' + rand() % 4; // Randomly assign A, C, G, or T
    }
    
    // Mutate the genome
    for (int i = 0; i < GENOME_SIZE; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            do {
                genome[i] = 'A' + rand() % 4; // Randomly mutate to A, C, G, or T
            } while (genome[i] == genome[i-1]); // Ensure we don't mutate to the same base as the previous one
        }
    }
    
    // Print the genome
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}