//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>

// Define maximum length for alien words and English translation
#define MAX_LENGTH 20

// Define struct for storing word pairs
typedef struct {
    char alienWord[MAX_LENGTH];
    char englishWord[MAX_LENGTH];
} WordPair;

// Define function to search for English word based on alien word
char* translateAlienToEnglish(WordPair pairs[], int numPairs, char alienWord[]) {
    for (int i = 0; i < numPairs; i++) {
        if (strcmp(pairs[i].alienWord, alienWord) == 0) {
            return pairs[i].englishWord;
        }
    }
    return "Translation not found";
}

// Define main function
int main() {
    // Define array of word pairs
    WordPair pairs[] = {
        {"kren", "hello"},
        {"aika", "goodbye"},
        {"plort", "thank you"},
        {"flench", "please"},
        {"grix", "sorry"},
        {"zorp", "yes"},
        {"snick", "no"}
    };
    
    // Get number of word pairs
    int numPairs = sizeof(pairs) / sizeof(WordPair);
    
    // Get user input for alien word to translate
    char alienWord[MAX_LENGTH];
    printf("Enter an alien word to translate: ");
    scanf("%s", alienWord);
    
    // Call translation function and print result
    printf("The English translation is: %s", translateAlienToEnglish(pairs, numPairs, alienWord));
    
    return 0;
}