//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// define a struct for storing genetic information
struct DNA {
    char sequence[50];
};

// function to generate a random DNA sequence
char generateBase() {
    char bases[4] = {'A', 'T', 'C', 'G'};
    int randomIndex = rand() % 4;
    return bases[randomIndex];
}

// function to generate a random DNA sequence of length 50
struct DNA generateSequence() {
    struct DNA sequence;
    for (int i = 0; i < 50; i++) {
        sequence.sequence[i] = generateBase();
    }
    return sequence;
}

// function to calculate the difference between two DNA sequences
int calculateDifference(struct DNA sequence1, struct DNA sequence2) {
    int differences = 0;
    for (int i = 0; i < 50; i++) {
        if (sequence1.sequence[i] != sequence2.sequence[i]) {
            differences++;
        }
    }
    return differences;
}

// main function to test the program
int main() {
    srand(time(NULL)); // seed the random number generator
    
    struct DNA sequence1 = generateSequence();
    struct DNA sequence2 = generateSequence();
    
    printf("Randomly generated DNA sequence 1: %s\n", sequence1.sequence);
    printf("Randomly generated DNA sequence 2: %s\n", sequence2.sequence);
    
    int differences = calculateDifference(sequence1, sequence2);
    
    printf("The number of differences between the two DNA sequences is: %d\n", differences);
    
    return 0;
}