//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform genome sequencing simulation
void sequence_genome(char* genome, int length) {
    int i;
    for(i=0; i<length; i++) {
        int random_number = rand()%4;
        if(random_number == 0) {
            genome[i] = 'A';
        }
        else if(random_number == 1) {
            genome[i] = 'C';
        }
        else if(random_number == 2) {
            genome[i] = 'G';
        }
        else {
            genome[i] = 'T';
        }
    }
}

// Function to print genome sequence
void print_genome_sequence(char* genome, int length) {
    int i;
    for(i=0; i<length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int genome_length;
    printf("Enter the length of genome sequence to be generated: ");
    scanf("%d", &genome_length);
    if(genome_length <= 0) {
        printf("Invalid genome length!\n");
        return 0;
    }
    char* genome = (char*) malloc((genome_length+1)*sizeof(char));
    sequence_genome(genome, genome_length);
    printf("Generated genome sequence: ");
    print_genome_sequence(genome, genome_length);
    free(genome);
    return 0;
}