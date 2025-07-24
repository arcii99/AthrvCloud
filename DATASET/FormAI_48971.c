//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // length of the genome
#define NUM_BASES 4 // number of possible bases (A, C, G, T)

char random_base() {
    int rand_num = rand() % NUM_BASES;
    char base;
    switch(rand_num) {
        case 0:
            base = 'A';
            break;
        case 1:
            base = 'C';
            break;
        case 2:
            base = 'G';
            break;
        case 3:
            base = 'T';
            break;
    }
    return base;
}

int main() {
    srand(time(NULL));

    char genome[GENOME_LENGTH];

    printf("Generating genome:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_base();
        printf("%c", genome[i]);
    }
    printf("\n");

    printf("Simulating genome sequencing:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        char base = genome[i];
        if (rand() % 2) { // 50% chance of mutation
            switch(base) {
                case 'A':
                    genome[i] = 'C';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'A';
                    break;
            }
            printf("Mutation at index %d: %c -> %c\n", i, base, genome[i]);
        } else {
            printf("Read base %c at index %d\n", base, i);
        }
    }

    return 0;
}