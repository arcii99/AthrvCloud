//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 10000

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Define the four nucleotides
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    
    // Create a random DNA sequence of length MAX_LENGTH
    char sequence[MAX_LENGTH];
    for (int i=0; i<MAX_LENGTH; i++) {
        int random_index = rand() % 4; // Generate a random number between 0 and 3
        sequence[i] = nucleotides[random_index];
    }
    sequence[MAX_LENGTH] = '\0'; // Add null terminator at the end of the sequence
    
    // Print the DNA sequence
    printf("DNA sequence: %s\n\n", sequence);
    
    // Define the amino acids and their corresponding codons
    char amino_acids[] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'Y'};
    char codons[][4] = {"GCA", "GCC", "GCG", "GCT", "TGC", "TGT", "GAC", "GAT", "GAA", "GAG", "TTA", "TTG", "CTA", "CTC", "CTG", "CTT", "AGA", "AGG", "TCA", "TCC", "TCG", "TCT", "ACA", "ACC", "ACG", "ACT", "GTA", "GTC", "GTG", "GTT", "CAA", "CAG", "AAT", "AAC", "CAA", "CAG", "AAA", "AAG", "TAT", "TAC", "CCA", "CCC", "CCG", "CCT", "CAA", "CAG", "CGA", "CGC", "CGG", "CGT", "AGA", "AGG", "TGG", "TAT", "TAC"};
    
    // Calculate the number of codons in the sequence
    int num_codons = MAX_LENGTH / 3;
    
    // Create an array to store the codons
    char codon_sequence[num_codons][4];
    
    // Populate the array with the codons
    int codon_index = 0;
    for (int i=0; i<MAX_LENGTH; i+=3) {
        codon_sequence[codon_index][0] = sequence[i];
        codon_sequence[codon_index][1] = sequence[i+1];
        codon_sequence[codon_index][2] = sequence[i+2];
        codon_sequence[codon_index][3] = '\0'; // Add null terminator at the end of the codon
        codon_index++;
    }
    
    // Print the codon sequence
    printf("Codon sequence:\n");
    for (int i=0; i<num_codons; i++) {
        printf("%s ", codon_sequence[i]);
    }
    printf("\n\n");
    
    // Translate the codon sequence into an amino acid sequence
    char amino_acid_sequence[num_codons];
    for (int i=0; i<num_codons; i++) {
        // Search for the codon in the codon array
        int codon_index = -1;
        for (int j=0; j<64; j++) {
            if (strcmp(codons[j], codon_sequence[i]) == 0) {
                codon_index = j;
                break;
            }
        }
        
        // Find the corresponding amino acid
        if (codon_index != -1) {
            amino_acid_sequence[i] = amino_acids[codon_index/3];
        } else {
            amino_acid_sequence[i] = 'X'; // If codon is not found, assign the amino acid 'X' (unknown)
        }
    }
    amino_acid_sequence[num_codons] = '\0'; // Add null terminator at the end of the amino acid sequence
    
    // Print the amino acid sequence
    printf("Amino acid sequence: %s\n", amino_acid_sequence);
    
    return 0;
}