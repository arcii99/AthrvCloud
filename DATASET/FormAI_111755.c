//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char text[1000]; // array to store text input
    printf("Enter text to count words:\n");
    fgets(text, 1000, stdin); // get user input

    int wordCount = 0;
    int i = 0;

    // Check every character in string
    while (text[i] != '\0')
    {
        // If current character is a space or new line or tab, it means a word just ended.
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            wordCount++; // Increase word count
        }
        i++;
    }
    // If the last character isn't space or new line or tab means there is one more word
    if(text[strlen(text)-1] != ' ' && text[strlen(text)-1] != '\n' && text[strlen(text)-1] != '\t')
    {
        wordCount++;
    }

    printf("Word count: %d\n", wordCount); // Output result
    return 0;
}