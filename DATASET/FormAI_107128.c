//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 20 // Maximum length of a word (excluding null terminator)
#define MAX_NUM_WORDS 5000 // Maximum number of unique words to store

// A struct to store information about a word
struct WordInfo {
    char word[MAX_WORD_LEN + 1];
    int frequency;
};

int main() {
    struct WordInfo words[MAX_NUM_WORDS]; // Array to store word info
    int numWords = 0; // Number of unique words found
    char curWord[MAX_WORD_LEN + 1]; // Buffer to store current word
    char curChar; // Buffer to store current character
    int curCharIndex = 0; // Index within current word
    int i, j; // Loop indices

    FILE *inputFile = fopen("input.txt", "r"); // Open input file for reading
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read file character by character
    while ((curChar = fgetc(inputFile)) != EOF) {
        if (isspace(curChar) || ispunct(curChar)) { // If current character is whitespace or punctuation
            if (curCharIndex > 0) { // If current word is not empty
                // Convert current word to lowercase
                for (i = 0; i < curCharIndex; i++) {
                    curWord[i] = tolower(curWord[i]);
                }
                curWord[curCharIndex] = '\0'; // Null-terminate the word

                // Check if current word already exists in words array
                for (i = 0; i < numWords; i++) {
                    if (strcmp(words[i].word, curWord) == 0) {
                        words[i].frequency++; // Increment frequency of existing word
                        break;
                    }
                }

                // If current word is not already in words array, add it
                if (i == numWords) {
                    if (numWords == MAX_NUM_WORDS) { // Check if maximum number of words has been reached
                        printf("Maximum number of words reached!\n");
                        break;
                    }
                    strcpy(words[numWords].word, curWord);
                    words[numWords].frequency = 1;
                    numWords++;
                }

                curCharIndex = 0; // Reset index within current word
            }
        }
        else { // If current character is not whitespace or punctuation
            if (curCharIndex < MAX_WORD_LEN) { // If current word is not too long
                curWord[curCharIndex] = curChar;
                curCharIndex++;
            }
        }
    }

    fclose(inputFile); // Close input file

    printf("Word Frequency\n-------------\n");
    // Print frequency of each word
    for (i = 0; i < numWords; i++) {
        printf("%-20s%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}