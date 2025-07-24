//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
/*
* This program calculates the hamming distance between two DNA strands
* The hamming distance refers to the number of positions at which the nucleotides are different in the two strands
*/

#include <stdio.h>
#include <string.h>

int main() {
    char dna1[50], dna2[50];
    int i, hd = 0; // hd - hamming distance

    printf("Enter the first DNA strand: ");
    scanf("%s", dna1);

    printf("Enter the second DNA strand: ");
    scanf("%s", dna2);

    if (strlen(dna1) != strlen(dna2)) {
        printf("The length of the two DNA strands are different!");
        return 1;
    }

    for (i = 0; i < strlen(dna1); i++) {
        if (dna1[i] != dna2[i]) {
            hd++;
        }
    }

    printf("The hamming distance between the two DNA strands is %d", hd);

    return 0;
}