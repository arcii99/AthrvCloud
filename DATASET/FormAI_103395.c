//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h> 
#include <string.h>
#define MAX_WORD_LENGTH 50 
#define MAX_WORDS 1000 

// Function to check if a character is alpha-numeric
int isAlnum(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

// Function to get a word from a string
void getWord(char *str, int start, int end, char *word) {
    int i, j = 0;
    for (i=start; i<=end; i++) {
        word[j] = str[i];
        j++;
    }
    word[j] = '\0';
}

int main() {
    char text[MAX_WORDS], word[MAX_WORD_LENGTH], ch;
    int i, j = 0, len, wordCount = 0, frequency[MAX_WORDS];
    int isFound, index;

    // Initialize frequency array
    for (i=0; i<MAX_WORDS; i++)
        frequency[i] = -1;

    // Read text from user
    printf("Enter some text:\n");
    while ((ch = getchar()) != '\n' && j < MAX_WORDS - 1) {
        text[j] = ch;
        j++;
    }
    text[j] = '\0';

    // Scan text for words
    len = strlen(text);
    for (i=0; i<len; i++) {
        if (isAlnum(text[i])) { // If character is alpha-numeric
            if (wordCount == 0) // Start new word
                j = i;
            wordCount++;
        } else { // If character is not alpha-numeric
            if (wordCount > 0) { // End current word
                getWord(text, j, i-1, word);
                isFound = 0;
                // Check if word is already in frequency array
                for (index=0; index<MAX_WORDS; index++) {
                    if (strcmp(word, "") == 0)
                        break;
                    if (frequency[index] == -1) { // End of frequency array
                        frequency[index] = 1;
                        strcpy(word, "");
                        break;
                    }
                    if (strcmp(word, &text[index*MAX_WORD_LENGTH]) == 0) { // Word already exists
                        frequency[index]++;
                        strcpy(word, "");
                        isFound = 1;
                        break;
                    }
                }
                if (!isFound) { // Add new word to frequency array
                    frequency[index] = 1;
                    strcpy(&text[index*MAX_WORD_LENGTH], word);
                    strcpy(word, "");
                }
                wordCount = 0;
            }
        }
    }

    // Print word frequency
    printf("Word Frequency:\n");
    for (i=0; i<MAX_WORDS; i++) {
        if (frequency[i] == -1)
            break;
        printf("%s: %d\n", &text[i*MAX_WORD_LENGTH], frequency[i]);
    }

    return 0;
}