//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    //assuming a DNA molecule as a string
    char dna[] = "ATGGTCCCGTAGGACAGCATGCTAGCTACGTCGTAGCGATCGCTAGTACG";
    int length = strlen(dna);
    int genome[length];
    for(int i = 0; i < length; i++)
    {
        switch (dna[i])
        {
            case 'A': genome[i] = 0;
                    break;
            case 'T': genome[i] = 1;
                    break;
            case 'G': genome[i] = 2;
                    break;
            case 'C': genome[i] = 3;
                    break;
        }
    }
    int counter[4][4][4][4] = {0};
    for(int i = 0; i < length - 3; i++)
        counter[genome[i]][genome[i+1]][genome[i+2]][genome[i+3]]++;

    printf("Here's the frequency of each 4-mer:\n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                for(int l = 0; l < 4; l++)
                {
                    printf("%c%c%c%c : %d\n", 
                      i == 0 ? 'A' : (i == 1 ? 'T' : (i == 2 ? 'G' : 'C')),
                      j == 0 ? 'A' : (j == 1 ? 'T' : (j == 2 ? 'G' : 'C')),
                      k == 0 ? 'A' : (k == 1 ? 'T' : (k == 2 ? 'G' : 'C')),
                      l == 0 ? 'A' : (l == 1 ? 'T' : (l == 2 ? 'G' : 'C')), 
                      counter[i][j][k][l]);
                }
            }
        }
    }
    return 0;
}