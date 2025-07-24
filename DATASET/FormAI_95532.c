//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

/*ENERGETIC C COMPUTER BIOLOGY PROGRAM*/

//Function to count the number of nucleotides in the DNA sequence
void countNucleotides(char *dnaSequence) {
    int adenineCount = 0, cytosineCount = 0, guanineCount = 0, thymineCount = 0;
    for(int i=0; dnaSequence[i]!='\0'; i++) {
        switch(dnaSequence[i]) {
            case 'A':
                adenineCount++;
                break;
            case 'C':
                cytosineCount++;
                break;
            case 'G':
                guanineCount++;
                break;
            case 'T':
                thymineCount++;
                break;
        }
    }
    printf("\n");
    printf("Number of Adenine nucleotides: %d\n", adenineCount);
    printf("Number of Cytosine nucleotides: %d\n", cytosineCount);
    printf("Number of Guanine nucleotides: %d\n", guanineCount);
    printf("Number of Thymine nucleotides: %d\n", thymineCount);
}

//Function to calculate the GC content of the DNA sequence
float calculateGCContent(char *dnaSequence) {
    int gcCount = 0;
    int totalNucleotides = 0;
    float gcContent = 0.0;
    for(int i=0; dnaSequence[i]!='\0'; i++) {
        switch(dnaSequence[i]) {
            case 'C':
            case 'G':
                gcCount++;
                break;
        }
        totalNucleotides++;
    }
    gcContent = (float)gcCount / totalNucleotides * 100;
    return gcContent;
}

int main() {
    char dnaSequence[1000];
    printf("Enter the DNA sequence:\n");
    fgets(dnaSequence, sizeof(dnaSequence), stdin);
    
    printf("The DNA sequence you entered is:\n%s\n", dnaSequence);
    
    printf("Counting Nucleotides...\n");
    countNucleotides(dnaSequence);
    
    printf("Calculating GC Content...\n");
    float gcContent = calculateGCContent(dnaSequence);
    printf("GC Content is: %.2f%%\n", gcContent);
    
    return 0;
}