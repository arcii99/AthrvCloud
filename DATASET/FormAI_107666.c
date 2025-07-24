//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>

// Define the length of the sequence to be generated
#define SEQUENCE_LENGTH 100

int main() {

    // Define the possible nucleotides of DNA
    char nucleotides[] = {'A', 'C', 'T', 'G'};

    // Define the sequence array
    char sequence[SEQUENCE_LENGTH];

    // Generate a random sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        // Generate a random index for nucleotides array
        int index = rand() % 4;

        // Insert the selected nucleotide in the sequence
        sequence[i] = nucleotides[index];
    }

    // Print the generated sequence
    printf("The generated DNA sequence is: ");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", sequence[i]);
    }

    // Translate the sequence to RNA
    printf("\n\nRNA sequence obtained from DNA: ");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        switch (sequence[i]) {
            case 'A':
                printf("U");
                break;
            case 'C':
                printf("G");
                break;
            case 'T':
                printf("A");
                break;
            case 'G':
                printf("C");
                break;
        }
    }

    // Translate the sequence to proteins
    printf("\n\nProtein sequence obtained from DNA:  ");
    for (int i = 0; i < SEQUENCE_LENGTH; i += 3) {
        // Define the codon from the sequence
        char codon[4] = {sequence[i], sequence[i + 1], sequence[i + 2], '\0'};

        // Translate the codon into amino acid
        char aminoAcid;
        if (strcmp(codon, "GCT") == 0 || strcmp(codon, "GCC") == 0 || strcmp(codon, "GCA") == 0 || strcmp(codon, "GCG") == 0) {
            aminoAcid = 'A';
        } else if (strcmp(codon, "CGT") == 0 || strcmp(codon, "CGC") == 0 || strcmp(codon, "CGA") == 0 || strcmp(codon, "CGG") == 0 || strcmp(codon, "AGA") == 0 || strcmp(codon, "AGG") == 0) {
            aminoAcid = 'R';
        } else if (strcmp(codon, "AAT") == 0 || strcmp(codon, "AAC") == 0) {
            aminoAcid = 'N';
        } else if (strcmp(codon, "GAT") == 0 || strcmp(codon, "GAC") == 0) {
            aminoAcid = 'D';
        } else if (strcmp(codon, "TGT") == 0 || strcmp(codon, "TGC") == 0) {
            aminoAcid = 'C';
        } else if (strcmp(codon, "CAA") == 0 || strcmp(codon, "CAG") == 0) {
            aminoAcid = 'Q';
        } else if (strcmp(codon, "GAA") == 0 || strcmp(codon, "GAG") == 0) {
            aminoAcid = 'E';
        } else if (strcmp(codon, "GGT") == 0 || strcmp(codon, "GGC") == 0 || strcmp(codon, "GGA") == 0 || strcmp(codon, "GGG") == 0) {
            aminoAcid = 'G';
        } else if (strcmp(codon, "CAT") == 0 || strcmp(codon, "CAC") == 0) {
            aminoAcid = 'H';
        } else if (strcmp(codon, "ATT") == 0 || strcmp(codon, "ATC") == 0 || strcmp(codon, "ATA") == 0) {
            aminoAcid = 'I';
        } else if (strcmp(codon, "TTA") == 0 || strcmp(codon, "TTG") == 0 || strcmp(codon, "CTT") == 0 || strcmp(codon, "CTC") == 0 || strcmp(codon, "CTA") == 0 || strcmp(codon, "CTG") == 0) {
            aminoAcid = 'L';
        } else if (strcmp(codon, "AAA") == 0 || strcmp(codon, "AAG") == 0) {
            aminoAcid = 'K';
        } else if (strcmp(codon, "ATG") == 0) {
            aminoAcid = 'M';
        } else if (strcmp(codon, "TTT") == 0 || strcmp(codon, "TTC") == 0) {
            aminoAcid = 'F';
        } else if (strcmp(codon, "CCT") == 0 || strcmp(codon, "CCC") == 0 || strcmp(codon, "CCA") == 0 || strcmp(codon, "CCG") == 0) {
            aminoAcid = 'P';
        } else if (strcmp(codon, "TCT") == 0 || strcmp(codon, "TCC") == 0 || strcmp(codon, "TCA") == 0 || strcmp(codon, "TCG") == 0 || strcmp(codon, "AGT") == 0 || strcmp(codon, "AGC") == 0) {
            aminoAcid = 'S';
        } else if (strcmp(codon, "ACT") == 0 || strcmp(codon, "ACC") == 0 || strcmp(codon, "ACA") == 0 || strcmp(codon, "ACG") == 0) {
            aminoAcid = 'T';
        } else if (strcmp(codon, "TGG") == 0) {
            aminoAcid = 'W';
        } else if (strcmp(codon, "TAT") == 0 || strcmp(codon, "TAC") == 0) {
            aminoAcid = 'Y';
        } else if (strcmp(codon, "GTT") == 0 || strcmp(codon, "GTC") == 0 || strcmp(codon, "GTA") == 0 || strcmp(codon, "GTG") == 0) {
            aminoAcid = 'V';
        } else if (strcmp(codon, "TAA") == 0 || strcmp(codon, "TAG") == 0 || strcmp(codon, "TGA") == 0) {
            aminoAcid = '*';
        }

        printf("%c", aminoAcid);
    }

    return 0;
}