//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nucleotides[4] = {'A', 'C', 'G', 'T'}; // array of nucleotides
    int sequenceLength; // length of the DNA sequence to be generated
    srand(time(NULL)); // seeding random number generator

    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Please enter the length of the DNA sequence to be generated: ");
    scanf("%d", &sequenceLength);

    char* sequence = malloc(sequenceLength * sizeof(char)); // allocate memory for sequence

    for (int i = 0; i < sequenceLength; i++) { // loop through each nucleotide in the sequence
        int randomIndex = rand() % 4; // generate a random number between 0 and 3
        sequence[i] = nucleotides[randomIndex]; // add the corresponding nucleotide to the sequence
    }

    printf("DNA sequence generated successfully:\n%s\n", sequence);

    free(sequence); // free the memory allocated for sequence
    return 0;
}