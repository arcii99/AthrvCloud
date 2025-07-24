//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 20 // assume words are not longer than 20 characters

int main() {
    char input_string[MAX_WORDS][MAX_LENGTH];
    char word[MAX_LENGTH];
    int frequency[MAX_WORDS];
    int i, j, count, unique_words;

    // Initialize frequency array to zero
    for (i = 0; i < MAX_WORDS; i++) {
        frequency[i] = 0;
    }

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input_string[0], MAX_WORDS, stdin);

    // Tokenize the input string into individual words
    count = 0;
    unique_words = 0;
    for (i = 0; i < strlen(input_string[0]); i++) {
        if (isalnum(input_string[0][i])) { // Check if character is alphanumeric
            word[count] = tolower(input_string[0][i]); // Convert to lowercase
            count++;
        } else if (count != 0) { // End of word encountered
            word[count] = '\0'; // Terminate string
            count = 0; // Reset count

            // Check if word already exists in array
            for (j = 0; j < unique_words; j++) {
                if (strcmp(word, input_string[j]) == 0) { // Word already exists
                    frequency[j]++;
                    break;
                }
            }

            // If word does not exist in array, add it
            if (j == unique_words) {
                strcpy(input_string[unique_words], word);
                frequency[unique_words]++;
                unique_words++;
            }
        }
    }

    // Output the word frequency counts
    printf("\nWord Frequency:\n");
    for (i = 0; i < unique_words; i++) {
        printf("%-20s %d\n", input_string[i], frequency[i]);
    }

    return 0;
}