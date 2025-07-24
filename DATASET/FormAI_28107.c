//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // define genome length

int main(int argc, char *argv[]) {
    int genome[N];
    srand(time(NULL)); // seed random number generator

    // Generate random nucleotides and store in genome array
    for (int i = 0; i < N; i++) {
        genome[i] = rand() % 4; // choices are A=0, C=1, G=2, T=3
    }

    // Print out genome for confirmation
    printf("Generated Genome:\n");
    for (int i = 0; i < N; i++) {
        if (genome[i] == 0) {
            printf("A");
        } else if (genome[i] == 1) {
            printf("C");
        } else if (genome[i] == 2) {
            printf("G");
        } else {
            printf("T");
        }
    }
    printf("\n");

    // Simulate sequencing by randomly sampling sections of the genome
    int num_samples = atoi(argv[1]); // number of reads to generate
    int read_length = atoi(argv[2]); // length of each read
    printf("Simulating sequencing of %d reads with a read length of %d nucleotides...\n", num_samples, read_length);

    for (int i = 0; i < num_samples; i++) {
        int start = rand() % (N - read_length); // random starting position for read
        printf("Read %d: ", i+1);
        for (int j = start; j < (start + read_length); j++) {
            if (genome[j] == 0) {
                printf("A");
            } else if (genome[j] == 1) {
                printf("C");
            } else if (genome[j] == 2) {
                printf("G");
            } else {
                printf("T");
            }
        }
        printf("\n");
    }

    return 0;
}