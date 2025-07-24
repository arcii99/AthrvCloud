//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000

int main() {
    int genome[GENOME_SIZE];
    int i;

    // Populate genome with random nucleotide bases (1 = A, 2 = C, 3 = G, 4 = T)
    srand(time(NULL));
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4 + 1;
    }

    // Print out genome
    printf("Genome:\n");
    for (i = 0; i < GENOME_SIZE; i++) {
        switch (genome[i]) {
            case 1:
                printf("A ");
                break;
            case 2:
                printf("C ");
                break;
            case 3:
                printf("G ");
                break;
            case 4:
                printf("T ");
                break;
        }
    }
    printf("\n");

    // Search for specified sequence in genome
    int sequence[3] = {1, 2, 3}; // Example sequence
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int match_index = -1;
    for (i = 0; i < GENOME_SIZE - sequence_length; i++) {
        if (genome[i] == sequence[0] && genome[i+1] == sequence[1] && 
            genome[i+2] == sequence[2]) {
            match_index = i;
            break;
        }
    }

    // Print out search results
    if (match_index >= 0) {
        printf("Sequence found at index %d in genome\n", match_index);
    } else {
        printf("Sequence not found in genome\n");
    }

    return 0;
}