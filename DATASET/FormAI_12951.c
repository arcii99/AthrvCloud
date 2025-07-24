//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
#include <stdio.h>

/* This program simulates the process of DNA replication */

int main() {

    char dnaStrand1[100];
    char complement[100];
    char dnaStrand2[100];
    int i, length;
    
    printf("Enter the DNA sequence to be replicated: ");
    scanf("%s", dnaStrand1);
    
    length = strlen(dnaStrand1);
    
    for (i = 0; i < length; i++) {
        switch(dnaStrand1[i]) {
            case 'A': complement[i] = 'T'; break;
            case 'T': complement[i] = 'A'; break;
            case 'C': complement[i] = 'G'; break;
            case 'G': complement[i] = 'C'; break;
        }
    }
    
    printf("Original DNA strand: %s\n", dnaStrand1);
    printf("Complementary strand: %s\n", complement);
    
    for (i = 0; i < length; i++) {
        switch(dnaStrand1[i]) {
            case 'A': dnaStrand2[i] = 'T'; break;
            case 'T': dnaStrand2[i] = 'A'; break;
            case 'C': dnaStrand2[i] = 'G'; break;
            case 'G': dnaStrand2[i] = 'C'; break;
        }
    }
    
    printf("Replicated DNA strand: %s\n", dnaStrand1);
    printf("Complementary strand: %s\n", dnaStrand2);
    
    return 0;
}