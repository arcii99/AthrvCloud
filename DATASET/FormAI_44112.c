//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

int main(){
    // initialize genome and random seed
    char genome[GENOME_LENGTH + 1];
    srand(time(NULL));

    // create the reference genome
    for(int i = 0; i < GENOME_LENGTH; i++){
        char nucleotide;
        switch(rand() % 4){
            case 0:
                nucleotide = 'A'; break;
            case 1:
                nucleotide = 'C'; break;
            case 2:
                nucleotide = 'G'; break;
            default:
                nucleotide = 'T'; break;
        }
        genome[i] = nucleotide;
    }
    genome[GENOME_LENGTH] = '\0';

    // output the reference genome
    printf("Reference genome: %s\n", genome);

    // create the mutated genome
    char mutated_genome[GENOME_LENGTH + 1];
    strncpy(mutated_genome, genome, GENOME_LENGTH + 1);
    for(int i = 0; i < GENOME_LENGTH; i++){
        if((double) rand() / (double) RAND_MAX <= MUTATION_RATE){
            char nucleotide;
            do{
                switch(rand() % 4){
                    case 0:
                        nucleotide = 'A'; break;
                    case 1:
                        nucleotide = 'C'; break;
                    case 2:
                        nucleotide = 'G'; break;
                    default:
                        nucleotide = 'T'; break;
                }
            }while(nucleotide == mutated_genome[i]);
            mutated_genome[i] = nucleotide;
        }
    }

    // output the mutated genome
    printf("Mutated genome: %s\n", mutated_genome);

    return 0;
}