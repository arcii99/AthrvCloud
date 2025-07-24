//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 10000000
#define ALPHABET_SIZE 4

const char nucleotides[] = {'A', 'C', 'G', 'T'};

int main() {
    srand(time(NULL));
    int genome_length = rand() % (MAX_GENOME_LENGTH + 1);
    char genome[genome_length];
    int i, j;

    // randomly generate genome sequence
    for (i = 0; i < genome_length; i++) {
        genome[i] = nucleotides[rand() % ALPHABET_SIZE];
    }

    // randomly introduce mutations
    int num_mutations = rand() % (genome_length / 10 + 1);
    for (i = 0; i < num_mutations; i++) {
        int mutation_pos = rand() % genome_length;
        int mutation_type = rand() % 3;
        switch (mutation_type) {
            case 0: // substitution
                genome[mutation_pos] = nucleotides[rand() % ALPHABET_SIZE];
                break;
            case 1: // insertion
                memmove(&genome[mutation_pos + 1], &genome[mutation_pos], genome_length - mutation_pos);
                genome[mutation_pos] = nucleotides[rand() % ALPHABET_SIZE];
                genome_length++;
                break;
            case 2: // deletion
                memmove(&genome[mutation_pos], &genome[mutation_pos + 1], genome_length - mutation_pos);
                genome_length--;
                break;
            default:
                break;
        }
    }

    printf("Original genome: %s\n\n", genome);

    // randomly sample reads
    int num_reads = rand() % (genome_length / 100 + 1);
    char reads[num_reads][51];
    int read_lengths[num_reads];
    for (i = 0; i < num_reads; i++) {
        int read_start = rand() % genome_length;
        int read_length = rand() % 50 + 1;
        if (read_start + read_length > genome_length) {
            read_length = genome_length - read_start;
        }
        for (j = 0; j < read_length; j++) {
            reads[i][j] = genome[read_start + j];
        }
        reads[i][read_length] = '\0';
        read_lengths[i] = read_length;
    }

    // print out reads
    printf("Sampled reads:\n");
    for (i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    return 0;
}