//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int genome_length = 100000;
    char genome[genome_length]; // creating a character array to represent genome

    // randomly selecting bases to populate the genome
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < genome_length; i++) {
        int base = rand() % 4; // there are four possible bases: A, C, G, T
        if (base == 0) {
            genome[i] = 'A';
        } else if (base == 1) {
            genome[i] = 'C';
        } else if (base == 2) {
            genome[i] = 'G';
        } else {
            genome[i] = 'T';
        }
    }

    // outputting the genome
    printf("GENOME SEQUENCE:\n");
    for (i = 0; i < genome_length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // counting the number of each base in the genome
    int count_A = 0, count_C = 0, count_G = 0, count_T = 0;
    for (i = 0; i < genome_length; i++) {
        if (genome[i] == 'A') {
            count_A++;
        } else if (genome[i] == 'C') {
            count_C++;
        } else if (genome[i] == 'G') {
            count_G++;
        } else if (genome[i] == 'T') {
            count_T++;
        }
    }

    // outputting the base counts
    printf("BASE COUNTS:\n");
    printf("A: %d\n", count_A);
    printf("C: %d\n", count_C);
    printf("G: %d\n", count_G);
    printf("T: %d\n", count_T);

    return 0;
}