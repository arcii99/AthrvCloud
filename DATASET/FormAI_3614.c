//FormAI DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countWords(char* text);
char* removePunctuations(char* text);

int main()
{
    char* inputText;
    int wordCount;
    printf("Enter text to count words: \n");
    fgets(inputText, 1000, stdin);
    inputText = removePunctuations(inputText);
    wordCount = countWords(inputText);
    printf("Total number of words in the text: %d", wordCount);
    return 0;
}

int countWords(char* text)
{
    int count = 0;
    char* word = strtok(text, " ");
    while(word != NULL)
    {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

char* removePunctuations(char* text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(ispunct(text[i]))
        {
            text[i] = ' ';
        }
    }
    return text;
}