//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

int main() {
    char input_str[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_lengths[MAX_WORDS];
    int word_count = 0;

    printf("Enter a string: ");
    fgets(input_str, MAX_WORDS, stdin);

    // Convert input string to lowercase to make counting case-insensitive
    for (int i = 0; i < strlen(input_str); i++) {
        input_str[i] = tolower(input_str[i]);
    }

    // Tokenize the input string into words
    char* token = strtok(input_str, " ");
    while (token != NULL) {
        // Remove trailing newline character from word
        if (token[strlen(token)-1] == '\n') {
            token[strlen(token)-1] = '\0';
        }
        // Store the word and its length
        strcpy(words[word_count], token);
        word_lengths[word_count] = strlen(token);
        word_count++;
        token = strtok(NULL, " ");
    }

    // Initialize the word counts to zero
    int counts[MAX_WORDS] = {0};

    // Count the occurrence of each unique word
    for (int i = 0; i < word_count; i++) {
        int is_duplicate = 0;
        for (int j = i-1; j >= 0; j--) {
            if (strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            counts[i] = 1;
            for (int j = i+1; j < word_count; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    counts[i]++;
                }
            }
        }
    }

    // Print the word counts
    printf("\nWord Counts:\n");
    for (int i = 0; i < word_count; i++) {
        if (counts[i] > 0) {
            printf("%s: %d\n", words[i], counts[i]);
        }
    }

    return 0;
}