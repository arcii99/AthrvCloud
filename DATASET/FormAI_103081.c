//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[1000];
    printf("Enter a string: ");
    fgets(inputStr, 1000, stdin);

    // Removing the newline character from the end of input string
    strtok(inputStr, "\n");

    int i, wordCount = 1, letterCount = 0, sentenceCount = 0;

    // Loop through the input string to count words, letters and sentences
    for(i=0; i<strlen(inputStr); i++) {
        if(inputStr[i] == ' ')
            wordCount++;
        else if(inputStr[i] == '.' || inputStr[i] == '!' || inputStr[i] == '?')
            sentenceCount++;
        else
            letterCount++;
    }
    //Calculating average words and word count per sentence
    float avgLetters = (float)letterCount/wordCount;
    float avgWords = (float)wordCount/sentenceCount;

    printf("\nWord count: %d", wordCount);
    printf("\nLetter count: %d", letterCount);
    printf("\nSentence count: %d", sentenceCount);
    printf("\nAverage letters per word: %.2f", avgLetters);
    printf("\nAverage words per sentence: %.2f", avgWords);

    return 0;
}