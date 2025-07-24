//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Define the Genome sequence
    char genome[4] = {'A', 'T', 'G', 'C'};

    // Random number generator seed
    srand(time(NULL));

    // Define the size of the Genome sequence
    int sequence_size = 100;

    // Generate random sequence of genome
    char dna_sequence[sequence_size];
    for(int i = 0; i < sequence_size; i++){
        dna_sequence[i] = genome[rand() % 4];
    }

    // Print the generated sequence
    printf("DNA Sequence: %s\n\n", dna_sequence);

    // Start Genome Analysis

    // Variable to count frequency of each gene in the sequence
    int gene_freq[4] = {0};

    // Loop through the sequence and count the frequency of each gene
    for(int i = 0; i < sequence_size; i++){
        switch(dna_sequence[i]){
            case 'A': gene_freq[0]++; break;
            case 'T': gene_freq[1]++; break;
            case 'G': gene_freq[2]++; break;
            case 'C': gene_freq[3]++; break;
        }
    }

    // Print the frequency of each gene in the sequence
    printf("Analysis:\n\n");
    printf("Frequency of A: %d\n", gene_freq[0]);
    printf("Frequency of T: %d\n", gene_freq[1]);
    printf("Frequency of G: %d\n", gene_freq[2]);
    printf("Frequency of C: %d\n", gene_freq[3]);

    // Print the percentage of each gene in the sequence
    printf("\nPercentage of each gene:\n");
    printf("A: %.2f%%\n", (float)(gene_freq[0] * 100) / sequence_size);
    printf("T: %.2f%%\n", (float)(gene_freq[1] * 100) / sequence_size);
    printf("G: %.2f%%\n", (float)(gene_freq[2] * 100) / sequence_size);
    printf("C: %.2f%%\n", (float)(gene_freq[3] * 100) / sequence_size);

    return 0;
}