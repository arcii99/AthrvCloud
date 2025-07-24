//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 5000

int main() {
    // Generate a random DNA sequence
    char DNA[MAX_LENGTH];
    char bases[] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    for (int i = 0; i < MAX_LENGTH; i++) {
        int r = rand() % 4;
        DNA[i] = bases[r];
    }
    printf("DNA Sequence: %s\n", DNA);

    // Simulate sequencing errors
    char mutated_DNA[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        mutated_DNA[i] = DNA[i];
        // Introduce a random error with probability 0.01
        if ((double) rand() / (double) RAND_MAX < 0.01) {
            int r = rand() % 3;
            if (DNA[i] == 'A') {
                mutated_DNA[i] = bases[(r + 1) % 4];
            } else if (DNA[i] == 'C') {
                mutated_DNA[i] = bases[(r + 1) % 4];
            } else if (DNA[i] == 'G') {
                mutated_DNA[i] = bases[(r + 1) % 4];
            } else if (DNA[i] == 'T') {
                mutated_DNA[i] = bases[(r + 1) % 4];
            }
        }
    }
    printf("Mutated DNA Sequence: %s\n", mutated_DNA);

    // Simulate genome sequencing
    char reads[MAX_LENGTH][101]; //read length is assumed to be 100 and we have 5000 bases
    int n_reads = MAX_LENGTH / 100;
    int read_length = 100;
    for (int i = 0; i < n_reads; i++) {
        int start = i * read_length;
        strncpy(reads[i], mutated_DNA + start, read_length);
        reads[i][read_length] = '\0';
    }

    // Output read sequences to a file
    FILE * output_file = fopen("reads.fasta", "w");
    if (output_file != NULL) {
        for (int i = 0; i < n_reads; i++) {
            fprintf(output_file, ">read%d\n%s\n", i+1, reads[i]);
        }
        fclose(output_file);
        printf("Read sequences saved to file: reads.fasta\n");
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}