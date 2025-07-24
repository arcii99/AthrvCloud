//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("This program will simulate the process of sequencing a certain region of your DNA.\n");

    // generate random DNA sequence
    char dna[] = "ATCG";
    int dna_length = 100000;
    char sequence[dna_length];

    srand(time(NULL));

    for (int i = 0; i < dna_length; i++) {
        int index = rand() % 4;
        sequence[i] = dna[index];
    }

    printf("Generated random DNA sequence of length %d\n", dna_length);

    // simulate sequencing process
    printf("Starting sequencing process...\n");

    int num_reads = 1000;
    int read_length = 100;
    char reads[num_reads][read_length+1];

    for (int i = 0; i < num_reads; i++) {
        int start_index = rand() % (dna_length-read_length+1);

        for (int j = 0; j < read_length; j++) {
            reads[i][j] = sequence[start_index+j];
        }

        reads[i][read_length] = '\0';
    }

    printf("Sequencing complete!\n");

    // analyze results
    printf("Analyzing sequencing results...\n");

    int num_matches = 0;
    int total_reads = 0;

    for (int i = 0; i < num_reads; i++) {
        char *result = strstr(sequence, reads[i]);

        if (result) {
            num_matches++;
        }

        total_reads++;
    }

    float match_percentage = ((float) num_matches / total_reads) * 100;

    printf("Sequencing complete!\n\n");
    printf("Results:\n");
    printf("Number of reads: %d\n", total_reads);
    printf("Number of matches: %d\n", num_matches);
    printf("Match percentage: %.2f%%\n", match_percentage);

    return 0;
}