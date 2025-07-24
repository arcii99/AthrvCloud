//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_FILE_NAME 100
#define MAX_WORD_SIZE 50
#define MAX_WORDS 100000

int countWords(const char *filename);

int main()
{
    char filename[MAX_FILE_NAME];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    int wordCount = countWords(filename);
    printf("Total words in the file: %d\n", wordCount);

    return 0;
}

int countWords(const char *filename)
{   
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int count = 0;
    char word[MAX_WORD_SIZE];

    while(fscanf(fp, "%s", word) != EOF)
    {
        count++;
    }
    fclose(fp);

    return count;
}