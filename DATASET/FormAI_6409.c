//FormAI DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter or not
int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to remove punctuation marks from a word
void removePunctuation(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!isLetter(word[i])) {
            for (int j = i; j < len; j++)
                word[j] = word[j+1];
            len--;
            i--;
        }
    }
}

// Function to check if two words are equal
int isEqual(char word1[], char word2[]) {
    if (strcasecmp(word1, word2) == 0)
        return 1;
    return 0;
}

// Function to search for a word in a dictionary
int searchDictionary(char word[], char dictionary[][100], int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        if (isEqual(word, dictionary[i]))
            return 1;
    }
    return 0;
}

// Function to check if a word is spelled correctly
void checkSpelling(char input[]) {
    char dictionary[][100] = {"hello", "world", "programming", "language", "computer", "science", "algorithm", "data", "structure"};
    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

    char word[100];
    int index = 0;
    int len = strlen(input);

    printf("The misspelled words in the input are:\n");

    for (int i = 0; i < len; i++) {
        if (isLetter(input[i]))
            word[index++] = tolower(input[i]);
        else {
            word[index] = '\0';

            // If word is less than 2 characters, ignore it
            if (strlen(word) < 2)
                continue;

            // Remove punctuation marks from the word
            removePunctuation(word);

            // Check if word is spelled correctly
            if (!searchDictionary(word, dictionary, dictionarySize))
                printf("%s\n", word);

            index = 0;
        }
    }

    // Check the last word in the input
    word[index] = '\0';
    if (strlen(word) >= 2) {
        removePunctuation(word);
        if (!searchDictionary(word, dictionary, dictionarySize))
            printf("%s\n", word);
    }
}

int main() {
    char input[100];

    printf("Enter some text to check for spelling errors:\n");
    fgets(input, 100, stdin);

    checkSpelling(input);

    return 0;
}