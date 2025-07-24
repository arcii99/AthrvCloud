//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

int main(){

    char genome[GENOME_LENGTH];
    srand(time(NULL));

    // Generate random genome
    for(int i = 0; i < GENOME_LENGTH; i++){
        genome[i] = (rand() % 4) + 'A';
    }

    printf("Original genome: %s\n", genome);

    // Mutate genome
    for(int i = 0; i < GENOME_LENGTH; i++){
        if((double)rand() / (double)RAND_MAX < MUTATION_RATE){
            switch(genome[i]){
                case 'A':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'A';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'C';
                    break;
            }
        }
    }

    printf("Mutated genome: %s\n", genome);

    return 0;
}