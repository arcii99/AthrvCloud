//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000000

int main() {
    srand(time(NULL)); // Seed the random number generator
    char genome[MAX_LENGTH]; // Initialize genome array

    // Generate random genome sequence
    for (int i = 0; i < MAX_LENGTH; i++) {
        int random_nucleotide = rand() % 4;
        switch (random_nucleotide) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }

    int kmer_size = 25; // Set k-mer size
    int occurrences[4^kmer_size]; // Initialize occurrences array
    int num_kmers = MAX_LENGTH - kmer_size + 1; // Calculate number of k-mers

    // Iterate through genome to count k-mer occurrences
    for (int i = 0; i < num_kmers; i++) {
        int kmer_index = 0;
        for (int j = 0; j < kmer_size; j++) {
            switch (genome[i+j]) {
                case 'A':
                    kmer_index = kmer_index*4 + 0;
                    break;
                case 'C':
                    kmer_index = kmer_index*4 + 1;
                    break;
                case 'G':
                    kmer_index = kmer_index*4 + 2;
                    break;
                case 'T':
                    kmer_index = kmer_index*4 + 3;
                    break;
            }
        }
        occurrences[kmer_index]++;
    }

    // Print k-mer occurrences
    printf("K-mer\tFrequency\n");
    for (int i = 0; i < 4^kmer_size; i++) {
        printf("%d\t%d\n", i, occurrences[i]);
    }

    return 0;
}