//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[50], word[50];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);
    printf("Enter the word to count occurrences for: ");
    scanf("%s", word);
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    
    char line[100];
    int count = 0;
    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, word))
        {
            count++;
        }
    }
    
    fclose(fp);
    
    printf("%s occurs %d times in %s", word, count, filename);
    
    return 0;
}