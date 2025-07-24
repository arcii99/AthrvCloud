//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000

int main(void) {
    char genome[MAX_GENOME_LENGTH];
    int genomeLength, deletionStart, deletionEnd, insertionIndex, numInsertions, i;

    srand(time(NULL)); // Seed the random number generator with current time

    // Generate random genome length between 500 and MAX_GENOME_LENGTH
    genomeLength = rand() % (MAX_GENOME_LENGTH - 500 + 1) + 500;

    // Fill genome with random A, C, G, T nucleotides
    for (i = 0; i < genomeLength; i++) {
        switch (rand() % 4) {
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

    printf("Generated genome sequence:\n%s\n\n", genome);

    // Randomly delete a section of the genome
    deletionStart = rand() % (genomeLength - 200 + 1); // Ensure deletion is at least 200 nucleotides
    deletionEnd = rand() % (genomeLength - deletionStart) + deletionStart;
    printf("Deleted nucleotides %d to %d (inclusive)\n\n", deletionStart, deletionEnd);
    for (i = deletionStart; i <= deletionEnd; i++) {
        genome[i] = '-';
    }

    // Randomly insert nucleotides into the deleted section
    numInsertions = rand() % 10; // Maximum of 10 insertions
    for (i = 0; i < numInsertions; i++) {
        insertionIndex = rand() % (deletionEnd - deletionStart + 1) + deletionStart;
        genome[insertionIndex] = 'A' + rand() % 4;
    }
    printf("Inserted %d random nucleotides into deleted section\n\n", numInsertions);

    // Print the final genome sequence
    printf("Final genome sequence:\n%s\n", genome);

    return 0;
}