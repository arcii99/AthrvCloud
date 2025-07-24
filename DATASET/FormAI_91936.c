//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50
#define MAX_BASES 4

char sequence[MAX_LENGTH];
char bases[MAX_BASES] = {'A', 'C', 'G', 'T'};

int main() {
    srand((unsigned int) time(NULL)); // Initialize random number generator
    int length = 0; // Initialize sequence length
    
    // Prompt user for sequence length
    printf("Enter sequence length: ");
    scanf("%d", &length);
    
    // Generate random sequence
    for(int i = 0; i < length; i++) {
        int base = rand() % MAX_BASES; // Generate random base index
        sequence[i] = bases[base]; // Append random base to sequence
    }
    
    // Print generated sequence
    printf("Generated sequence: ");
    for(int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    
    return 0;
}