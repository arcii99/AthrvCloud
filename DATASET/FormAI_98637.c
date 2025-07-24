//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

void print_word_frequencies(char* words[], int frequency[], int n) {
    printf("\nWord\t\tFrequency\n");
    printf("==========================\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s\t%d\n", words[i], frequency[i]);
    }
}

int main() {
    char text[1000];
    printf("Enter some text:\n");
    fgets(text, 1000, stdin);

    // Replacing non-alphabetical characters with spaces
    for (int i = 0; i < strlen(text); i++) {
        if (!isalpha(text[i]))
            text[i] = ' ';
    }

    int n = 0;
    char* words[MAX_WORDS];
    int frequency[MAX_WORDS] = {0};

    char* token = strtok(text, " ");
    while (token != NULL && n < MAX_WORDS) {
        int found = 0;
        // Check if the word is already in the list
        for (int i = 0; i < n; i++) {
            if (strcasecmp(token, words[i]) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        // Add the word to the list if it is not already there
        if (!found) {
            words[n] = token;
            frequency[n]++;
            n++;
        }
        // Get the next word
        token = strtok(NULL, " ");
    }

    // Print the word frequencies
    print_word_frequencies(words, frequency, n);

    return 0;
}