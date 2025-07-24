//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 100
#define MUTATION_PROBABILITY 0.01

int randomInRange(int start, int end) {
    return rand() % (end - start + 1) + start;
}

char randomNucleotide() {
    int r = rand() % 4;
    switch(r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

void mutate(char * genome) {
    for(int i = 0; i < GENOME_LENGTH; i++) {
        if((double)rand() / RAND_MAX < MUTATION_PROBABILITY) {
            genome[i] = randomNucleotide();
        }
    }
}

void printGenome(char * genome) {
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char genome[GENOME_LENGTH];

    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = randomNucleotide();
    }

    printf("Initial Genome:\n");
    printGenome(genome);

    mutate(genome);

    printf("Mutated Genome:\n");
    printGenome(genome);

    return 0;
}