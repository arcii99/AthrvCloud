//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100

// Function to generate random nucleotide sequence
char getRandomNucleotide() {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int randomIndex = rand() % 4;
    return nucleotides[randomIndex];
}

// Recursive function to generate DNA sequence
void generateSequence(char* sequence, int currentIndex, int sequenceLength) {
    if(currentIndex == sequenceLength) {
        printf("%s\n", sequence);
        return;
    }
    
    sequence[currentIndex] = getRandomNucleotide();
    generateSequence(sequence, currentIndex+1, sequenceLength);
}

int main() {
    srand((unsigned int) time(0)); // Seed for rand() function
    
    // Read input sequence length from user
    int sequenceLength = 0;
    printf("Enter the DNA sequence length: ");
    scanf("%d", &sequenceLength);
    
    // Validate sequence length
    if(sequenceLength <= 0 || sequenceLength > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length!\n");
        return 1;
    }
    
    char sequence[MAX_SEQUENCE_LENGTH + 1]; // +1 for null terminator
    memset(sequence, 0, sizeof(sequence)); // Initialize sequence to 0
    
    // Call recursive function to generate sequence
    generateSequence(sequence, 0, sequenceLength);
    
    return 0;
}