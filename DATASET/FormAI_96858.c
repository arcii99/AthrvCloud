//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 25
#define MAX_WORDS 5000

/* Struct for storing a word and its frequency */
struct WordFreq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

/* Function to add a word to the array of word frequencies */
int addWord(struct WordFreq *wordFreqArr, char *word) {
    int i;
    
    /* Convert word to lowercase */
    char lcWord[MAX_WORD_LENGTH];
    for (i = 0; i < strlen(word); i++) {
        lcWord[i] = tolower(word[i]);
    }
    lcWord[i] = '\0';
    
    /* Check if word is already in the array */
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordFreqArr[i].word, lcWord) == 0) {
            wordFreqArr[i].freq++;
            return i;
        }
    }
    
    /* Add the word to the array */
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFreqArr[i].freq == 0) {
            strcpy(wordFreqArr[i].word, lcWord);
            wordFreqArr[i].freq = 1;
            return i;
        }
    }
    
    /* If we get here, the array is full */
    return -1;
}

int main() {
    char inputStr[MAX_WORD_LENGTH];
    int numWords = 0;
    struct WordFreq wordFreqArr[MAX_WORDS] = {{"", 0}};
    
    printf("Enter a string of words (up to %d words, one word per line):\n", MAX_WORDS);
    while (fgets(inputStr, MAX_WORD_LENGTH, stdin) != NULL) {
        /* Strip newline character from input string */
        inputStr[strcspn(inputStr, "\n")] = 0;
        
        /* Add word to array of word frequencies */
        addWord(wordFreqArr, inputStr);
        numWords++;
        
        /* Stop getting input after MAX_WORDS words */
        if (numWords == MAX_WORDS) {
            break;
        }
    }
    
    /* Print the word frequencies */
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFreqArr[i].freq > 0) {
            printf("%s: %d\n", wordFreqArr[i].word, wordFreqArr[i].freq);
        }
    }
    
    return 0;
}