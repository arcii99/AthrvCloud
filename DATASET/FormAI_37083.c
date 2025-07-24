//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>

// Define a struct for modeling DNA
struct DNA {
    char codons[1000]; // String of nucleotide codons
    char name[50]; // Name of the gene
};

// Function to print out information about a DNA instance
void print_dna_info(struct DNA dna) {
    printf("Name: %s\n", dna.name);
    printf("Codons: %s\n", dna.codons);
}

int main() {
    // Create a new DNA instance and assign it values
    struct DNA my_dna;
    sprintf(my_dna.name, "MYC-1"); // sprintf copies the string into the name field
    sprintf(my_dna.codons, "ATGCGCA..."); // Replace these dots with your own string, each 3 letters comprise a codon
    
    // Print out information about the DNA
    print_dna_info(my_dna);
    
    return 0;
}