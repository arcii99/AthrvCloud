//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQ_LENGTH 1000
#define MUTATION_RATE 0.1
#define MAX_MUTATIONS 10

char random_base() {
    int rand_num = rand() % 4;
    switch(rand_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
    return '\0';
}

void generate_sequence(char* sequence) {
    for(int i = 0; i < SEQ_LENGTH; i++) {
        sequence[i] = random_base();
    }
    sequence[SEQ_LENGTH] = '\0';
}

void print_sequence(char* sequence) {
    printf("%s\n", sequence);
}

int generate_mutations(int* mutation_positions) {
    int num_mutations = rand() % MAX_MUTATIONS;
    for(int i = 0; i < num_mutations; i++) {
        mutation_positions[i] = rand() % SEQ_LENGTH;
    }
    return num_mutations;
}

void mutate_sequence(char* sequence, int* mutation_positions, int num_mutations) {
    for(int i = 0; i < num_mutations; i++) {
        int mutation_pos = mutation_positions[i];
        if(rand() / (double)RAND_MAX < MUTATION_RATE) {
            char original_base = sequence[mutation_pos];
            char new_base = random_base();
            while(new_base == original_base) {
                new_base = random_base();
            }
            sequence[mutation_pos] = new_base;
            printf("Mutated position %d from %c to %c\n", mutation_pos, original_base, new_base);
        }
    }
}

int compare_sequences(char* seq1, char* seq2) {
    int differences = 0;
    for(int i = 0; i < SEQ_LENGTH; i++) {
        if(seq1[i] != seq2[i]) {
            differences++;
        }
    }
    return differences;
}

int main() {
    srand((unsigned int)time(NULL));

    char original_sequence[SEQ_LENGTH + 1];
    generate_sequence(original_sequence);

    printf("Original Sequence:\n");
    print_sequence(original_sequence);

    int mutation_positions[MAX_MUTATIONS];
    int num_mutations = generate_mutations(mutation_positions);

    printf("Mutations:\n");
    for(int i = 0; i < num_mutations; i++) {
        printf("%d ", mutation_positions[i]);
    }
    printf("\n");

    char mutated_sequence[SEQ_LENGTH + 1];
    for(int i = 0; i < SEQ_LENGTH; i++) {
        mutated_sequence[i] = original_sequence[i];
    }
    mutated_sequence[SEQ_LENGTH] = '\0';

    mutate_sequence(mutated_sequence, mutation_positions, num_mutations);

    printf("Mutated Sequence:\n");
    print_sequence(mutated_sequence);

    int differences = compare_sequences(original_sequence, mutated_sequence);
    printf("Number of differences between original and mutated sequences: %d\n", differences);

    return 0;
}