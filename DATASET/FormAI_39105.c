//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LEN 1000
#define MUTATION_RATE 0.1

char nucleotides[4] = {'A', 'C', 'G', 'T'};

// Function to generate random nucleotides
char get_random_nucleotide() {
    int rand_num = rand() % 4;
    return nucleotides[rand_num];
}

// Function to generate random sequence of a given length
void generate_sequence(char sequence[], int seq_len) {
    for (int i = 0; i < seq_len; i++) {
        sequence[i] = get_random_nucleotide();
    }
}

// Function to simulate a mutation in the sequence
void simulate_mutation(char sequence[], int seq_len) {
    for (int i = 0; i < seq_len; i++) {
        double rand_num = (double)rand() / RAND_MAX;
        if (rand_num < MUTATION_RATE) {
            sequence[i] = get_random_nucleotide();
        }
    }
}

int main() {
    srand(time(NULL));
    char sequence[MAX_SEQ_LEN];
    int seq_len;
    printf("Enter length of DNA sequence: ");
    scanf("%d", &seq_len);
    if (seq_len > MAX_SEQ_LEN) {
        printf("Error: Sequence length exceeds maximum allowed length.\n");
        return 1;
    }
    generate_sequence(sequence, seq_len);
    printf("Original sequence: %s\n", sequence);
    simulate_mutation(sequence, seq_len);
    printf("Mutated sequence: %s\n", sequence);
    return 0;
}