//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Function to count the number of words in the given string
int countWords(char* string, int wordCount[]) {
    int i = 0, j = 0, k = 0, flag = 0;
    int numWords = 0;
    char word[MAX_WORD_LENGTH];

    // Loop over the string one character at a time
    while (string[i] != '\0') {
        // If the current character is a whitespace
        if (isspace(string[i])) {
            // If we have a word to process
            if (flag == 1) {
                // Null terminate the current word
                word[j] = '\0';
                j = 0;

                // Update the word count
                wordCount[k++] = strlen(word);
                numWords++;

                // Clear the word buffer
                memset(word, 0, sizeof(word));
            }
            flag = 0;
        }
        else {
            // If we're not at a whitespace, add the character to the word buffer
            word[j++] = string[i];
            flag = 1;
        }

        // If we have processed the maximum amount of words, return the count
        if (numWords == MAX_WORDS) {
            return numWords;
        }

        // Move on to the next character in the string
        ++i;
    }

    // Process the last word in the string
    if (flag == 1) {
        // Null terminate the current word
        word[j] = '\0';
        j = 0;

        // Update the word count
        wordCount[k++] = strlen(word);;
        numWords++;
    }

    // Return the number of words processed
    return numWords;
}

int main() {
    char string[1000];

    printf("Enter the string to count the number of words: ");
    fgets(string, 1000, stdin);

    // Remove the newline character at the end of the string
    string[strcspn(string, "\n")] = 0;

    // Initialize the array to store the word lengths
    int wordCount[MAX_WORDS] = {0};

    // Call the function to count the number of words
    int numWords = countWords(string, wordCount);

    // Display the number of words in the input
    printf("The input contains %d words\n", numWords);

    // Display the length of each word
    printf("Word lengths: ");
    for (int i = 0; i < numWords; i++) {
        printf("%d ", wordCount[i]);
    }
    printf("\n");

    return 0;
}