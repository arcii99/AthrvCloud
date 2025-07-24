//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define DNA nucleotides
#define NUCLEOTIDES "ATCG"

// Define struct for storing DNA sequence
typedef struct {
    char *data;
    int length;
} DNA;

// Define function to generate random DNA sequence
DNA generate_sequence(int length) {
    char *sequence = malloc(sizeof(char) * length);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }

    DNA dna;
    dna.data = sequence;
    dna.length = length;

    return dna;
}

// Define function to print DNA sequence
void print_sequence(DNA dna) {
    printf("Sequence Length: %d\n", dna.length);
    for (int i = 0; i < dna.length; i++) {
        printf("%c", dna.data[i]);
    }
    printf("\n");
}

int main() {
    int sequence_length = 10;
    DNA sequence = generate_sequence(sequence_length);
    print_sequence(sequence);

    return 0;
}