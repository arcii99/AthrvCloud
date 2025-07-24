//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LEN 10000 // Maximum length of genome
#define PROB_MUTATION 0.05 // Probability of a mutation occuring

int main() {
    char genome[MAX_GENOME_LEN]; // Genome sequence
    int length; // Length of genome sequence
    
    // Set random seed
    srand(time(0));
    
    // Generate random genome
    length = rand() % MAX_GENOME_LEN;
    for(int i = 0; i < length; i++) {
        genome[i] = rand() % 4; // Randomly select A, C, G, or T
    }
    
    // Mutate genome with specified probability
    for(int i = 0; i < length; i++) {
        if((double)rand() / RAND_MAX < PROB_MUTATION) {
            genome[i] = rand() % 4; // Randomly select new nucleotide
        }
    }
    
    // Print genome sequence
    printf("Genome sequence: ");
    for(int i = 0; i < length; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("?");
                break;
        }
    }
    printf("\n");
    
    return 0;
}