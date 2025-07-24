//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    char bases[4] = {'A', 'C', 'G', 'T'}; // array of possible DNA bases
    
    int genome_length; // user input for length of genome
    
    printf("Enter length of genome: "); 
    scanf("%d", &genome_length);
    
    char *sequence = malloc(sizeof(char) * (genome_length + 1)); // allocate memory for sequence
    sequence[genome_length] = '\0'; // add terminating character to sequence
    
    int i;
    for (i = 0; i < genome_length; i++) {
        int random_index = rand() % 4; // generate random integer between 0 and 3
        sequence[i] = bases[random_index]; // add random base to sequence
    }
    
    printf("Generated genome sequence:\n%s", sequence);
    
    free(sequence); // free allocated memory
    
    return 0;
}