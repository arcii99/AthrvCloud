//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GENOME "ATCG"
#define GENOME_LEN 4

char* generate_random_sequence(int length){
    char* seq = (char*) malloc((length + 1) * sizeof(char)); // Allocate memory for sequence
    int i;
    for(i = 0; i < length; i++){
        int r = rand() % GENOME_LEN; // Generate a random index
        seq[i] = GENOME[r]; // Append the corresponding character to sequence
    }
    seq[i] = '\0'; // Append null character to end of sequence
    return seq; // Return the generated sequence
}

int main(){
    srand(time(NULL)); // Seed random number generator
    int sequence_length = 20; // Length of sequence to be generated
    char* sequence = generate_random_sequence(sequence_length); // Generate random sequence
    printf("Generated Sequence: %s\n", sequence); // Print the generated sequence
    free(sequence); // Free the memory allocated for sequence
    return 0;
}