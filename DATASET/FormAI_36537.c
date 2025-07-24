//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LEN 100 // length of genome
#define MUTATION_PROB 5 // probability of mutation in percentage

int main() {

    srand(time(NULL)); // initialize random number generator

    char genome[GENOME_LEN+1]; // create genome array
    int i;

    // generate random genome
    for(i=0; i<GENOME_LEN; i++) {
        genome[i] = rand()%4; // each position is A, C, G, or T
        switch(genome[i]) {
            case 0: genome[i] = 'A'; break;
            case 1: genome[i] = 'C'; break;
            case 2: genome[i] = 'G'; break;
            case 3: genome[i] = 'T'; break;
        }
    }
    genome[GENOME_LEN] = '\0'; // make sure genome is terminated properly

    printf("Original Genome: %s\n", genome);

    // simulate mutation
    for(i=0; i<GENOME_LEN; i++) {
         if(rand()%100 < MUTATION_PROB) { 
             switch(genome[i]) {
                case 'A': genome[i] = 'C'; break;
                case 'C': genome[i] = 'G'; break;
                case 'G': genome[i] = 'T'; break;
                case 'T': genome[i] = 'A'; break;
             }
         }
    }

    printf("Mutated Genome: %s\n", genome);

    return 0;
}