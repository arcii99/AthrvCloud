//FormAI DATASET v1.0 Category: Computer Biology ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 20

int main() {
    char dna[LENGTH], new_dna[LENGTH];
    srand(time(NULL));
    
    // Generate random DNA sequence
    for(int i=0; i<LENGTH; i++) {
        int num = rand() % 4; // Random number between 0 and 3
        if(num == 0) dna[i] = 'A';
        else if(num == 1) dna[i] = 'T';
        else if(num == 2) dna[i] = 'G';
        else dna[i] = 'C';
    }
    printf("Original DNA sequence: %s\n", dna);
    
    // Replicate DNA sequence
    for(int i=0; i<LENGTH; i++) {
        if(dna[i] == 'A') new_dna[i] = 'T';
        else if(dna[i] == 'T') new_dna[i] = 'A';
        else if(dna[i] == 'G') new_dna[i] = 'C';
        else new_dna[i] = 'G';
    }
    printf("Replicated DNA sequence: %s\n", new_dna);
    
    // Check for mutations
    int num_mutations = 0;
    for(int i=0; i<LENGTH; i++) {
        int num = rand() % 100; // Random number between 0 and 99
        if(num < 5) { // 5% chance of mutation
            printf("***Mutation at position %d!***\n", i);
            if(new_dna[i] == 'A') new_dna[i] = 'G';
            else if(new_dna[i] == 'T') new_dna[i] = 'C';
            else if(new_dna[i] == 'G') new_dna[i] = 'T';
            else new_dna[i] = 'A';
            num_mutations++;
        }
    }
    if(num_mutations == 0) printf("No mutations detected. DNA sequence is stable.\n");
    else if(num_mutations == 1) printf("1 mutation detected.\n");
    else printf("%d mutations detected.\n", num_mutations);
    
    // Compare original and replicated DNA sequences
    int num_differences = 0;
    for(int i=0; i<LENGTH; i++) {
        if(dna[i] != new_dna[i]) num_differences++;
    }
    if(num_differences == 0) printf("Original and replicated DNA sequences match.\n");
    else if(num_differences == 1) printf("1 difference detected between original and replicated DNA sequences.\n");
    else printf("%d differences detected between original and replicated DNA sequences.\n", num_differences);
    
    return 0;
}