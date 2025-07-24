//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Define the max length of a word
#define MAX_WORD_LEN 30

// Define the max size of the dictionary
#define MAX_DICT_SIZE 1000

// Define the struct for each word in the dictionary
typedef struct {
    char word[MAX_WORD_LEN+1];
} Word;

// Define the dictionary array
Word dict[MAX_DICT_SIZE];

// Define the number of words in the dictionary
int dictSize = 0;

// Add a word to the dictionary
void addWord(char* word) {
    // Check if the dictionary is full
    if (dictSize == MAX_DICT_SIZE) {
        printf("Sorry, the dictionary is full.\n");
        return;
    }
    
    // Add the word to the dictionary
    strcpy(dict[dictSize].word, word);
    dictSize++;
    
    printf("Yay! '%s' has been added to the dictionary.\n", word);
}

// Check if a word is in the dictionary
bool isWord(char* word) {
    // Loop through the dictionary to find a match
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return true;
        }
    }
    
    return false;
}

// Check if a character is a letter
bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Check if a word has only letters
bool hasOnlyLetters(char* word) {
    // Loop through all characters in the word
    for (int i = 0; i < strlen(word); i++) {
        if (!isLetter(word[i])) {
            return false;
        }
    }
    
    return true;
}

// Check a word for spelling errors
void checkWord(char* word) {
    // Check if the word is in the dictionary
    if (isWord(word)) {
        printf("Yay! '%s' is spelled correctly.\n", word);
        return;
    }
    
    // Check if the word has only letters
    if (!hasOnlyLetters(word)) {
        printf("Oops! '%s' contains non-letter characters.\n", word);
        return;
    }
    
    printf("Uh-oh! '%s' is not spelled correctly.\n", word);
}

// Main function
int main() {
    // Add words to the dictionary
    addWord("happy");
    addWord("joy");
    addWord("smile");
    addWord("fun");
    addWord("laughter");
    addWord("cheer");
    
    // Check words for spelling errors
    checkWord("hapy");
    checkWord("joi");
    checkWord("smaile");
    checkWord("fuun");
    checkWord("laughhter");
    checkWord("chair");
    
    return 0;
}