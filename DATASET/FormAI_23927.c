//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100 // Length of genome sequence
#define BASE_NUM 4 // Number of bases (A,C,G,T)

int main() {
    srand(time(0)); // Use current time as seed for random generator

    char dna_bases[BASE_NUM] = {'A', 'C', 'G', 'T'}; // Possible DNA bases

    char genome[LENGTH]; // Array to store genome sequence
    int i;

    // Generate genome sequence
    for (i = 0; i < LENGTH; i++) {
        int base_index = rand() % BASE_NUM; // Generate random index
        genome[i] = dna_bases[base_index]; // Set base at current index
    }

    // Print genome sequence
    printf("Genome Sequence: ");
    for (i = 0; i < LENGTH; i++) {
        printf("%c", genome[i]);
    }

    return 0;
}