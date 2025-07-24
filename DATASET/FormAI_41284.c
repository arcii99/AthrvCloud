//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int genomeLength = 1000;
    int genome[genomeLength];
    
    // initialize the genome with random nucleotides
    for (int i=0; i<genomeLength; i++) {
        genome[i] = rand() % 4; // there are 4 possible nucleotides
    }
    
    // create mutations in the genome
    int numMutations = genomeLength / 10; // introduce 10% mutations
    for (int i=0; i<numMutations; i++) {
        int mutationIndex = rand() % genomeLength; // randomly select a mutation index
        int mutationType = rand() % 3; // randomly select a mutation type
        
        // perform the mutation
        switch(mutationType) {
            case 0: // substitution mutation
                genome[mutationIndex] = rand() % 4;
                break;
                
            case 1: // insertion mutation
                for (int j=genomeLength-1; j>mutationIndex; j--) {
                    genome[j] = genome[j-1];
                }
                genome[mutationIndex] = rand() % 4;
                genomeLength++;
                break;
                
            case 2: // deletion mutation
                for (int j=mutationIndex; j<genomeLength-1; j++) {
                    genome[j] = genome[j+1];
                }
                genomeLength--;
                break;
        }
    }
    
    // print the mutated genome
    for (int i=0; i<genomeLength; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
                
            case 1:
                printf("C");
                break;
                
            case 2:
                printf("G");
                break;
                
            case 3:
                printf("T");
                break;
        }
    }
    
    return 0;
}