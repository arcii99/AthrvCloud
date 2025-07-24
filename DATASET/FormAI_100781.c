//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function for generating random nucleotides
char random_nucleotide() {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int random_index = rand() % 4;
    return nucleotides[random_index];
}

// function for generating random DNA sequence of a given length
char* generate_DNA_sequence(int length) {
    char* sequence = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence[i] = random_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// function for printing a DNA sequence
void print_DNA_sequence(char* sequence) {
    printf("%s\n", sequence);
}

int main() {
    srand(time(NULL));  // seed the random number generator with time
    
    // generate a random DNA sequence of length 100
    char* sequence = generate_DNA_sequence(100);
    
    // print the DNA sequence
    print_DNA_sequence(sequence);
    
    // free the memory used by the DNA sequence
    free(sequence);
    
    return 0;
}