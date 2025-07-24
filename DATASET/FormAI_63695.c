//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LEN 1000000 // Maximum sequence length
#define BASES "ATCG" // Bases for DNA sequence

char sequence[MAX_SEQ_LEN]; // Global variable to store the DNA sequence

// Generate a random DNA sequence of given length
void generate_sequence(int seq_len) {
    int i;
    for (i = 0; i < seq_len; i++) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[i] = '\0';
}

// Write the DNA sequence to a text file
void write_sequence_to_file(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s", sequence);
    fclose(file);
    printf("Sequence saved to %s\n", filename);
}

// Read the DNA sequence from a text file
void read_sequence_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fgets(sequence, MAX_SEQ_LEN, file);
    fclose(file);
    printf("Sequence loaded from %s\n", filename);
}

// Mutate a random position in the DNA sequence
void mutate_sequence() {
    int pos = rand() % strlen(sequence);
    sequence[pos] = BASES[rand() % 4];
    printf("Mutation at position %d: %s\n", pos, sequence);
}

// Print the DNA sequence
void print_sequence() {
    printf("DNA sequence:\n");
    int i;
    for (i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    generate_sequence(100);
    printf("Initial ");
    print_sequence();
    mutate_sequence();
    write_sequence_to_file("genome.txt");
    read_sequence_from_file("genome.txt");
    return 0;
}