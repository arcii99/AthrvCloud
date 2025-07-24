//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define BASES "ACGT"

void random_sequence(char *sequence, int length){
    srand(time(0)); // Seed the random generator
    
    for(int i=0; i<length; i++){
        sequence[i] = BASES[rand() % 4]; // Choose a random base from A,C,G,T
    }
}

int main(){
    char sequence[SEQUENCE_LENGTH];
    random_sequence(sequence, SEQUENCE_LENGTH);
    
    printf("Generated sequence: %s\n", sequence);
    
    return 0;
}