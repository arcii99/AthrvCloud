//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

/*
Helper function to check if a word contains
only alphabets and apostrophe
*/
bool isWord(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
          if ((!isalpha(word[i])) && word[i] != '\'') {
              return false;
          }
    }
    return true;
}

/*
Helper function to convert a word to lowercase
*/
void toLowercase(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    bool isTypo = false; // flag to indicate if a typo has been found
    
    printf("Enter a sentence:\n");
    fgets(line, MAX_LINE_SIZE, stdin); // read the input line
    
    int i = 0, j = 0;
    while (line[i] != '\n') {
        if (isalpha(line[i]) || line[i] == '\'') { // if the character is alphabet or apostrophe
            word[j++] = line[i]; // add it to the word
        } else if (j > 0) { // if the word has ended
            word[j] = '\0'; // add null terminator to create a string
            toLowercase(word); // convert the word to lowercase
            
            // check if the word is spelled correctly
            // if not, print an error message
            if (!isWord(word)) {
                printf("Invalid word: '%s'\n", word);
                isTypo = true; // set the flag to true
            }
            
            // reset the word and index counter for next word
            j = 0;
            memset(word, 0, sizeof(word));
        }
        i++;
    }
    
    // check if a typo has been found
    if (!isTypo) {
        printf("No typos found!\n");
    }
    
    return 0;
}