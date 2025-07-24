//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
/*
 * Program: Protein Translation
 * Author: John Doe
 * Description: This program translates a DNA sequence into a protein sequence
 * using the genetic code table.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

/* Genetic code table */
char genetic_code[64][4] = {"UUU", "UUC", "UUA", "UUG", "CUU", "CUC", "CUA", "CUG",
                            "AUU", "AUC", "AUA", "AUG", "GUU", "GUC", "GUA", "GUG",
                            "UCU", "UCC", "UCA", "UCG", "CCU", "CCC", "CCA", "CCG",
                            "ACU", "ACC", "ACA", "ACG", "GCU", "GCC", "GCA", "GCG",
                            "UAU", "UAC", "CAU", "CAC", "CAA", "CAG", "AAU", "AAC",
                            "AAA", "AAG", "GAU", "GAC", "GAA", "GAG", "UGU", "UGC",
                            "UGG", "CGU", "CGC", "CGA", "CGG", "AGU", "AGC", "AGA",
                            "AGG", "GGU", "GGC", "GGA", "GGG"};

char protein_code[21] = {'A', 'R', 'N', 'D', 'C', 'Q', 'E', 'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V', '*'};

/* Function to convert a DNA codon to an amino acid */
char codon_to_amino_acid(char *codon) {
    int i;
    for (i = 0; i < 64; i++) {
        if (strcmp(codon, genetic_code[i]) == 0) {
            return protein_code[i/3];
        }
    }
    return '*';
}

/* Function to convert a DNA sequence to a protein sequence */
void dna_to_protein(char *dna_seq, char *protein_seq) {
    int dna_len = strlen(dna_seq);
    int i, j = 0;
    char codon[4];
    for (i = 0; i < dna_len-2; i += 3) {
        strncpy(codon, dna_seq + i, 3);
        codon[3] = '\0';
        protein_seq[j] = codon_to_amino_acid(codon);
        j++;
    }
    protein_seq[j] = '\0';
}

/* Main function */
int main() {
    char dna_seq[MAX_LEN], protein_seq[MAX_LEN/3];
    printf("Please enter a DNA sequence (max %d bases):\n", MAX_LEN);
    fgets(dna_seq, MAX_LEN, stdin);
    dna_seq[strcspn(dna_seq, "\n")] = '\0'; /* Remove newline character */
    dna_to_protein(dna_seq, protein_seq);
    printf("The corresponding protein sequence is:\n%s\n", protein_seq);
    return 0;
}