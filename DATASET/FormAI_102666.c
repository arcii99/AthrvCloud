//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
/* 'Tis but thy words that count for naught,
   This code shalt count the frequency of 'c' t'is taught.
   With love and reverence, let us begin,
   And towards completion, let us sin. */

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000 // Maximum size of string

int main()
{
    char str[MAX_SIZE];
    int freq = 0, i;
    printf("Enter the string: ");
    gets(str); // Input of string
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i] == 'c' || str[i] == 'C')
            freq++; // Incrementing freq count if 'c' or 'C' is found in string
    }
    printf("Frequency of 'c': %d", freq);
    return 0;
}
/* "Good night, good night! parting is such sweet sorrow,
   that I shall say good night till it be morrow." */