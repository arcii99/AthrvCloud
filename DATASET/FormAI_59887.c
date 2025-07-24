//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int sequence_length, A_count = 0, C_count = 0, T_count = 0, G_count = 0;
    char nucleotide;

    // get user input for sequence length
    printf("Enter sequence length: ");
    scanf("%d", &sequence_length);

    // set seed for random number generator
    srand(time(NULL));

    // generate random nucleotides
    for(int i=0; i<sequence_length; i++){
        int random_number = rand() % 4;
        switch(random_number){
            case 0: nucleotide = 'A'; A_count++; break;
            case 1: nucleotide = 'C'; C_count++; break;
            case 2: nucleotide = 'T'; T_count++; break;
            case 3: nucleotide = 'G'; G_count++; break;
        }
        printf("%c", nucleotide);
    }

    // print nucleotide counts
    printf("\nNumber of A's: %d\n", A_count);
    printf("Number of C's: %d\n", C_count);
    printf("Number of T's: %d\n", T_count);
    printf("Number of G's: %d\n", G_count);

    return 0;
}