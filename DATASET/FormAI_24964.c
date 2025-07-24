//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000 // length of genome
#define MUTATION_RATE 0.01 // probability of a base mutation

void createGenome(char *genome);
void mutateGenome(char *genome);
void printGenome(char *genome);

int main() {
    char genome[GENOME_SIZE];

    srand(time(NULL)); // seed random number generator

    createGenome(genome);
    printf("Original genome:\n");
    printGenome(genome);

    mutateGenome(genome);
    printf("Mutated genome:\n");
    printGenome(genome);

    return 0;
}

void createGenome(char *genome) {
    int i;
    char base;

    for(i=0; i<GENOME_SIZE; i++) {
        switch(rand()%4) {
            case 0: base = 'A'; break;
            case 1: base = 'C'; break;
            case 2: base = 'G'; break;
            case 3: base = 'T'; break;
        }
        genome[i] = base;
    }
}

void mutateGenome(char *genome) {
    int i;

    for(i=0; i<GENOME_SIZE; i++) {
        if(rand()/(double)RAND_MAX < MUTATION_RATE) { // probability of mutation
            switch(genome[i]) {
                case 'A': genome[i] = 'C'; break;
                case 'C': genome[i] = 'G'; break;
                case 'G': genome[i] = 'T'; break;
                case 'T': genome[i] = 'A'; break;
            }
        }
    }
}

void printGenome(char *genome) {
    int i;

    for(i=0; i<GENOME_SIZE; i++) {
        if(i%100 == 0 && i > 0) printf("\n"); // print in rows of 100 bases
        printf("%c", genome[i]);
    }
    printf("\n");
}