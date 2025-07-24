//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 100
#define MUTATION_RATE 0.01

int main(void) {

    // Initialize genome array with random nucleotides
    char genome[MAX_GENOME_SIZE];
    srand(time(NULL));
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }

    // Print original genome
    printf("Original genome:\n");
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        printf("%c ", genome[i]);
    }
    printf("\n\n");

    // Simulate mutations
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        double r = (double) rand() / RAND_MAX;
        if (r < MUTATION_RATE) { // Randomly mutate with defined mutation rate
            int n = rand() % 3;
            switch (n) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'C';
                    break;
                case 2:
                    genome[i] = 'G';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
            }
        }
    }

    // Print mutated genome
    printf("Mutated genome:\n");
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        printf("%c ", genome[i]);
    }
    printf("\n");

    return 0;
}