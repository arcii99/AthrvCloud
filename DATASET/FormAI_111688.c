//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20 // Maximum length of a word
#define MAX_WORDS 10000 // Maximum number of words supported

// Global variables
int wordCount[MAX_WORDS];
char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords = 0;

// Utility function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Utility function to convert all characters in a string to lowercase
void toLowercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to add a new word to the words array
void addWord(char word[]) {
    toLowercase(word); // Convert to lowercase
    int foundWord = 0;

    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i], word) == 0) {
            wordCount[i]++;
            foundWord = 1;
            break;
        }
    }

    if (!foundWord) {
        strcpy(words[numWords], word);
        wordCount[numWords] = 1;
        numWords++;
    }
}

// Main function to count the words in the input
int main() {
    char c;
    char word[MAX_WORD_LENGTH];
    int index = 0;

    printf("Enter some text (press Ctrl+D to end):\n");

    while ((c = getchar()) != EOF) {
        if (isLetter(c)) {
            if (index == MAX_WORD_LENGTH - 1) { // Word too long, ignore
                index = 0;
                continue;
            }

            word[index++] = c;
        } else {
            if (index > 0) { // End of a word
                word[index] = '\0';
                addWord(word);
                index = 0;
            }
        }
    }

    // Print the results
    printf("\nWord Count\n");
    printf("--------------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    return 0;
}