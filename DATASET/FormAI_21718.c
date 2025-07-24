//FormAI DATASET v1.0 Category: Computer Biology ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a program that demonstrates how to implement a DNA compression algorithm in C. 
 * The program takes a DNA sequence and converts it to a binary format using 2 bits per base.
 * The binary sequence can be stored in less memory and can be faster for some operations.
 */

int main() {
    char dna_seq[1000];
    int binary_seq[4000], i, j;
    printf("Enter DNA Sequence: ");
    scanf("%s", dna_seq);
    int seq_len = strlen(dna_seq);
    // Loop through each base in the DNA sequence and convert to binary
    for(i=0; i<seq_len; i++) {
        if(dna_seq[i] == 'A') {
            binary_seq[j++] = 0;
            binary_seq[j++] = 0;
        } else if(dna_seq[i] == 'C') {
            binary_seq[j++] = 0;
            binary_seq[j++] = 1;
        } else if(dna_seq[i] == 'G') {
            binary_seq[j++] = 1;
            binary_seq[j++] = 0;
        } else if(dna_seq[i] == 'T') {
            binary_seq[j++] = 1;
            binary_seq[j++] = 1;
        }
    }
    // Print the binary sequence
    printf("Binary Sequence: ");
    for(i=0; i<j; i++) {
        printf("%d", binary_seq[i]);
    }
    printf("\n");
    return 0;
}