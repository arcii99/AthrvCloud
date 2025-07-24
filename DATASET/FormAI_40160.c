//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the seed for the random number generator

    // generate a random genome sequence of length 50
    char genome[50];
    for (int i = 0; i < 50; i++) {
        int r = rand() % 4; // random number between 0 and 3
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

    // print the generated genome sequence
    printf("Generated genome sequence: %s\n", genome);

    // simulate a mutation in the genome sequence
    int mutation_index = rand() % 50; // randomly choose an index to mutate
    char mutation_type;
    do {
        int r = rand() % 4; // randomly choose a mutation type
        mutation_type = genome[mutation_index];
        switch (r) {
            case 0:
                mutation_type = 'A';
                break;
            case 1:
                mutation_type = 'C';
                break;
            case 2:
                mutation_type = 'G';
                break;
            case 3:
                mutation_type = 'T';
                break;
        }
    } while (mutation_type == genome[mutation_index]); // make sure the mutation type is different from the original nucleotide

    genome[mutation_index] = mutation_type; // update the genome sequence with the mutation

    // print the mutated genome sequence
    printf("Mutated genome sequence: %s\n", genome);

    return 0;
}