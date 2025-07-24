//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20 // maximum length of a word
#define MAX_WORDS 5000 // maximum number of unique words

int countWords(char *text, char *words[], int wordCount[]) {
    char *word;
    char *delim = " .,;:!?";
    int numWords = 0;
    
    word = strtok(text, delim); // get first word
    
    while (word != NULL) {
        // make word lowercase
        int i;
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // check if word already added to list of unique words
        int j;
        int found = 0;
        for (j = 0; j < numWords; j++) {
            if (strcmp(word, words[j]) == 0) {
                found = 1;
                break;
            }
        }
        
        if (found) { // word already exists in list
            wordCount[j]++;
        }
        else if (numWords < MAX_WORDS) { // add new word to list
            words[numWords] = strdup(word);
            wordCount[numWords] = 1;
            numWords++;
        }
        
        word = strtok(NULL, delim); // get next word
    }
    
    return numWords;
}

void printWordFrequencies(char *words[], int wordCount[], int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%-20s %d\n", words[i], wordCount[i]);
    }
}

int main() {
    char text[10000]; // buffer for input text
    char *words[MAX_WORDS]; // array of unique words
    int wordCount[MAX_WORDS] = { 0 }; // frequency count
    
    printf("Enter text: ");
    fgets(text, 10000, stdin); // read input text from user
    
    // remove newline character from input text
    int i;
    for (i = 0; text[i]; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }
    
    int numWords = countWords(text, words, wordCount);
    
    printWordFrequencies(words, wordCount, numWords);
    
    // free memory used by strdup
    for (i = 0; i < numWords; i++) {
        free(words[i]);
    }
    
    return 0;
}