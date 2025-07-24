//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, wordCount;
    char sentence[1000];

    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    wordCount = 1;

    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] == ' ' && sentence[i+1] != ' ')
        {
            wordCount++;
        }
    }

    printf("The number of words in the sentence is: %d\n", wordCount);

    return 0;
}