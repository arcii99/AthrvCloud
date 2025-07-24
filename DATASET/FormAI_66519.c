//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char bases[] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    int n = rand() % 501 + 1000;
    char sequence[n+1];

    // generate random sequence of DNA bases
    for (int i=0; i<n; i++) {
        int index = rand() % 4;
        sequence[i] = bases[index];
    }
    sequence[n] = '\0'; // terminate the sequence with null character

    // print the generated sequence
    printf("Generated DNA sequence of length %d:\n", n);
    printf("%s\n", sequence);

    // simulate genome sequencing
    printf("Simulating genome sequencing...\n");
    int read_length = rand() % 151 + 50; // generate random read length between 50 and 200
    printf("Using read length of %d...\n", read_length);
    int num_reads = n / read_length;
    if (n % read_length != 0) {
        num_reads++;
    }

    char reads[num_reads][read_length+1]; // +1 is for null character

    for (int i=0; i<num_reads; i++) {
        int start_index = i * read_length;
        int end_index = start_index + read_length;
        if (end_index > n) {
            end_index = n;
        }
        int read_length_actual = end_index - start_index;
        for (int j=0; j<read_length_actual; j++) {
            reads[i][j] = sequence[start_index+j];
        }
        reads[i][read_length_actual] = '\0'; // terminate the read with null character
    }

    // print the generated reads
    printf("Generated %d reads:\n", num_reads);
    for (int i=0; i<num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    return 0;
}