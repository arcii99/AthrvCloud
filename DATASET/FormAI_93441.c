//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random nucleotide */
char random_nucleotide() {
    int r = rand() % 4;
    switch(r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        default:
            return 'T';
    }
}

/* Recursive function to simulate genome sequencing */
void genome_sequence(char* sequence, int length) {
    if(length <= 0) { // base case, stop recursion
        return;
    }
    else {
        char n = random_nucleotide(); // generate a random nucleotide
        *sequence = n; // add the nucleotide to the sequence
        genome_sequence(sequence+1, length-1); // move to next position in sequence recursively
    }
}

/* Main function */
int main() {
    int length;
    printf("Enter the length of the genome sequence: ");
    scanf("%d", &length);
    
    srand(time(NULL)); // seed the random number generator with current time
    char* sequence = malloc(length * sizeof(char)); // allocate memory for sequence
    
    genome_sequence(sequence, length); // generate genome sequence recursively
    
    printf("The randomly generated genome sequence is:\n%s\n", sequence);
    
    free(sequence); // free the memory allocated for sequence
    
    return 0;
}