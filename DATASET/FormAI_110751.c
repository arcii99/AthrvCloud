//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the bases that make up the genome sequence
#define BASE_A 'A'
#define BASE_C 'C'
#define BASE_G 'G'
#define BASE_T 'T'

//Define the probability distribution between the bases
#define A_PROBABILITY 30
#define C_PROBABILITY 20
#define G_PROBABILITY 25
#define T_PROBABILITY 25

//Define the length of the genome sequence to be generated
#define GENOME_LENGTH 100

int main() {
    char genome[GENOME_LENGTH];
    int i;

    srand(time(NULL));

    //Generate genome sequence based on the probability distribution
    for (i = 0; i < GENOME_LENGTH; i++) {
        int rand_num = rand() % 100;
        if (rand_num < A_PROBABILITY) {
            genome[i] = BASE_A;
        }
        else if (rand_num < A_PROBABILITY + C_PROBABILITY) {
            genome[i] = BASE_C;
        }
        else if (rand_num < A_PROBABILITY + C_PROBABILITY + G_PROBABILITY) {
            genome[i] = BASE_G;
        }
        else {
            genome[i] = BASE_T;
        }
    }

    //Output generated genome sequence
    printf("Generated genome sequence: ");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}