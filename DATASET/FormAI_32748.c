//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define structure for each word and its count.
struct word {
    char *str;
    int count;
};

// Function to compare two words for qsort function.
int compare(const void *a, const void *b) {
    struct word *wordA = (struct word *)a;
    struct word *wordB = (struct word *)b;
    return wordB->count - wordA->count;
}

int main(void) {
    char *text = "This is an example C program to count the frequency of each word in a text. It should be able to handle punctuation, capitalization, and non-ASCII characters. Let's see if it works!";
    int textLength = strlen(text);

    // Initialize an array of words to keep track of each word and its count.
    struct word *wordList = malloc(textLength * sizeof(struct word));
    int numWords = 0;

    // Initialize variables for parsing the text.
    int i = 0;
    int start = -1;
    char current;

    // Parse the text character by character.
    while (i < textLength) {
        current = text[i];
        if (isalpha(current) || isdigit(current) || (i > 0 && isalpha(text[i - 1]) && current == '\'')) {
            // If the character is part of a word, keep track of its start index.
            if (start == -1) {
                start = i;
            }
        } else {
            // If the character is not part of a word, add the previous word to the list.
            if (start != -1) {
                int length = i - start;
                char *word = malloc(length + 1);
                strncpy(word, text + start, length);
                word[length] = '\0';

                // Convert the word to lower case.
                int j;
                for (j = 0; j < length; j++) {
                    word[j] = tolower(word[j]);
                }

                // Check if the word is already in the list.
                int k;
                for (k = 0; k < numWords; k++) {
                    if (strcmp(wordList[k].str, word) == 0) {
                        // If the word is already in the list, increment its count.
                        wordList[k].count++;
                        free(word);
                        break;
                    }
                }

                // If the word is not in the list, add it.
                if (k == numWords) {
                    wordList[numWords].str = word;
                    wordList[numWords].count = 1;
                    numWords++;
                }

                start = -1;
            }
        }

        i++;
    }

    // Sort the list by frequency.
    qsort(wordList, numWords, sizeof(struct word), compare);

    // Print the list.
    printf("Word Frequencies:\n");
    printf("------------------\n");
    for (i = 0; i < numWords; i++) {
        printf("%15s: %2d\n", wordList[i].str, wordList[i].count);
    }

    // Free memory allocated for words.
    for (i = 0; i < numWords; i++) {
        free(wordList[i].str);
    }

    free(wordList);

    return 0;
}