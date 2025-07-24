//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_SIZE 100

// Function to generate the random genome sequence
void generate_genome_sequence(char* genome_sequence) {
    int i;
    char nucleotides[] = "ACGT";
    for(i=0; i<GENOME_SIZE; i++) {
        genome_sequence[i] = nucleotides[rand() % 4];
    }
    genome_sequence[GENOME_SIZE] = '\0';
}

// Function to print the generated genome sequence
void print_genome_sequence(char* genome_sequence) {
    printf("Genome Sequence: %s\n", genome_sequence);
}

// Function to check if two genome sequences match
int check_genome_match(char* genome_sequence_a, char* genome_sequence_b) {
    int i;
    for(i=0; i<GENOME_SIZE; i++) {
        if(genome_sequence_a[i]!=genome_sequence_b[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to simulate the genome sequencing process
void genome_sequencing_simulation(char* genome_sequence_real, char* genome_sequence_sequenced) {
    int i, j, k, l;
    char match, mismatch;
    float error_probability = 0.05;
    
    printf("Simulated Genome Sequencing:\n");
    
    for(i=0; i<GENOME_SIZE; i++) {
        if((float)rand()/(float)(RAND_MAX) < error_probability) {
            // introduce an error
            mismatch = genome_sequence_real[i];
            do {
                match = "ACGT"[rand()%4];
            } while(match == mismatch);
            genome_sequence_sequenced[i] = match;
        } else {
            // no error
            genome_sequence_sequenced[i] = genome_sequence_real[i];
        }
    }
    genome_sequence_sequenced[GENOME_SIZE] = '\0';
}

// Main function
int main() {
    char genome_sequence_real[GENOME_SIZE+1], genome_sequence_sequenced[GENOME_SIZE+1];
    srand(time(NULL));
    
    // Generate the real genome sequence
    generate_genome_sequence(genome_sequence_real);
    print_genome_sequence(genome_sequence_real);
    
    // Simulate the genome sequencing process
    genome_sequencing_simulation(genome_sequence_real, genome_sequence_sequenced);
    print_genome_sequence(genome_sequence_sequenced);
    
    // Check if the real and sequenced genome sequences match
    if(check_genome_match(genome_sequence_real, genome_sequence_sequenced)) {
        printf("Sequencing Successful!\n");
    } else {
        printf("Sequencing Failed!\n");
    }
    
    return 0;
}