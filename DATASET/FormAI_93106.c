//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Hello there! Welcome to the Genome Sequencing Simulator.\n");
    printf("Generating sequence....\n\n");

    //Creating the DNA sequence
    char dnaSequence[] = {'A', 'C', 'G', 'T'};
    int dna_length = 100;
    char generatedSequence[dna_length];

    //generating DNA sequence
    srand(time(NULL));
    for(int i=0; i<dna_length; i++){
        int r = rand() % 4;
        generatedSequence[i] = dnaSequence[r];
    }

    //Printing the generated DNA sequence
    printf("The generated DNA sequence is:\n");
    for(int i=0; i<dna_length; i++){
        printf("%c ", generatedSequence[i]);
    }
    printf("\n\n");

    //Generating RNA from the generated DNA sequence
    char rnaSequence[dna_length];
    for(int i=0; i<dna_length; i++){
        if(generatedSequence[i] == 'A'){
            rnaSequence[i] = 'U';
        }
        else if(generatedSequence[i] == 'T'){
            rnaSequence[i] = 'A';
        }
        else if(generatedSequence[i] == 'C'){
            rnaSequence[i] = 'G';
        }
        else if(generatedSequence[i] == 'G'){
            rnaSequence[i] = 'C';
        }
    }

    //Printing the generated RNA sequence
    printf("The generated RNA sequence is:\n");
    for(int i=0; i<dna_length; i++){
        printf("%c ", rnaSequence[i]);
    }
    printf("\n\n");

    //Generating Protein from the generated RNA sequence
    char proteinSequence[dna_length];
    for(int i=0; i<dna_length; i+=3){
        char codon[4] = {rnaSequence[i], rnaSequence[i+1], rnaSequence[i+2], '\0'};
        if(strcmp(codon, "UUU")==0 || strcmp(codon, "UUC")==0){
            proteinSequence[i/3] = 'F'; 
        }
        else if(strcmp(codon, "UUA")==0 || strcmp(codon, "UUG")==0 || strcmp(codon, "CUU")==0 || strcmp(codon, "CUC")==0 || strcmp(codon, "CUA")==0 || strcmp(codon, "CUG")==0){
            proteinSequence[i/3] = 'L';
        }
        else if(strcmp(codon, "AUU")==0 || strcmp(codon, "AUC")==0 || strcmp(codon, "AUA")==0){
            proteinSequence[i/3] = 'I';
        }
        else if(strcmp(codon, "AUG")==0){
            proteinSequence[i/3] = 'M';
        }
        else if(strcmp(codon, "GUU")==0 || strcmp(codon, "GUC")==0 || strcmp(codon, "GUA")==0 || strcmp(codon, "GUG")==0){
            proteinSequence[i/3] = 'V';
        }
        else if(strcmp(codon, "UCU")==0 || strcmp(codon, "UCC")==0 || strcmp(codon, "UCA")==0 || strcmp(codon, "UCG")==0 || strcmp(codon, "AGU")==0 || strcmp(codon, "AGC")==0){
            proteinSequence[i/3] = 'S';
        }
        else if(strcmp(codon, "CCU")==0 || strcmp(codon, "CCC")==0 || strcmp(codon, "CCA")==0 || strcmp(codon, "CCG")==0){
            proteinSequence[i/3] = 'P';
        }
        else if(strcmp(codon, "ACU")==0 || strcmp(codon, "ACC")==0 || strcmp(codon, "ACA")==0 || strcmp(codon, "ACG")==0){
            proteinSequence[i/3] = 'T';
        }
        else if(strcmp(codon, "GCU")==0 || strcmp(codon, "GCC")==0 || strcmp(codon, "GCA")==0 || strcmp(codon, "GCG")==0){
            proteinSequence[i/3] = 'A';
        }
        else if(strcmp(codon, "UAU")==0 || strcmp(codon, "UAC")==0){
            proteinSequence[i/3] = 'Y';
        }
        else if(strcmp(codon, "UAA")==0 || strcmp(codon, "UAG")==0 || strcmp(codon, "UGA")==0){
            proteinSequence[i/3] = '.';
        }
        else if(strcmp(codon, "CAU")==0 || strcmp(codon, "CAC")==0){
            proteinSequence[i/3] = 'H';
        }
        else if(strcmp(codon, "CAA")==0 || strcmp(codon, "CAG")==0){
            proteinSequence[i/3] = 'Q';
        }
        else if(strcmp(codon, "AAU")==0 || strcmp(codon, "AAC")==0){
            proteinSequence[i/3] = 'N';
        }
        else if(strcmp(codon, "AAA")==0 || strcmp(codon, "AAG")==0){
            proteinSequence[i/3] = 'K';
        }
        else if(strcmp(codon, "GAU")==0 || strcmp(codon, "GAC")==0){
            proteinSequence[i/3] = 'D';
        }
        else if(strcmp(codon, "GAA")==0 || strcmp(codon, "GAG")==0){
            proteinSequence[i/3] = 'E';
        }
        else if(strcmp(codon, "UGU")==0 || strcmp(codon, "UGC")==0){
            proteinSequence[i/3] = 'C';
        }
        else if(strcmp(codon, "UGG")==0){
            proteinSequence[i/3] = 'W';
        }
        else if(strcmp(codon, "CGU")==0 || strcmp(codon, "CGC")==0 || strcmp(codon, "CGA")==0 || strcmp(codon, "CGG")==0 || strcmp(codon, "AGA")==0 || strcmp(codon, "AGG")==0){
            proteinSequence[i/3] = 'R';
        }
        else if(strcmp(codon, "GGU")==0 || strcmp(codon, "GGC")==0 || strcmp(codon, "GGA")==0 || strcmp(codon, "GGG")==0){
            proteinSequence[i/3] = 'G';
        }
    }

    //Printing the generated Protein sequence
    printf("The generated Protein sequence is:\n");
    for(int i=0; i<dna_length; i+=3){
        printf("%c ", proteinSequence[i/3]);
    }
    printf("\n");

    printf("Thank you for using Genome Sequencing Simulator. Have a nice day!\n\n");

    return 0;
}