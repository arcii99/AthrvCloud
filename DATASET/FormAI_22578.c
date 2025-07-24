//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int main() {
    char text[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS];
    int i, j, k, word_count;
    int length;
    int unique_count = 0;

    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin); 

    // Ensure text ends with '\0'
    length = strlen(text);
    if (length > 0 && text[length-1] != '\0') {
        text[length-1] = '\0';
    }

    // Split text into individual words
    word_count = 0;
    i = 0;
    while (text[i] != '\0') {
        // Ignore non-alphabetic characters
        while (text[i] != '\0' && !isalpha(text[i])) {
            i++;
        }

        // Extract word
        j = 0;
        while (text[i] != '\0' && isalpha(text[i])) {
            words[word_count][j] = tolower(text[i]);
            j++;
            i++;
        }
        words[word_count][j] = '\0';
        word_count++;
    }

    // Count frequency of each unique word
    for (i = 0; i < word_count; i++) {
        if (strlen(words[i]) > 0) {
            count[i] = 1;
            for (j = i+1; j < word_count; j++) {
                if (strlen(words[j]) > 0 && strcmp(words[i], words[j]) == 0) {
                    count[i]++;
                    // Set duplicate words to empty string to ignore them in the future
                    strcpy(words[j], "");
                }
            }
            unique_count++;
        }
    }

    // Print results
    printf("Unique Words: %d\n\n", unique_count);
    for (i = 0; i < word_count; i++) {
        if (strlen(words[i]) > 0) {
            printf("%-20s%5d\n", words[i], count[i]);
        }
    }

    return 0;
}