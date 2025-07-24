//FormAI DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char sentence[1000];
    int wordCount = 0;
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    int sentenceLength = strlen(sentence);

    for(int i=0; i<sentenceLength; i++)
    {
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t')
        {
            wordCount++;
        }
    }

    if(wordCount > 0)
    {
        wordCount++;
    }

    printf("Your sentence contains %d words.", wordCount);
    return 0;
}