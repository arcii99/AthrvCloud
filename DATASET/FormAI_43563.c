//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 100

// Generate random genome sequence
char* generate_genome_sequence(int size) {
    char* genome = (char*)malloc(sizeof(char) * size);
    if (genome == NULL) {
        printf("Failed to allocate memory for genome sequence.\n");
        return NULL;
    }

    int i;
    for (i = 0; i < size; i++) {
        int rand_num = rand() % 4;
        if (rand_num == 0) { genome[i] = 'A'; }
        else if (rand_num == 1) { genome[i] = 'C'; }
        else if (rand_num == 2) { genome[i] = 'G'; }
        else if (rand_num == 3) { genome[i] = 'T'; }
    }

    return genome;
}

// Print genome sequence to console
void print_genome_sequence(char* genome, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

// Mutate genome sequence by randomly replacing nucleotides
void mutate_genome_sequence(char* genome, int size, int mutation_rate) {
    int i;
    for (i = 0; i < size; i++) {
        int rand_num = rand() % 100;
        if (rand_num < mutation_rate) {
            rand_num = rand() % 3;
            if (rand_num == 0) { genome[i] = 'A'; }
            else if (rand_num == 1) { genome[i] = 'C'; }
            else if (rand_num == 2) { genome[i] = 'G'; }
            else if (rand_num == 3) { genome[i] = 'T'; }
        }
    }
}

int main() {
    // Set up random number generator
    srand(time(NULL));

    // Generate initial genome sequence
    char* genome = generate_genome_sequence(GENOME_SIZE);
    if (genome == NULL) {
        return 1;
    }

    // Print initial genome sequence
    printf("Initial genome sequence: ");
    print_genome_sequence(genome, GENOME_SIZE);

    // Mutate genome sequence
    mutate_genome_sequence(genome, GENOME_SIZE, 10);

    // Print mutated genome sequence
    printf("Mutated genome sequence: ");
    print_genome_sequence(genome, GENOME_SIZE);

    // Free memory allocated for genome sequence
    free(genome);
    genome = NULL;

    return 0;
}