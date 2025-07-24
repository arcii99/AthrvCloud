//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASES "ACGT"

int main() {
    int length;
    printf("Enter the length of DNA sequence to generate: ");
    scanf("%d", &length);

    srand(time(NULL));
    char dna_sequence[length+1];
    for(int i = 0; i < length; i++) {
        dna_sequence[i] = BASES[rand()%4];
    }
    dna_sequence[length] = '\0';

    printf("Generated DNA sequence: %s\n", dna_sequence);

    return 0;
}