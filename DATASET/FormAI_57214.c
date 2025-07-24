//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int countWords(char str[]) {
    int wordCount = 0;
    int inWord = 0; // flag for whether we are currently inside a word
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            // if the current character is a whitespace character, we are no longer inside a word
            inWord = 0;
        } else if (!inWord) {
            // if the current character is not a whitespace character and we were not in a word, we are now inside a new word
            wordCount++;
            inWord = 1;
        }
    }
    return wordCount;
}

int main() {
    char inputString[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(inputString, MAX_LENGTH, stdin);
    printf("Word count: %d", countWords(inputString));
    return 0;
}