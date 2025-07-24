//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000 // Length of the genome
#define BASES { 'A', 'C', 'G', 'T' } // Possible bases of the genome

// Function to generate a random base from the possible bases
char generate_base() {
    char bases[] = BASES;
    int random_index = rand() % 4; // Random index within the length of the bases array
    return bases[random_index];
}

// Function to generate a genome sequence of a given length
void generate_sequence(char* genome, int length) {
    int i;
    for (i = 0; i < length; i++) {
        genome[i] = generate_base();
    }
}

int main() {
    char genome[GENOME_LENGTH];
    srand(time(NULL)); // Initialize random number generator with current time
    
    generate_sequence(genome, GENOME_LENGTH);
    
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    return 0;
}