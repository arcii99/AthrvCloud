//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100

char random_nucleotide() {
    char nucleotides[] = {'A', 'T', 'C', 'G'};
    int index = rand() % 4;
    return nucleotides[index];
}

void generate_genome(char genome[]) {
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
}

void print_genome(char genome[]) {
    for(int i=0; i<GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
}

int main() {
    char genome[GENOME_LENGTH];
    
    srand(time(NULL)); //initialize random seed
    
    generate_genome(genome);
    
    printf("Sample Sequence: ");
    print_genome(genome);
    
    return 0;
}