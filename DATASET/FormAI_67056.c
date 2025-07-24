//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>

int main() 
{
    char sentence[1000];
    int freq[256] = {0};
    int i, ascii;

    printf("Enter any sentence: ");
    gets(sentence); // read input string from user

    for(i=0; sentence[i]!='\0'; i++) // iterate over each character in the string
    {
        ascii = (int)sentence[i]; // convert the character to its ASCII value

        if(isalpha(sentence[i])) // check if the character is an alphabet
        {
            freq[ascii]++; // increase the frequency of this alphabet's ASCII value
        }
    }

    printf("\nWord Frequency Count:\n");

    for(i=65; i<=90; i++) // iterate over capital letters A to Z
    {
        printf("%c : %d\n", i, freq[i] + freq[i+32]); // add the frequency of lowercase letters as well
    }

    return 0;
}