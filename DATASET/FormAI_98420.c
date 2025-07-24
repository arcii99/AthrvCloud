//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include<string.h>
#define MAX_BUFFER_SIZE 1000

int main()
{
    char inputText[MAX_BUFFER_SIZE];
    char upcomingChar;
    int i, wordCount = 1, charCount = 0, sentenceCount = 0;
    
    printf("Enter the text to be processed:\n");
    fgets(inputText, MAX_BUFFER_SIZE, stdin);
    
    for (i = 0; inputText[i] != '\0'; i++) {
        upcomingChar = inputText[i];
        charCount++;
        if (upcomingChar == ' ') {
            wordCount++;
        }
        else if (upcomingChar == '.' || upcomingChar == '?' || upcomingChar == '!') {
            sentenceCount++;
        }
    }
    
    printf("The number of characters in the text is: %d\n", charCount-1);
    printf("The number of words in the text is: %d\n", wordCount);
    printf("The number of sentences in the text is: %d\n", sentenceCount);
    
    return 0;
}