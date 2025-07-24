//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GENOME_LENGTH 1000

char randomNucleotide() {
    int randomNum = rand() % 4;
    switch(randomNum) {
        case 0:
            return 'A';
            break;
        case 1:
            return 'C';
            break;
        case 2:
            return 'G';
            break;
        case 3:
            return 'T';
            break;
        default:
            return 'A';
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    int numMutations = 0;
    int mutationIndex;
    char newNuc;
    bool hasMutation = false;
    
    // initialize genome with random nucleotides
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = randomNucleotide();
    }
    
    printf("Initial Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n\n");
    
    // randomly introduce mutations
    while(numMutations < 10) {
        mutationIndex = rand() % GENOME_LENGTH;
        newNuc = randomNucleotide();
        
        if(genome[mutationIndex] != newNuc) {
            genome[mutationIndex] = newNuc;
            numMutations++;
        }
    }
    
    printf("Mutated Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n\n");
    
    // find mutations and print mutation report
    printf("Mutation Report: \n");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        if(genome[i] != randomNucleotide()) {
            printf("%d: %c -> %c\n", i+1, randomNucleotide(), genome[i]);
            hasMutation = true;
        }
    }
    if(!hasMutation) {
        printf("No mutations detected.\n");
    }
    
    return 0;
}