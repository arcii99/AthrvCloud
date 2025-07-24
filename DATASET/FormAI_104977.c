//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[1000];
    int freq[26]={0};
    //array to store the frequency of each character. Index 0 for a, Index 1 for b and so on.

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); //gets the input sentence

    for(int i=0; i<strlen(sentence); i++)
    {
        if(isalpha(sentence[i])) //checking if the character is an alphabet
        {
            freq[tolower(sentence[i])-'a']++; //incrementing the frequency of the character
        }
    }

    printf("\nFrequency of each C/c: \n");
    printf("-----------------\n");
    printf("| Character | Frequency |\n");
    printf("-----------------\n");
    printf("|      C    |     %2d    |\n", freq['c'-'a']);
    printf("|      c    |     %2d    |\n", freq['c'-'a']);
    printf("-----------------\n");

    return 0; //program ends
}