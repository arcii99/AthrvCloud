//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BASES 4 // number of bases in DNA
#define SEQUENCE_LENGTH 100 // length of DNA sequence

/* Definition of nucleotides */
enum base {
    A, // adenine
    C, // cytosine
    G, // guanine
    T  // thymine
};

/* Function to generate random base */
enum base generate_random_base() {
    int random_num = rand() % NUM_BASES;
    switch (random_num) {
        case 0: return A;
        case 1: return C;
        case 2: return G;
        case 3: return T;
        default: return A;
    }
}

/* Function to generate random DNA sequence */
void generate_random_sequence(enum base sequence[]) {
    for (int i=0; i<SEQUENCE_LENGTH; i++) {
        sequence[i] = generate_random_base();
    }
}

/* Function to print DNA sequence */
void print_sequence(enum base sequence[]) {
    for (int i=0; i<SEQUENCE_LENGTH; i++) {
        switch (sequence[i]) {
            case A: printf("A"); break;
            case C: printf("C"); break;
            case G: printf("G"); break;
            case T: printf("T"); break;
            default: break;
        }
    }
    printf("\n");
}

/* Main function */
int main() {
    srand(time(NULL)); // seed for random number generator
    
    enum base sequence[SEQUENCE_LENGTH];
    
    printf("Generated DNA sequence:\n");
    generate_random_sequence(sequence);
    print_sequence(sequence);
    
    return 0;
}