//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count the number of words in a string
int countWords(char *string)
{
    int wordCount = 0;
    char *copyString = strdup(string); // make a copy of string, so that we don't modify the original string
    
    // strtok will break the string into individual words, using space as a delimiter
    char *word = strtok(copyString, " ");
    while (word != NULL)
    {
        wordCount++;
        word = strtok(NULL, " ");
    }
    
    free(copyString); // free the memory allocated for copyString
    
    return wordCount;
}

int main()
{
    char *string = "This is a sample sentence"; // example string
    
    int wordCount = countWords(string);
    
    printf("The string contains %d words\n", wordCount);
    
    return 0;
}