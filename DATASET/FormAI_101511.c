//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of DNA sequence
#define MAX_SEQ_LENGTH 1000

// Define the probabilities of each base appearing
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Function to generate random DNA sequence
void generate_seq(char *seq, int length) {
    int i;
    double r;
    for (i = 0; i < length; i++) {
        r = (double)rand() / RAND_MAX;
        if (r < PROB_A) {
            seq[i] = 'A';
        } else if (r < PROB_A + PROB_C) {
            seq[i] = 'C';
        } else if (r < PROB_A + PROB_C + PROB_G) {
            seq[i] = 'G';
        } else {
            seq[i] = 'T';
        }
    }
    seq[length] = '\0';
}

// Function to print DNA sequence
void print_seq(char *seq) {
    for (int i = 0; i < strlen(seq); i++) {
        printf("%c", seq[i]);
    }
    printf("\n");
}

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Randomly generate a DNA sequence
    char seq[MAX_SEQ_LENGTH];
    generate_seq(seq, MAX_SEQ_LENGTH);
    printf("Original DNA Sequence:\n");
    print_seq(seq);

    // Simulate genome sequencing process by introducing mutations
    char seq_mut[MAX_SEQ_LENGTH];
    int num_mutations = 0;
    for (int i = 0; i < strlen(seq); i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < 0.01) {
            // introduce a mutation with probability 0.01
            r = (double)rand() / RAND_MAX;
            if (r < PROB_A) {
                seq_mut[i] = 'A';
            } else if (r < PROB_A + PROB_C) {
                seq_mut[i] = 'C';
            } else if (r < PROB_A + PROB_C + PROB_G) {
                seq_mut[i] = 'G';
            } else {
                seq_mut[i] = 'T';
            }
            num_mutations++;
        } else {
            // no mutation
            seq_mut[i] = seq[i];
        }
    }
    seq_mut[strlen(seq)] = '\0';
    printf("Mutated DNA Sequence:\n");
    print_seq(seq_mut);
    printf("Number of mutations: %d\n", num_mutations);

    return 0;
}