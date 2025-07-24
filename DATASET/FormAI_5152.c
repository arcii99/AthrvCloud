//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10 // length of genome sequence
#define NUM_BASE_PAIRS 4 // number of base pairs A,C,G,T

int main() {
    char genome[GENOME_LENGTH];
    srand(time(NULL)); // seed random number generator with current time
    int i;

    // randomly generate genome sequence
    for (i = 0; i < GENOME_LENGTH; i++) {
        int bp = rand() % NUM_BASE_PAIRS;
        switch (bp) {
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
            default:
                printf("Error: invalid base pair\n");
                return 1;
        }
    }

    // print generated genome sequence
    printf("Generated genome sequence: ");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // simulate sequencing of genome
    int num_errors = rand() % GENOME_LENGTH; // randomly generate number of sequencing errors
    for (i = 0; i < GENOME_LENGTH; i++) {
        char bp;
        if (i < num_errors) { // introduce sequencing error
            do {
                bp = genome[i];
            } while (bp == genome[i]); // randomly select one of the other base pairs as error
        } else { // no error introduced
            bp = genome[i];
        }
        printf("%c", bp); // print sequenced base pair
    }
    printf("\n");

    return 0;
}