//FormAI DATASET v1.0 Category: Computer Biology ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a DNA sequence  with the possible nucleobases A, C, T, and G
    char dna[] = "ATCGGACATTCTGCTTGAAACGTAGCATAAGGGCTTCATGACCGTCAGCATGACGACGAACCTC";
    
    // Find the length of the DNA sequence
    int dna_length = 0;
    while(dna[dna_length] != '\0') {
        dna_length++;
    }
    
    // Calculate the number of each nucleobase in the DNA sequence
    int num_A = 0, num_C = 0, num_T = 0, num_G = 0;
    for(int i = 0; i < dna_length; i++) {
        if(dna[i] == 'A') {
            num_A++;
        } else if(dna[i] == 'C') {
            num_C++;
        } else if(dna[i] == 'T') {
            num_T++;
        } else if(dna[i] == 'G') {
            num_G++;
        } else {
            printf("Invalid nucleobase: %c\n", dna[i]);
        }
    }
    
    // Print out the results
    printf("DNA sequence: %s\n", dna);
    printf("Number of A nucleobases: %d\n", num_A);
    printf("Number of C nucleobases: %d\n", num_C);
    printf("Number of T nucleobases: %d\n", num_T);
    printf("Number of G nucleobases: %d\n", num_G);
    
    // Determine the GC content of the DNA sequence
    double gc_content = ((double)(num_C + num_G) / (double)dna_length) * 100;
    printf("GC content: %.2f%%\n", gc_content);
    
    return 0;
}