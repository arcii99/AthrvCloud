//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GENOME_LENGTH 5000
#define BASES "ACGT" // Valid bases

// Simulation settings
#define MUTATION_RATE 0.01 // 1% chance of mutation per base
#define ERROR_RATE 0.005 // 0.5% chance of sequencing error per base

// Helper function to generate random float between 0 and 1
float randf() {
    return (float)rand() / RAND_MAX;
}

// Helper function to randomly select a valid base
char random_base() {
    int idx = rand() % strlen(BASES);
    return BASES[idx];
}

// Simulate genome sequencing with a given error rate and random mutations
int simulate(char* genome, char* result) {
    int errors = 0;
    int mutations = 0;
    
    for (int i = 0; i < GENOME_LENGTH; i++) {
        // Check for mutation
        if (randf() < MUTATION_RATE) {
            genome[i] = random_base();
            mutations++;
        }
        
        // Simulate sequencing error
        char base = genome[i];
        if (randf() < ERROR_RATE) {
            // Replace with a random base
            do {
                base = random_base();
            } while (base == genome[i]); // ensure it's not the same as original base
            
            errors++;
        }
        
        // Add to result string
        result[i] = base;
    }
    
    return errors + mutations;
}

int main() {
    // Initialize genome
    char genome[GENOME_LENGTH+1];
    memset(genome, 'A', GENOME_LENGTH);
    genome[GENOME_LENGTH] = '\0';
    
    // Simulate sequencing
    char result[GENOME_LENGTH+1];
    memset(result, '\0', GENOME_LENGTH+1);
    int errors = simulate(genome, result);
    
    // Print results
    printf("Original genome: %s\n", genome);
    printf("Resulting sequence: %s\n", result);
    printf("Mutation and error rate: %f%%\n", 100.0 * errors / GENOME_LENGTH);
    
    return 0;
}