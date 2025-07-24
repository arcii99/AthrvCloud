//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSequence(char* seq, int length){
    printf("\n\nSequence: ");
    
    for(int i = 0; i < length; i++){
        printf("%c", seq[i]);
    }
}

int main(){
    // Set the random seed.
    srand((unsigned) time(NULL));
    
    // Define the nucleotides.
    char nucleotides[4] = {'A', 'T', 'C', 'G'};
    
    // Define the length of the sequence.
    int length = 100;
    
    // Allocate memory for the sequence.
    char* sequence = (char*) malloc(length * sizeof(char));
    
    // Generate the sequence.
    for(int i = 0; i < length; i++){
        int index = rand() % 4;
        sequence[i] = nucleotides[index];
    }
    
    // Print the sequence.
    printSequence(sequence, length);
    
    // Free the memory.
    free(sequence);
    
    return 0;
}