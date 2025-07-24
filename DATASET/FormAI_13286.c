//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10000

int main() {
    int genome[GENOME_SIZE];
    int i, j;

    /* Generate random genome sequence */
    srand(time(NULL));
    for(i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4; // Represent nucleotides using 0, 1, 2, 3
    }

    /* Print the genome sequence */
    printf("Genome Sequence:\n");
    for(i = 0; i < GENOME_SIZE; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("T");
                break;
            case 2:
                printf("C");
                break;
            case 3:
                printf("G");
                break;
            default:
                printf("N"); // Unknown nucleotide
        }
    }
    printf("\n");

    /* Calculate the percentage of each nucleotide in the genome */
    int count[4] = {0, 0, 0, 0};
    for(i = 0; i < GENOME_SIZE; i++) {
        count[genome[i]]++;
    }

    /* Print the percentage of each nucleotide */
    printf("\nNucleotide Percentage:\n");
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0:
                printf("A: ");
                break;
            case 1:
                printf("T: ");
                break;
            case 2:
                printf("C: ");
                break;
            case 3:
                printf("G: ");
                break;
        }
        printf("%.2f%%\n", (float)count[i]*100/GENOME_SIZE);
    }

    /* Find the location of a specific sequence in the genome */
    int sequence[4] = {0, 1, 2, 3}; // Example sequence: ATCG
    int seq_size = 4;
    int seq_count = 0;
    int seq_location = -1;
    for(i = 0; i < GENOME_SIZE; i++) {
        if(genome[i] == sequence[seq_count]) {
            if(seq_count == 0) {
                seq_location = i;
            }
            seq_count++;
            if(seq_count == seq_size) {
                printf("\nSequence Found!\nLocation: %d\n", seq_location);
                break;
            }
        } else {
            seq_count = 0;
            seq_location = -1;
        }
    }
    if(seq_count < seq_size) {
        printf("\nError: Sequence Not Found.\n");
    }

    return 0;
}