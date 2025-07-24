//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[100], copy[100], reverse[100];
    int i, j, count = 0, length;

    printf("Enter a word: ");
    scanf("%s", word);

    // Making a copy of the word
    strcpy(copy, word);

    // Reversing the word
    length = strlen(word);
    for(i = length-1, j = 0; i >= 0; i--, j++)
    {
        reverse[j] = word[i];
    }
    reverse[length] = '\0';

    // Counting the number of vowels in the word
    for(i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
           word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
           word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
           word[i] == 'U')
        {
            count++;
        }
    }

    // Printing the results
    printf("\nOriginal word: %s", word);
    printf("\nCopy of word: %s", copy);
    printf("\nReverse of word: %s", reverse);
    printf("\nNumber of vowels: %d", count);

    return 0;
}