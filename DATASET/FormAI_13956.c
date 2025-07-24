//FormAI DATASET v1.0 Category: Computer Biology ; Style: expert-level
#include <stdio.h>

// define structures to represent DNA sequences and proteins
typedef struct {
    char* bases; // the nucleotide bases of the sequence (A, C, G, T)
    int length; // the length of the sequence
} DNA;

typedef struct {
    char* amino_acids; // the amino acid sequence (A, C, D, E, F, etc.)
    int length; // the length of the sequence
} Protein;

// function to translate a DNA sequence into a protein sequence
Protein translate(DNA dna) {
    // allocate memory for the protein sequence (each codon of DNA corresponds to one amino acid)
    Protein protein;
    protein.amino_acids = malloc((dna.length / 3) + 1); // assume a stop codon at the end of the DNA sequence
    protein.length = 0;

    // iterate over each codon in the DNA sequence
    for (int i = 0; i < dna.length; i += 3) {
        char codon[4];
        strncpy(codon, dna.bases + i, 3); // extract the three bases of the codon
        codon[3] = '\0';

        // translate the codon into an amino acid
        char amino_acid;
        if (strcmp(codon, "TTT") == 0 || strcmp(codon, "TTC") == 0) {
            amino_acid = 'F';
        } else if (strcmp(codon, "TTA") == 0 || strcmp(codon, "TTG") == 0 || strcmp(codon, "CTT") == 0 ||
                   strcmp(codon, "CTC") == 0 || strcmp(codon, "CTA") == 0 || strcmp(codon, "CTG") == 0) {
            amino_acid = 'L';
        } else if (strcmp(codon, "ATT") == 0 || strcmp(codon, "ATC") == 0 || strcmp(codon, "ATA") == 0) {
            amino_acid = 'I';
        } else if (strcmp(codon, "ATG") == 0) {
            amino_acid = 'M';
        } else if (strcmp(codon, "GTT") == 0 || strcmp(codon, "GTC") == 0 || strcmp(codon, "GTA") == 0 ||
                   strcmp(codon, "GTG") == 0) {
            amino_acid = 'V';
        } else if (strcmp(codon, "TCT") == 0 || strcmp(codon, "TCC") == 0 || strcmp(codon, "TCA") == 0 ||
                   strcmp(codon, "TCG") == 0 || strcmp(codon, "AGT") == 0 || strcmp(codon, "AGC") == 0) {
            amino_acid = 'S';
        } else if (strcmp(codon, "CCT") == 0 || strcmp(codon, "CCC") == 0 || strcmp(codon, "CCA") == 0 ||
                   strcmp(codon, "CCG") == 0) {
            amino_acid = 'P';
        } else if (strcmp(codon, "ACT") == 0 || strcmp(codon, "ACC") == 0 || strcmp(codon, "ACA") == 0 ||
                   strcmp(codon, "ACG") == 0) {
            amino_acid = 'T';
        } else if (strcmp(codon, "GCT") == 0 || strcmp(codon, "GCC") == 0 || strcmp(codon, "GCA") == 0 ||
                   strcmp(codon, "GCG") == 0) {
            amino_acid = 'A';
        } else if (strcmp(codon, "TAT") == 0 || strcmp(codon, "TAC") == 0) {
            amino_acid = 'Y';
        } else if (strcmp(codon, "TAA") == 0 || strcmp(codon, "TAG") == 0 || strcmp(codon, "TGA") == 0) {
            amino_acid = '\0'; // stop codon
        } else if (strcmp(codon, "CAT") == 0 || strcmp(codon, "CAC") == 0) {
            amino_acid = 'H';
        } else if (strcmp(codon, "CAA") == 0 || strcmp(codon, "CAG") == 0) {
            amino_acid = 'Q';
        } else if (strcmp(codon, "AAT") == 0 || strcmp(codon, "AAC") == 0) {
            amino_acid = 'N';
        } else if (strcmp(codon, "AAA") == 0 || strcmp(codon, "AAG") == 0) {
            amino_acid = 'K';
        } else if (strcmp(codon, "GAT") == 0 || strcmp(codon, "GAC") == 0) {
            amino_acid = 'D';
        } else if (strcmp(codon, "GAA") == 0 || strcmp(codon, "GAG") == 0) {
            amino_acid = 'E';
        } else if (strcmp(codon, "TGT") == 0 || strcmp(codon, "TGC") == 0) {
            amino_acid = 'C';
        } else if (strcmp(codon, "TGG") == 0) {
            amino_acid = 'W';
        } else if (strcmp(codon, "CGT") == 0 || strcmp(codon, "CGC") == 0 || strcmp(codon, "CGA") == 0 ||
                   strcmp(codon, "CGG") == 0 || strcmp(codon, "AGA") == 0 || strcmp(codon, "AGG") == 0) {
            amino_acid = 'R';
        } else if (strcmp(codon, "GGT") == 0 || strcmp(codon, "GGC") == 0 || strcmp(codon, "GGA") == 0 ||
                   strcmp(codon, "GGG") == 0) {
            amino_acid = 'G';
        } else {
            printf("Invalid codon: %s\n", codon);
            exit(1);
        }

        // add the amino acid to the protein sequence
        if (amino_acid != '\0') {
            protein.amino_acids[protein.length] = amino_acid;
            protein.length++;
        } else {
            break; // stop codon reached, stop translating
        }
    }

    return protein;
}

int main() {
    // specify a DNA sequence
    DNA dna;
    dna.bases = "ATGTTATGCGACATCGTATAA";
    dna.length = strlen(dna.bases);

    // translate the DNA sequence into a protein sequence
    Protein protein = translate(dna);

    // print the protein sequence
    for (int i = 0; i < protein.length; i++) {
        printf("%c", protein.amino_acids[i]);
    }
    printf("\n");

    return 0;
}