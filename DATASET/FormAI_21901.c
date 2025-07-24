//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000

char getNucleotide() {
    int random = rand() % 4;
    switch(random) {
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

int main() {
    srand(time(NULL));

    char genome[GENOME_SIZE];
    for(int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = getNucleotide();
    }

    printf("Simulated Genome Sequence: %s\n", genome);
    return 0;
}