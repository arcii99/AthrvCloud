//FormAI DATASET v1.0 Category: Computer Biology ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char dna[100];
    int i, j, n;

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Length of DNA sequence: %d\n", strlen(dna));

    for(i=0; dna[i]!='\0'; i++) {
        if(dna[i] == 'A') {
            printf("Adenine found at position %d\n", i+1);
        }
        else if(dna[i] == 'C') {
            printf("Cytosine found at position %d\n", i+1);
        }
        else if(dna[i] == 'G') {
            printf("Guanine found at position %d\n", i+1);
        }
        else if(dna[i] == 'T') {
            printf("Thymine found at position %d\n", i+1);
        }
        else {
            printf("Invalid DNA sequence found!\n");
            exit(0);
        }
    }

    printf("Enter the length of k-mer: ");
    scanf("%d", &n);

    for(i=0; i<=strlen(dna)-n; i++) {
        printf("k-mer %d: ", i+1);
        for(j=i; j<i+n; j++) {
            printf("%c", dna[j]);
        }
        printf("\n");
    }

    return 0;
}