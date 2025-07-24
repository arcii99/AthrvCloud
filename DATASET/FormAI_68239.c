//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// define the size of the genome and the alphabet
#define GENOME_SIZE 100
#define ALPHABET_SIZE 4
const char ALPHABET[ALPHABET_SIZE] = {'A', 'C', 'G', 'T'};

// function to generate a random genome sequence
void generate_genome_sequence(char* genome) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        int random_index = rand() % ALPHABET_SIZE;
        genome[i] = ALPHABET[random_index];
    }
    genome[GENOME_SIZE] = '\0';
}

// function to calculate the hamming distance between two genome sequences
int hamming_distance(char* genome1, char* genome2) {
    int distance = 0;
    for (int i = 0; i < GENOME_SIZE; i++) {
        if (genome1[i] != genome2[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // generate a random genome sequence
    char genome1[GENOME_SIZE+1];
    generate_genome_sequence(genome1);
    printf("Genome 1:\n%s\n\n", genome1);
    
    // generate another random genome sequence
    char genome2[GENOME_SIZE+1];
    generate_genome_sequence(genome2);
    printf("Genome 2:\n%s\n\n", genome2);
    
    // calculate the hamming distance between the two genome sequences
    int distance = hamming_distance(genome1, genome2);
    printf("Hamming distance between the two genome sequences: %d\n", distance);
    
    return 0;
}