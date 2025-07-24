//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
// Grateful Biology Program
// Written by a grateful chatbot
// Thank you for using this program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Grateful Biology Program!\n\n");

    // Generate random DNA sequence
    srand(time(NULL));
    char dna_seq[51];
    printf("Generating random DNA sequence...\n\n");
    for (int i = 0; i < 50; i++) {
        int random_num = rand() % 4;
        switch (random_num) {
            case 0:
                dna_seq[i] = 'A';
                break;
            case 1:
                dna_seq[i] = 'T';
                break;
            case 2:
                dna_seq[i] = 'C';
                break;
            case 3:
                dna_seq[i] = 'G';
                break;
        }
    }
    dna_seq[50] = '\0';
    printf("Random DNA sequence: %s\n\n", dna_seq);

    // Calculate GC content of DNA sequence
    int gc_count = 0;
    for (int i = 0; i < 50; i++) {
        if (dna_seq[i] == 'C' || dna_seq[i] == 'G') {
            gc_count++;
        }
    }
    double gc_content = (double) gc_count / 50.0 * 100.0;
    printf("GC content of DNA sequence: %.2lf%%\n\n", gc_content);

    // Transcribe DNA sequence to RNA sequence
    char rna_seq[51];
    printf("Transcribing DNA sequence to RNA sequence...\n\n");
    for (int i = 0; i < 50; i++) {
        if (dna_seq[i] == 'T') {
            rna_seq[i] = 'U';
        } else {
            rna_seq[i] = dna_seq[i];
        }
    }
    rna_seq[50] = '\0';
    printf("RNA sequence: %s\n\n", rna_seq);

    // Translate RNA sequence to protein sequence
    char codon_table[64][5] = {
        {"UUU"}, {"UUC"}, {"UUA"}, {"UUG"},
        {"CUU"}, {"CUC"}, {"CUA"}, {"CUG"},
        {"AUU"}, {"AUC"}, {"AUA"}, {"AUG"},
        {"GUU"}, {"GUC"}, {"GUA"}, {"GUG"},
        {"UCU"}, {"UCC"}, {"UCA"}, {"UCG"},
        {"CCU"}, {"CCC"}, {"CCA"}, {"CCG"},
        {"ACU"}, {"ACC"}, {"ACA"}, {"ACG"},
        {"GCU"}, {"GCC"}, {"GCA"}, {"GCG"},
        {"UAU"}, {"UAC"}, {"UAA"}, {"UAG"},
        {"CAU"}, {"CAC"}, {"CAA"}, {"CAG"},
        {"AAU"}, {"AAC"}, {"AAA"}, {"AAG"},
        {"GAU"}, {"GAC"}, {"GAA"}, {"GAG"},
        {"UGU"}, {"UGC"}, {"UGA"}, {"UGG"},
        {"CGU"}, {"CGC"}, {"CGA"}, {"CGG"},
        {"AGU"}, {"AGC"}, {"AGA"}, {"AGG"},
        {"GGU"}, {"GGC"}, {"GGA"}, {"GGG"}
    };
    char protein_seq[18];
    printf("Translating RNA sequence to protein sequence...\n\n");
    int protein_index = 0;
    for (int i = 0; i < 50; i += 3) {
        char codon[4] = {rna_seq[i], rna_seq[i+1], rna_seq[i+2], '\0'};
        for (int j = 0; j < 64; j++) {
            if (strcmp(codon_table[j], codon) == 0) {
                if (j == 3 || j == 7 || j == 11 || j == 15 || j == 19 || j == 23 || j == 27 ||
                    j == 31 || j == 45 || j == 49 || j == 57 || j == 61) {
                    protein_seq[protein_index] = ' ';
                } else {
                    protein_seq[protein_index] = j + 65;
                }
                protein_index++;
                break;
            }
        }
    }
    protein_seq[17] = '\0';
    printf("Protein sequence: %s\n\n", protein_seq);

    // Thank you message
    printf("Thank you for using the Grateful Biology Program!\n");
    printf("Have a grateful day!\n");

    return 0;
}