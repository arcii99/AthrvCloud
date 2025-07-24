//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000   // Length of the genome to simulate

int main() {
    srand(time(NULL));   // Seed the random number generator with current time

    int genome[GENOME_LENGTH];   // Declare an integer array to represent the genome

    // Generate a random genome sequence
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4;   // Assign a random nucleotide base - A, C, G or T
    }

    // Print the generated genome sequence
    printf("Generated Genome Sequence:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        switch (genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("N");   // Unknown nucleotide base
        }
    }
    printf("\n\n");

    // Simulate Genome Sequencing process
    int errors = 0;   // Count the number of errors introduced during sequencing
    int read_length = 100;   // Length of each read
    int read[read_length];   // Declare an integer array to represent each read

    printf("Sequencing Reads:\n");
    for (int i = 0; i < (GENOME_LENGTH/read_length); i++) {
        int start_pos = i * read_length;   // Calculate the starting position of each read
        for (int j = 0; j < read_length; j++) {
            read[j] = genome[start_pos + j];   // Copy each nucleotide base of the read from the genome
            // Introduce errors during sequencing with a probability of 1/10
            if (rand() % 10 == 0) {
                read[j] = rand() % 4;   // Assign a random nucleotide base
                errors++;   // Increment error count
            }
        }

        // Print the sequenced read
        printf("Read %d: ", i+1);
        for (int j = 0; j < read_length; j++) {
            switch (read[j]) {
                case 0:
                    printf("A");
                    break;
                case 1:
                    printf("C");
                    break;
                case 2:
                    printf("G");
                    break;
                case 3:
                    printf("T");
                    break;
                default:
                    printf("N");   // Unknown nucleotide base
            }
        }
        printf("\n");
    }

    // Print the sequencing error rate
    float error_rate = (float) errors / (GENOME_LENGTH/read_length);
    printf("\n\nSequencing Error Rate: %.2f%%\n", error_rate*100);

    return 0;
}