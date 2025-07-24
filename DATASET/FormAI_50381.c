//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generateRandomNucleotideSequence(int sequenceSize) {
    char *nucleotideSequence = (char*) malloc((sequenceSize + 1) * sizeof(char));
    const char nucleotides[] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    for(int i = 0; i < sequenceSize; i++) {
        nucleotideSequence[i] = nucleotides[rand() % 4];
    }
    nucleotideSequence[sequenceSize] = '\0';
    return nucleotideSequence;
}

char* generateComplementarySequence(const char* nucleotideSequence) {
    int sequenceSize = strlen(nucleotideSequence);
    char *complementarySequence = (char*) malloc((sequenceSize + 1) * sizeof(char));
    for(int i = 0; i < sequenceSize; i++) {
        char c = nucleotideSequence[i];
        char comp;
        if(c == 'A') {
            comp = 'T';
        } else if(c == 'T') {
            comp = 'A';
        } else if(c == 'C') {
            comp = 'G';
        } else {
            comp = 'C';
        }
        complementarySequence[sequenceSize - 1 - i] = comp;
    }
    complementarySequence[sequenceSize] = '\0';
    return complementarySequence;
}

int main() {
    char *nucleotideSequence = generateRandomNucleotideSequence(10);
    char *complementarySequence = generateComplementarySequence(nucleotideSequence);
    printf("Nucleotide sequence: %s\n", nucleotideSequence);
    printf("Complementary sequence: %s\n", complementarySequence);
    free(nucleotideSequence);
    free(complementarySequence);
    return 0;
}