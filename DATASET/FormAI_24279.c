//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {

    int dna[10] = {1, 3, 2, 4, 1, 2, 1, 4, 3, 1}; // DNA sequence array
    int count[4] = {0, 0, 0, 0}; // count array for each nucleotide
    
    for (int i = 0; i < 10; i++) { // iterate through DNA sequence array
        
        if (dna[i] == 1) {
            count[0]++; // increment count for nucleotide A
        }
        else if (dna[i] == 2) {
            count[1]++; // increment count for nucleotide C
        }
        else if (dna[i] == 3) {
            count[2]++; // increment count for nucleotide G
        }
        else if (dna[i] == 4) {
            count[3]++; // increment count for nucleotide T
        }
    }
    
    printf("Nucleotide A count: %d\n", count[0]); // print count for nucleotide A
    printf("Nucleotide C count: %d\n", count[1]); // print count for nucleotide C
    printf("Nucleotide G count: %d\n", count[2]); // print count for nucleotide G
    printf("Nucleotide T count: %d\n", count[3]); // print count for nucleotide T
    
    return 0;
}