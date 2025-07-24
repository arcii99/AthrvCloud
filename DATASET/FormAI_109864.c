//FormAI DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <string.h>

// Global variables
int dictionarySize = 0;
char dictionary[1000][100];

// Function to add a word to the dictionary
void addToDictionary(char word[]) {
    if (dictionarySize < 1000) {
        strcpy(dictionary[dictionarySize], word);
        dictionarySize++;
    }
}

// Function to check if a word is in the dictionary
int checkDictionary(char word[]) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is a letter
int isLetter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}

// Function to check if a word is spelled correctly
int checkSpelling(char word[]) {
    int len = strlen(word);
    if (len == 0) {
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (!isLetter(word[i])) {
            return 0;
        }
    }
    if (checkDictionary(word)) {
        return 1;
    }
    return 0;
}

// Driver program
int main() {
    // Add words to the dictionary
    addToDictionary("hello");
    addToDictionary("world");
    addToDictionary("awesome");
    addToDictionary("fantastic");
    addToDictionary("spell");
    addToDictionary("checking");
    addToDictionary("program");
    
    // Check the spelling of some words
    printf("Checking the spelling of 'hello': %d\n", checkSpelling("hello"));
    printf("Checking the spelling of 'world': %d\n", checkSpelling("world"));
    printf("Checking the spelling of 'awesom': %d\n", checkSpelling("awesom"));
    printf("Checking the spelling of 'fantstic': %d\n", checkSpelling("fantstic"));
    printf("Checking the spelling of 'spll': %d\n", checkSpelling("spll"));
    printf("Checking the spelling of 'chcking': %d\n", checkSpelling("chcking"));
    
    return 0;
}