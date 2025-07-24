//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MUTATION_RATE 0.01

char nucleotides[4] = {'A', 'C', 'G', 'T'};

void print_sequence(char* seq) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", seq[i]);
    }
}

void mutate_sequence(char* seq) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        double rand_num = (double) rand() / RAND_MAX;
        if (rand_num < MUTATION_RATE) {
            int rand_index = rand() % 4;
            seq[i] = nucleotides[rand_index];
        }
    }
}

int main() {
    srand(time(NULL));
    char sequence[SEQUENCE_LENGTH];
    // generate random sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int rand_index = rand() % 4;
        sequence[i] = nucleotides[rand_index];
    }
    printf("Original Sequence:\n");
    print_sequence(sequence);
    printf("\n\nMutated Sequence:\n");
    mutate_sequence(sequence);
    print_sequence(sequence);
    return 0;
}