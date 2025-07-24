//FormAI DATASET v1.0 Category: Computer Biology ; Style: introspective
#include<stdio.h>

int main()
{
    //This program accepts DNA sequence input and outputs the corresponding RNA sequence.
    
    char dna[20], rna[20];
    int i;
    
    printf("Enter the DNA sequence: ");
    scanf("%s", dna);
    
    //Converting DNA to RNA by replacing 'T' with 'U'
    for(i=0; dna[i]!='\0'; i++)
    {
        if(dna[i] == 'T')
        {
            rna[i] = 'U';
        }
        else
        {
            rna[i] = dna[i];
        }
    }
    rna[i] = '\0'; //Terminating the RNA sequence with null character
    
    printf("\nDNA sequence: %s", dna);
    printf("\nRNA sequence: %s", rna);
    
    return 0;
}