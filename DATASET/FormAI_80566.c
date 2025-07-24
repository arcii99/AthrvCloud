//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

int main() {
    srand(time(NULL)); // initialize random seed

    char genome[GENOME_LENGTH];

    for (int i = 0; i < GENOME_LENGTH; i++) {
        int r = rand() % 4; // generate a random number between 0 and 3
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

    printf("Generated genome sequence: %s\n", genome);

    int num_mutations;
    printf("Enter the number of mutations to introduce: ");
    scanf("%d", &num_mutations);

    for (int i = 0; i < num_mutations; i++) {
        int pos = rand() % GENOME_LENGTH; // generate a random position in the genome
        int r = rand() % 3; // generate a random number between 0 and 2 (excluding the original base)
        switch (genome[pos]) {
            case 'A':
                if (r == 0) genome[pos] = 'C';
                else if (r == 1) genome[pos] = 'G';
                else genome[pos] = 'T';
                break;
            case 'C':
                if (r == 0) genome[pos] = 'A';
                else if (r == 1) genome[pos] = 'G';
                else genome[pos] = 'T';
                break;
            case 'G':
                if (r == 0) genome[pos] = 'A';
                else if (r == 1) genome[pos] = 'C';
                else genome[pos] = 'T';
                break;
            case 'T':
                if (r == 0) genome[pos] = 'A';
                else if (r == 1) genome[pos] = 'C';
                else genome[pos] = 'G';
                break;
        }
    }

    printf("Mutated genome sequence: %s\n", genome);

    return 0;
}