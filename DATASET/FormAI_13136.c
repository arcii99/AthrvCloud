//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random DNA base (A, T, C, or G)
char randomBase() {
    int randNum = rand() % 4;
    switch (randNum) {
        case 0:
            return 'A';
        case 1:
            return 'T';
        case 2:
            return 'C';
        case 3:
            return 'G';
        default:
            return ' '; // should never happen
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    int genomeLength = 1000;   // length of the genome to sequence
    int numReads = 10;         // number of reads to sequence with
    int readLength = 100;      // length of each read
    char genome[genomeLength]; // the genome to sequence
    char output[readLength];   // the current read being sequenced

    // Generate the random genome
    for (int i = 0; i < genomeLength; i++) {
        genome[i] = randomBase();
    }

    // Print out the original genome
    printf("Original Genome:\n%s\n\n", genome);

    // Simulate the sequencing of the genome with the specified number of reads
    for (int i = 0; i < numReads; i++) {
        // Generate a random starting point for the read
        int start = rand() % (genomeLength - readLength);

        // Extract the read from the genome
        for (int j = 0; j < readLength; j++) {
            output[j] = genome[start + j];
        }

        // Print out the read and its starting position
        printf("Read %d Starting at Position %d:\n%s\n\n", i + 1, start, output);
    }

    return 0;
}