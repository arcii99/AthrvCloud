//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Simulate a genome sequencing machine
    printf("Welcome to the Genome Sequencing Simulator!\n");
    srand(time(NULL)); // Seed the random number generator
    
    // Generate a random DNA sequence of length 100
    char dna[101];
    for(int i = 0; i < 100; i++) {
        int rand_num = rand() % 4; // Random number between 0 and 3
        if(rand_num == 0) {
            dna[i] = 'A';
        } else if(rand_num == 1) {
            dna[i] = 'C';
        } else if(rand_num == 2) {
            dna[i] = 'G';
        } else {
            dna[i] = 'T';
        }
    }
    dna[100] = '\0'; // Terminate the string
    
    // Print the original DNA sequence
    printf("Original DNA sequence: %s\n", dna);
    
    // Simulate a sequencing error
    int error_index = rand() % 100;
    int error_base = rand() % 3;
    char error_letter;
    if(error_base == 0) {
        error_letter = 'C';
    } else if(error_base == 1) {
        error_letter = 'G';
    } else {
        error_letter = 'T';
    }
    dna[error_index] = error_letter;
    
    // Print the mutated DNA sequence
    printf("Mutated DNA sequence: %s\n", dna);
    
    // Simulate a DNA sequencing machine
    for(int i = 0; i < 100; i++) {
        int rand_num = rand() % 10; // Random number between 0 and 9
        if(rand_num < 5) {
            printf("%c", dna[i]);
        } else if(rand_num == 5) {
            printf("-");
        } else if(rand_num == 6) {
            printf("A");
        } else if(rand_num == 7) {
            printf("C");
        } else if(rand_num == 8) {
            printf("G");
        } else {
            printf("T");
        }
    }
    printf("\n");
    
    // End the program
    printf("Thanks for using the Genome Sequencing Simulator!\n");
    return 0;
}