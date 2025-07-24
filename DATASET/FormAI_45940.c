//FormAI DATASET v1.0 Category: Computer Biology ; Style: content
/* This program simulates the process of DNA replication 
   and the transcription of DNA into messenger RNA */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LEN 100 // Length of DNA strand
#define RNA_LEN 50 // Length of messenger RNA strand

const char NUCLEOTIDES[] = {'A', 'C', 'G', 'T'}; // Allowed nucleotides

char DNA[DNA_LEN]; // DNA strand
char RNA[RNA_LEN]; // Messenger RNA strand

// Generate a random nucleotide from NUCLEOTIDES array
char random_nucleotide() {
    int index = rand()%4;
    return NUCLEOTIDES[index];
}

// Replicate DNA strand and create a complementary strand
void replicate_DNA() {
    printf("Original DNA strand: %s\n", DNA);
    
    char complement[DNA_LEN]; // Complementary strand
    for(int i=0; i<DNA_LEN; i++) {
        switch(DNA[i]) {
            case 'A':
                complement[i] = 'T';
                break;
            case 'T':
                complement[i] = 'A';
                break;
            case 'C':
                complement[i] = 'G';
                break;
            case 'G':
                complement[i] = 'C';
                break;
        }
    }
    
    printf("Complementary DNA strand: %s\n", complement);
    strncpy(DNA, complement, DNA_LEN); // Update original DNA strand
}

// Transcribe DNA strand into messenger RNA
void transcribe_DNA() {
    printf("Original DNA strand: %s\n", DNA);
    
    for(int i=0; i<RNA_LEN; i++) {
        char nucleotide = DNA[rand()%DNA_LEN]; // Randomly pick nucleotide from DNA strand
        RNA[i] = nucleotide;
    }
    
    printf("Messenger RNA: %s\n", RNA);
}

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Generate a DNA strand with random nucleotides
    for(int i=0; i<DNA_LEN; i++) {
        DNA[i] = random_nucleotide();
    }
    
    // Replicate DNA strand and create a complementary strand
    replicate_DNA();
    
    // Transcribe DNA strand into messenger RNA
    transcribe_DNA();
    
    return 0;
}