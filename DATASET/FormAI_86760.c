//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000 

void summarizer(char paragraph[]); 

int main()
{
    char input[MAX_SIZE];
    printf("Enter a paragraph to summarize: \n");
    fgets(input, MAX_SIZE, stdin); 
    summarizer(input);
    return 0;
}

void summarizer(char paragraph[])
{
    char* sentence;
    int i, count = 0;
    for(i = 0; i < strlen(paragraph); i++)
    {
        if(paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!')
        {
            count++;
        }
    }
    printf("The summarized text is:\n");
    for(i = 0; i < count; i++)
    {
        sentence = strtok(paragraph, ".?!"); 
        if(sentence)
        {
            printf("%s.\n", sentence);
            paragraph += strlen(sentence) + 1; 
        }
    }
    printf("\n***The End***\n");
}