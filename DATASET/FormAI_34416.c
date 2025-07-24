//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 10 // change this value for longer sequences
#define NUCLEOTIDES "ATCG"

int main() {
    srand(time(NULL)); // seed random number generator with current time
    char sequence[SEQUENCE_LENGTH];
    
    printf("Generating random DNA sequence of length %d...\n", SEQUENCE_LENGTH);
    
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4]; // randomly select a nucleotide from the four options
        printf("%c ", sequence[i]); // print the current nucleotide as it is generated
    }
    
    printf("\n\nSimulating genome sequencing process...\n");
    
    // simulate sequencing process by introducing errors and duplications
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int error_chance = rand() % 100; // randomly determine if an error occurs
        int duplicate_chance = rand() % 100; // randomly determine if a duplication occurs
        
        if (error_chance < 10) { // 10% chance of error
            int new_nuc = rand() % 4; // randomly select a new nucleotide
            while (new_nuc == sequence[i]) { // avoid generating the same nucleotide as before
                new_nuc = rand() % 4;
            }
            sequence[i] = NUCLEOTIDES[new_nuc];
            printf("Error at position %d: %c -> %c\n", i+1, NUCLEOTIDES[new_nuc], sequence[i]);
        }
        
        if (duplicate_chance < 5) { // 5% chance of duplication
            int dup_pos = rand() % SEQUENCE_LENGTH; // randomly select a position to duplicate
            while (dup_pos == i) { // avoid duplicating the current position
                dup_pos = rand() % SEQUENCE_LENGTH;
            }
            sequence[dup_pos] = sequence[i];
            printf("Duplication at position %d: %c -> %c\n", dup_pos+1, sequence[i], sequence[dup_pos]);
        }
    }
    
    printf("\nFinal DNA sequence after sequencing:\n\n");
    
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c ", sequence[i]); // print the final sequence
    }
    
    printf("\n");
    
    return 0;
}