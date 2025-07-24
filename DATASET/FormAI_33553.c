//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

int main() {
    char text[1000000]; // Input text
    char word[MAX_WORD_LENGTH]; // Input word
    int nWords = 0; // Number of words in input text
    int count[MAX_WORDS]; // Array to store word frequencies
    char wordList[MAX_WORDS][MAX_WORD_LENGTH]; // Array to store unique words
    
    printf("Enter a text to count word frequency:\n");
    fgets(text, sizeof(text), stdin);
    
    // Replace newline character with null character
    text[strcspn(text, "\n")] = '\0';
    
    // Tokenize input text into words and count frequency
    char * pToken = strtok(text, " ");
    while(pToken != NULL) {
        // Convert to lowercase and strip non-alphanumeric characters
        for(int i = 0; pToken[i]; i++){
            pToken[i] = tolower(pToken[i]);
            if(!isalnum(pToken[i])) {
                pToken[i] = ' ';
            }
        }
        
        // Tokenize modified word and add to count
        char * sToken = strtok(pToken, " ");
        while(sToken != NULL) {
            // Check if word already exists in list
            int j = 0;
            for(; j < nWords; j++){
                if(strcmp(sToken, wordList[j]) == 0) {
                    count[j]++;
                    break;
                }
            }
            
            // Add new word to list and set frequency count to 1
            if(j == nWords) {
                strncpy(wordList[nWords], sToken, MAX_WORD_LENGTH);
                count[nWords++] = 1;
            }
            
            sToken = strtok(NULL, " ");
        }
        
        pToken = strtok(NULL, " ");
    }
    
    // Output word frequency counts
    printf("Word frequency count:\n");
    for(int i = 0; i < nWords; i++) {
        printf("%s: %d\n", wordList[i], count[i]);
    }
    
    return 0;
}