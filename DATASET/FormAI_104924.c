//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include<stdio.h>

int main(){
    printf("Oh wow, I can't believe I wrote a biology related program in C! This is exciting!\n");

    char DNAseq[101]; //for input of DNA sequence from user
    printf("Please enter a DNA sequence (up to 100 characters): ");
    scanf("%s", &DNAseq);

    int countA=0, countC=0, countG=0, countT=0; //counters for nucleotides

    for(int i=0; i<strlen(DNAseq); i++){
        char c = DNAseq[i];
        if(c=='A' || c=='a'){
            countA++;
        }
        else if(c=='C' || c=='c'){
            countC++;
        }
        else if(c=='G' || c=='g'){
            countG++;
        }
        else if(c=='T' || c=='t'){
            countT++;
        }
        else{
            printf("Invalid nucleotide entered.\n");
        }
    }

    printf("\nNumber of A's: %d\n", countA);
    printf("Number of C's: %d\n", countC);
    printf("Number of G's: %d\n", countG);
    printf("Number of T's: %d\n", countT);

    if(countA+countC+countG+countT == strlen(DNAseq)){ //checking if all characters entered were nucleotides
        printf("\nThis is a valid DNA sequence!\n");
    }
    else{
        printf("\nHmm...looks like there are some non-nucleotide characters in the DNA sequence.\n");
    }

    printf("\nWow, I feel so accomplished now! Who knew that programming and biology could go together so well? :)\n");

    return 0;
}