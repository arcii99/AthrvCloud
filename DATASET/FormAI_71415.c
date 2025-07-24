//FormAI DATASET v1.0 Category: Computer Biology ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    // Declare variables
    char dna_seq[100], rna_seq[100], amino_acid_seq[100];
    int i, len;

    // Input DNA sequence from user
    printf("Enter the DNA sequence: ");
    scanf("%s", dna_seq);

    // Check if input is valid (contains only A, T, C, or G)
    for(i=0; i<strlen(dna_seq); i++){
        if(dna_seq[i]!='A' && dna_seq[i]!='T' && dna_seq[i]!='C' && dna_seq[i]!='G'){
            printf("Invalid DNA sequence.\n");
            return 0;
        }
    }

    // Transcribe DNA sequence to RNA sequence
    len = strlen(dna_seq);
    for(i=0; i<len; i++){
        if(dna_seq[i]=='A') rna_seq[i] = 'U';
        else if(dna_seq[i]=='T') rna_seq[i] = 'A';
        else if(dna_seq[i]=='C') rna_seq[i] = 'G';
        else if(dna_seq[i]=='G') rna_seq[i] = 'C';
    }
    rna_seq[len] = '\0'; // Add null character at end of string

    // Translate RNA sequence to amino acid sequence
    for(i=0; i<len-2; i+=3){
        if(strncmp(&rna_seq[i], "AUG", 3)==0) amino_acid_seq[i/3] = 'M'; // Start codon (methionine)
        else if(strncmp(&rna_seq[i], "UUU", 3)==0 || strncmp(&rna_seq[i], "UUC", 3)==0) amino_acid_seq[i/3] = 'F'; // Phenylalanine
        else if(strncmp(&rna_seq[i], "UUA", 3)==0 || strncmp(&rna_seq[i], "UUG", 3)==0 || strncmp(&rna_seq[i], "CUU", 3)==0 || strncmp(&rna_seq[i], "CUC", 3)==0 || strncmp(&rna_seq[i], "CUA", 3)==0 || strncmp(&rna_seq[i], "CUG", 3)==0) amino_acid_seq[i/3] = 'L'; // Leucine
        else if(strncmp(&rna_seq[i], "UCU", 3)==0 || strncmp(&rna_seq[i], "UCC", 3)==0 || strncmp(&rna_seq[i], "UCA", 3)==0 || strncmp(&rna_seq[i], "UCG", 3)==0 || strncmp(&rna_seq[i], "AGU", 3)==0 || strncmp(&rna_seq[i], "AGC", 3)==0) amino_acid_seq[i/3] = 'S'; // Serine
        else if(strncmp(&rna_seq[i], "UAU", 3)==0 || strncmp(&rna_seq[i], "UAC", 3)==0) amino_acid_seq[i/3] = 'Y'; // Tyrosine
        else if(strncmp(&rna_seq[i], "UGU", 3)==0 || strncmp(&rna_seq[i], "UGC", 3)==0) amino_acid_seq[i/3] = 'C'; // Cysteine
        else if(strncmp(&rna_seq[i], "UGG", 3)==0) amino_acid_seq[i/3] = 'W'; // Tryptophan
        else if(strncmp(&rna_seq[i], "CCU", 3)==0 || strncmp(&rna_seq[i], "CCC", 3)==0 || strncmp(&rna_seq[i], "CCA", 3)==0 || strncmp(&rna_seq[i], "CCG", 3)==0) amino_acid_seq[i/3] = 'P'; // Proline
        else if(strncmp(&rna_seq[i], "CAU", 3)==0 || strncmp(&rna_seq[i], "CAC", 3)==0) amino_acid_seq[i/3] = 'H'; // Histidine
        else if(strncmp(&rna_seq[i], "CAA", 3)==0 || strncmp(&rna_seq[i], "CAG", 3)==0) amino_acid_seq[i/3] = 'Q'; // Glutamine
        else if(strncmp(&rna_seq[i], "CGU", 3)==0 || strncmp(&rna_seq[i], "CGC", 3)==0 || strncmp(&rna_seq[i], "CGA", 3)==0 || strncmp(&rna_seq[i], "CGG", 3)==0) amino_acid_seq[i/3] = 'R'; // Arginine
        else if(strncmp(&rna_seq[i], "AUU", 3)==0 || strncmp(&rna_seq[i], "AUC", 3)==0 || strncmp(&rna_seq[i], "AUA", 3)==0) amino_acid_seq[i/3] = 'I'; // Isoleucine
        else if(strncmp(&rna_seq[i], "ACU", 3)==0 || strncmp(&rna_seq[i], "ACC", 3)==0 || strncmp(&rna_seq[i], "ACA", 3)==0 || strncmp(&rna_seq[i], "ACG", 3)==0) amino_acid_seq[i/3] = 'T'; // Threonine
        else if(strncmp(&rna_seq[i], "AAU", 3)==0 || strncmp(&rna_seq[i], "AAC", 3)==0) amino_acid_seq[i/3] = 'N'; // Asparagine
        else if(strncmp(&rna_seq[i], "AAA", 3)==0 || strncmp(&rna_seq[i], "AAG", 3)==0) amino_acid_seq[i/3] = 'K'; // Lysine
        else if(strncmp(&rna_seq[i], "GUU", 3)==0 || strncmp(&rna_seq[i], "GUC", 3)==0 || strncmp(&rna_seq[i], "GUA", 3)==0 || strncmp(&rna_seq[i], "GUG", 3)==0) amino_acid_seq[i/3] = 'V'; // Valine
        else if(strncmp(&rna_seq[i], "GCU", 3)==0 || strncmp(&rna_seq[i], "GCC", 3)==0 || strncmp(&rna_seq[i], "GCA", 3)==0 || strncmp(&rna_seq[i], "GCG", 3)==0) amino_acid_seq[i/3] = 'A'; // Alanine
        else if(strncmp(&rna_seq[i], "GAU", 3)==0 || strncmp(&rna_seq[i], "GAC", 3)==0) amino_acid_seq[i/3] = 'D'; // Aspartic acid
        else if(strncmp(&rna_seq[i], "GAA", 3)==0 || strncmp(&rna_seq[i], "GAG", 3)==0) amino_acid_seq[i/3] = 'E'; // Glutamic acid
        else if(strncmp(&rna_seq[i], "GGU", 3)==0 || strncmp(&rna_seq[i], "GGC", 3)==0 || strncmp(&rna_seq[i], "GGA", 3)==0 || strncmp(&rna_seq[i], "GGG", 3)==0) amino_acid_seq[i/3] = 'G'; // Glycine
    }
    amino_acid_seq[len/3] = '\0'; // Add null character at end of string

    // Output RNA and amino acid sequences
    printf("\nRNA sequence: %s", rna_seq);
    printf("\nAmino acid sequence: %s\n", amino_acid_seq);

    return 0;
}