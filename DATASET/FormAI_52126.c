//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

int countWords(FILE* file)
{
    int wordCount = 0;
    char line[MAX_LINE_LENGTH];
    char* token;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        // Tokenize the line
        token = strtok(line, " ");
        
        while (token != NULL)
        {
            // Check if the token is a word
            int isWord = 1;
            int i;
            
            for (i = 0; i < strlen(token); i++)
            {
                if (!isalpha(token[i]))
                {
                    isWord = 0;
                }
            }
            
            // If the token is a word, increment the word count
            if (isWord)
            {
                wordCount++;
            }
            
            // Move to the next token
            token = strtok(NULL, " ");
        }
    }
    
    return wordCount;
}

int main(int argc, char* argv[])
{
    // Check if an argument was provided
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Open the file
    FILE* file = fopen(argv[1], "r");
    
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    
    // Count the words in the file
    int wordCount = countWords(file);
    
    // Close the file
    fclose(file);
    
    // Display the word count
    printf("Word count: %d\n", wordCount);
    
    return 0;
}