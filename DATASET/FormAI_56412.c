//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate random sequence of nucleotides
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    int sequenceLength = rand() % 100 + 1;
    char sequence[sequenceLength];
    for (int i = 0; i < sequenceLength; i++) {
        int index = rand() % 4; 
        sequence[i] = nucleotides[index];
    }

    // Print generated sequence
    printf("Original Sequence: %s\n", sequence);

    // Mutate sequence with given probability
    int mutationProbability = rand() % 20 + 1;
    for (int i = 0; i < sequenceLength; i++) {
        int mutationChance = rand() % 100 + 1;
        if (mutationChance <= mutationProbability) {
            int index = rand() % 4;
            while (nucleotides[index] == sequence[i]) {
                index = rand() % 4;
            }
            sequence[i] = nucleotides[index];
        }
    }

    // Print mutated sequence
    printf("Mutated Sequence: %s\n", sequence);

    return 0;
}