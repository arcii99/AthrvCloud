//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nucleotides[] = {'A', 'C', 'G', 'T'};

void generate_sequence(char* sequence, int length) {
    int i;
    for(i = 0; i < length; i++) {
        int index = rand() % 4; // Get random nucleotide index between 0 and 3
        sequence[i] = nucleotides[index]; // Append nucleotide to sequence
    }
    sequence[length] = '\0'; // Add null terminator to end of string
}

void mutate_sequence(char* sequence, int mutation_rate) {
    int i;
    for(i = 0; i < strlen(sequence); i++) {
        int random = rand() % 100 + 1; // Get random number between 1 and 100
        if(random <= mutation_rate) {
            int index = rand() % 4;
            sequence[i] = nucleotides[index];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int sequence_size = rand() % 100 + 1; // Get random sequence size between 1 and 100
    char* sequence = malloc(sequence_size + 1); // Allocate memory for sequence string
    generate_sequence(sequence, sequence_size); // Generate random sequence
    printf("Original sequence: %s\n", sequence);
    int mutation_rate = rand() % 50 + 1; // Get random mutation rate between 1 and 50
    printf("Mutation rate: %d%%\n", mutation_rate);
    mutate_sequence(sequence, mutation_rate); // Mutate sequence
    printf("Mutated sequence: %s\n", sequence);
    free(sequence); // Deallocate memory for sequence string
    return 0;
}