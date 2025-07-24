//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DNA_SEQUENCE_LENGTH 100
#define DNA_BASES "ATCG"
#define MUTATION_RATE 0.05

char generateBase() {
    return DNA_BASES[rand() % strlen(DNA_BASES)];
}

void generateRandomDNASequence(char *dnaSequence) {
    for (int i = 0; i < DNA_SEQUENCE_LENGTH; i++) {
        dnaSequence[i] = generateBase();
    }
}

void printDNASequence(char *dnaSequence) {
    for (int i = 0; i < DNA_SEQUENCE_LENGTH; i++) {
        printf("%c", dnaSequence[i]);
    }
    printf("\n");
}

int countMutations(char *originalSequence, char *mutatedSequence) {
    int mutations = 0;
    for (int i = 0; i < DNA_SEQUENCE_LENGTH; i++) {
        if (originalSequence[i] != mutatedSequence[i]) {
            mutations++;
        }
    }
    return mutations;
}

void mutateDNASequence(char *dnaSequence, char *mutatedSequence) {
    strcpy(mutatedSequence, dnaSequence);
    for (int i = 0; i < DNA_SEQUENCE_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            mutatedSequence[i] = generateBase();
        }
    }
}

int main() {
    srand(time(NULL));
    char originalSequence[DNA_SEQUENCE_LENGTH + 1];
    char mutatedSequence[DNA_SEQUENCE_LENGTH + 1];

    generateRandomDNASequence(originalSequence);
    printf("Original DNA Sequence: ");
    printDNASequence(originalSequence);

    mutateDNASequence(originalSequence, mutatedSequence);
    printf("Mutated DNA Sequence:   ");
    printDNASequence(mutatedSequence);
    printf("Mutations:              %i\n", countMutations(originalSequence, mutatedSequence));

    return 0;
}