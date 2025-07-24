//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word
#define MAX_TEXT_LENGTH 10000 // Maximum length of the text

int main() {
    char text[MAX_TEXT_LENGTH] = "Enter your text here"; // Initialize the text
    char word[MAX_WORD_LENGTH]; // Initialize the word
    int word_count = 0; // Initialize the word count
    int freq[MAX_TEXT_LENGTH]; // Initialize the word frequency array
    int i, j; // Initialize the loop variables

    // Convert the text to lowercase
    for (i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Split the text into words and count their frequency
    for (i = 0; text[i]; i++) {
        // Initialize the word
        for (j = 0; j < MAX_WORD_LENGTH - 1 && text[i]; j++) {
            if (isalpha(text[i])) {
                word[j] = text[i];
            } else {
                break;
            }
            i++;
        }
        word[j] = '\0'; // Add null character to terminate the string

        // Update the word frequency count
        if (j > 0) {
            for (j = 0; j < word_count; j++) {
                if (strcmp(word, freq[j]) == 0) { // If word is already in the array, increment its count
                    freq[j]++;
                    break;
                }
            }
            if (j == word_count) { // If word is not in the array, add it to the array and set its count to 1
                strcpy(freq[word_count], word);
                freq[word_count++] = 1;
            }
        }
    }

    // Print the word frequency count
    for (i = 0; i < word_count; i++) {
        printf("%s : %d\n", freq[i], freq[i]);
    }

    return 0;
}