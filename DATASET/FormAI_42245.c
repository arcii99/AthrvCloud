//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
/* Cryptic C Genome Sequencing Simulator */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 10000
#define MUTATION_CHANCE 0.05

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH+1];
    
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4;
    }

    for(int i = 0; i < GENOME_LENGTH; i++) {
        if((double)rand() / (double)RAND_MAX <= MUTATION_CHANCE) {
            genome[i] = rand() % 4;
        }
    }
    
    int last_nucleotide = -1;
    
    for(int i = 0; i < GENOME_LENGTH; i++) {
        if(genome[i] != last_nucleotide) {
            printf("<");
            last_nucleotide = genome[i];
        }
        printf("%d", genome[i]);
    }
    printf("<\n");
    
    return 0;
}