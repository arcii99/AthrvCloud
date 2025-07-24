//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define POSSIBLE_NUCLEOTIDES 4

char random_nucleotide() {
    int rand_num = rand() % POSSIBLE_NUCLEOTIDES;

    if (rand_num == 0) {
        return 'A';
    } else if (rand_num == 1) {
        return 'C';
    } else if (rand_num == 2) {
        return 'G';
    } else {
        return 'T';
    }
}

int main() {
    srand(time(0));
    char genome[GENOME_LENGTH];

    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }

    printf("Genome sequence: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}