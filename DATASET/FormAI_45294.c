//FormAI DATASET v1.0 Category: Computer Biology ; Style: relaxed
#include <stdio.h>

// Define a DNA sequence as a character array
char sequence[] = "AGTCCATCGGTCACGAGCTAGCTGTGCTCGATAGTCTGCAGTGTAGCTAGCT";

/*
 * Function to count the number of occurrences of a specific nucleotide in the DNA sequence
 * Parameters:
 *   nucleotide: character representing the nucleotide to count (A,C,G,T)
 * Return value:
 *   integer representing the count of the specified nucleotide
 */
int countNucleotide(char nucleotide) {
    int count = 0; // Initialize count to 0
    
    for (int i = 0; i < sizeof(sequence); i++) {
        if (sequence[i] == nucleotide) { // If the current character is the specified nucleotide
            count++; // Increment the count
        }
    }
  
    return count;
}

int main() {
    // Print the DNA sequence
    printf("DNA sequence: %s\n", sequence);
  
    // Count the occurrences of each nucleotide and print the results
    printf("A count: %d\n", countNucleotide('A'));
    printf("C count: %d\n", countNucleotide('C'));
    printf("G count: %d\n", countNucleotide('G'));
    printf("T count: %d\n", countNucleotide('T'));
  
    return 0;
}