//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10000 // size of the genome
#define MUTATION_RATE 0.01 // probability of a single nucleotide mutation
#define SEQUENCE_LENGTH 1000 // target sequence length

// function to generate random nucleotide
char generate_nucleotide() {
    int random_num = rand() % 4;
    switch (random_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'T';
        case 3:
            return 'G';
    }
}

// function to mutate a nucleotide
char mutate_nucleotide(char nucleotide) {
    double random_num = (double)rand() / RAND_MAX; // generate a random number between 0 and 1
    if (random_num <= MUTATION_RATE) { // mutation occurs
        return generate_nucleotide(); // return a random nucleotide
    } else {
        return nucleotide; // no mutation occurs
    }
}

int main() {
    srand(time(NULL)); // set seed for random number generator with current time
    
    // initialize genome with random nucleotides
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = generate_nucleotide();
    }
    
    // generate target sequence with random starting index and length
    int start_index = rand() % GENOME_SIZE;
    int sequence_length = (rand() % SEQUENCE_LENGTH) + (SEQUENCE_LENGTH / 2);
    char target_sequence[sequence_length];
    for (int i = 0; i < sequence_length; i++) {
        target_sequence[i] = genome[(start_index + i) % GENOME_SIZE];
    }
    
    // simulate sequencing of the genome
    char sequence[sequence_length];
    for (int i = 0; i < sequence_length; i++) {
        sequence[i] = mutate_nucleotide(target_sequence[i]); // introduce mutations
    }
    
    // print results
    printf("Genome:\n");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n\nTarget Sequence (starting at index %d with length %d):\n", start_index, sequence_length);
    for (int i = 0; i < sequence_length; i++) {
        printf("%c", target_sequence[i]);
    }
    printf("\n\nSequence (result of sequencing target sequence):\n");
    for (int i = 0; i < sequence_length; i++) {
        printf("%c", sequence[i]);
    }
    
    return 0;
}