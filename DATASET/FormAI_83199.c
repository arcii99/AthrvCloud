//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void printSequence(char* sequence) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%c", sequence[i]);
        if (i % 80 == 79) {   // break lines after every 80 characters
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));     // seed the random number generator
    char sequence[SIZE];
    int i;
    for (i = 0; i < SIZE; i++) { 
        int n = rand() % 4;  // generate random nucleotide (0=A, 1=C, 2=G, 3=T)
        if (n == 0) {
            sequence[i] = 'A';
        } else if (n == 1) {
            sequence[i] = 'C';
        } else if (n == 2) {
            sequence[i] = 'G';
        } else if (n == 3) {
            sequence[i] = 'T';
        }
    }
    printSequence(sequence);
    return 0;
}