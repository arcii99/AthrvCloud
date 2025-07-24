//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 100
#define MUTATION_RATE 0.05

void print_sequence(char seq[]) {
    printf("Current sequence: %s\n", seq);
}

void mutate_sequence(char seq[]) {
    int i, len = strlen(seq);
    for (i = 0; i < len; i++) {
        if (((double) rand() / (RAND_MAX)) < MUTATION_RATE) {
            seq[i] = (char) ('A' + rand() % 4);
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    char sequence[MAX_SEQ_LEN + 1];

    // Generate random sequence
    for (i = 0; i < MAX_SEQ_LEN; i++) {
        sequence[i] = (char) ('A' + rand() % 4);
    }
    sequence[MAX_SEQ_LEN] = '\0';
    printf("Starting sequence: %s\n", sequence);

    // Mutate sequence
    for (i = 0; i < 10; i++) {
        mutate_sequence(sequence);
        print_sequence(sequence);
    }

    return 0;
}