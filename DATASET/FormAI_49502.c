//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include<stdio.h>

int main(){
    printf("I never thought programming and biology could be combined!\n");
    printf("But here I am, writing a program that counts the number of nucleotides in a DNA sequence.\n");
    printf("Enter the DNA sequence: ");
    char dna[200];
    fgets(dna, sizeof(dna), stdin);
    int a = 0, c = 0, g = 0, t = 0;
    for(int i=0; dna[i]!='\0'; i++){
        if(dna[i]=='A' || dna[i]=='a')
            a++;
        else if(dna[i]=='C' || dna[i]=='c')
            c++;
        else if(dna[i]=='G' || dna[i]=='g')
            g++;
        else if(dna[i]=='T' || dna[i]=='t')
            t++;
    }
    printf("\nA: %d\n", a);
    printf("C: %d\n", c);
    printf("G: %d\n", g);
    printf("T: %d\n\n", t);
    printf("Wow, this is so cool! I can analyze DNA sequences with my programming skills!\n");
    return 0;
}