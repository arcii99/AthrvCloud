//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100 // length of genome sequence
#define MUTATION_RATE 0.01 // chance of mutation

int main() {
    srand(time(NULL)); // seed random number generator

    char genome[GENOME_SIZE];
    int i, j;

    // generate random genome sequence
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = (rand() % 4) + 'A'; // generate A, C, G or T
    }

    // print original genome sequence
    printf("Original genome:\n");
    for (i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }

    // simulate sequencing
    for (i = 0; i < GENOME_SIZE; i++) {
        // introduce mutations
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = (rand() % 4) + 'A'; // replace with random nucleotide
        }

        // simulate sequencing error
        if ((double)rand() / RAND_MAX < 0.001) {
            genome[i] = (rand() % 4) + 'A'; // randomly replace nucleotide
        }

        // print simulated sequence
        printf("%c", genome[i]);

        // introduce sequencing error
        if ((double)rand() / RAND_MAX < 0.001) {
            printf("%c", (rand() % 4) + 'A'); // add extra nucleotide
            i++;
        }
    }

    return 0;
}