//FormAI DATASET v1.0 Category: Computer Biology ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DNA_LENGTH 20

typedef struct {
    char nucleotide;
    int position;
} Codon;

void print_codon(Codon *codon) {
    printf("Nucleotide: %c, Position: %d\n", codon->nucleotide, codon->position);
}

int main() {
    printf("Welcome to the DNA Simulator!\n");
    printf("Generating a random section of DNA...\n");

    char nucleotides[] = {'A', 'C', 'G', 'T'};
    char *dna_sequence = malloc(DNA_LENGTH * sizeof(char));

    int i;
    for (i = 0; i < DNA_LENGTH; i++) {
        int random_index = rand() % 4; // generate a random number between 0 and 3
        dna_sequence[i] = nucleotides[random_index];
    }

    printf("DNA Sequence: %s\n", dna_sequence);

    printf("Breaking the DNA into codons...\n");

    Codon *codons = malloc((DNA_LENGTH / 3) * sizeof(Codon));

    for (i = 0; i < (DNA_LENGTH / 3); i++) {
        Codon *codon = &(codons[i]);

        codon->nucleotide = dna_sequence[i * 3];
        codon->position = i;

        printf("Codon %d: ", i + 1);
        print_codon(codon);
    }

    return 0;
}