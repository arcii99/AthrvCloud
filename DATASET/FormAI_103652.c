//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int wordCount = 0;
    int characterCount = 0;
    int sentenceCount = 0;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Counting number of characters, words, and sentences
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' && input[i+1] != ' ') {
            wordCount++;
        }
        else if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentenceCount++;
        }
        else {
            characterCount++;
        }
    }

    // Calculating the average number of characters per word and average number of words per sentence
    float avgChar = (float)characterCount / (float)wordCount;
    float avgWord = (float)wordCount / (float)sentenceCount;

    // Displaying the results
    printf("\n----------------------------------\n");
    printf("Number of characters: %d\n", characterCount);
    printf("Number of words: %d\n", wordCount+1);
    printf("Number of sentences: %d\n", sentenceCount);
    printf("Average number of characters per word: %.2f\n", avgChar);
    printf("Average number of words per sentence: %.2f\n", avgWord);
    printf("----------------------------------\n");

    return 0;
}