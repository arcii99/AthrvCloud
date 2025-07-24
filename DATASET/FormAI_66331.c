//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding random number generator with current time
    int dnaSeq[1000]; // array to represent the DNA sequence
    int i;
    for (i = 0; i < 1000; i++) {
        dnaSeq[i] = rand() % 4; // randomly assigning one of the four nucleotide bases to each element in the array
    }
    printf("DNA sequence generated:\n");
    for (i = 0; i < 1000; i++) {
        if (dnaSeq[i] == 0) {
            printf("A");
        }
        else if (dnaSeq[i] == 1) {
            printf("C");
        }
        else if (dnaSeq[i] == 2) {
            printf("G");
        }
        else {
            printf("T");
        }
    }

    printf("\n\nMutations occurring...\n\n");

    // introducing simulated mutations by randomly shifting or deleting a base
    int numMutations = rand() % 50 + 1; // random number of mutations between 1 and 50
    for (i = 0; i < numMutations; i++) {
        int mutationType = rand() % 3; // randomly choose one of three mutation types: insert, delete, or change
        int position = rand() % 1000; // randomly choose a position in the sequence to apply the mutation
        switch (mutationType) {
            case 0: // insert
                printf("Inserting a base at position %d\n", position);
                for (int j = 999; j >= position; j--) {
                    dnaSeq[j+1] = dnaSeq[j]; // shift all subsequent bases one position to the right
                }
                dnaSeq[position] = rand() % 4; // randomly assign a base to the new position
                break;
            case 1: // delete
                printf("Deleting a base from position %d\n", position);
                for (int j = position; j < 999; j++) {
                    dnaSeq[j] = dnaSeq[j+1]; // shift all subsequent bases one position to the left
                }
                dnaSeq[999] = rand() % 4; // randomly assign a new base to fill the last position
                break;
            case 2: // change
                printf("Changing base at position %d\n", position);
                dnaSeq[position] = rand() % 4; // randomly assign a new base to the selected position
                break;
        }
    }

    printf("\nMutated DNA sequence:\n");
    for (i = 0; i < 1000; i++) {
        if (dnaSeq[i] == 0) {
            printf("A");
        }
        else if (dnaSeq[i] == 1) {
            printf("C");
        }
        else if (dnaSeq[i] == 2) {
            printf("G");
        }
        else {
            printf("T");
        }
    }
    printf("\n");
    return 0;
}