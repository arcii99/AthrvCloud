//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate random genome sequence
char randomGenome() {
    int x = rand() % 4; // generate random number from 0 to 3
    
    if(x == 0) return 'A';
    if(x == 1) return 'C';
    if(x == 2) return 'G';
    if(x == 3) return 'T';
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    int genome_length = 100; // set genome length to 100
    
    // allocate memory for genome sequence
    char* genome = (char*)malloc((genome_length+1)*sizeof(char));
    
    // generate genome sequence randomly
    for(int i = 0; i < genome_length; i++) {
        genome[i] = randomGenome();
    }
    
    genome[genome_length] = '\0'; // set last character as null terminator
    
    printf("Generated Genome Sequence: %s\n", genome);
    
    free(genome); // free the allocated memory
    
    return 0; // end the program
}