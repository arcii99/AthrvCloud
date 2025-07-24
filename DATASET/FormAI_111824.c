//FormAI DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove punctuation marks from a string
void remove_punctuation(char s[]) {
    int len = strlen(s);
    for (int i = 0; s[i]; i++) {
        if (ispunct(s[i])) {
            memmove(&s[i], &s[i + 1], len-- - i); // Remove the character and shorten the length of the string
        }
    }
}

// Function to convert string to lowercase
void to_lower(char s[]) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]); // Change each character to lowercase
    }
}

// Main function to summarize the text
int main() {
    char text[1000], summary[1000] = "";
    int word_count = 0, num_sentences = 0;

    printf("Please enter the text to be summarized:\n");
    fgets(text, 1000, stdin);

    // Remove punctuation and convert to lowercase
    remove_punctuation(text);
    to_lower(text);

    // Count number of words and sentences
    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            word_count++;
        } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            num_sentences++;
        }
    }

    // Determine length of summary based on number of sentences
    int summary_length;
    if (num_sentences <= 1) {
        summary_length = strlen(text) / 4;
    } else if (num_sentences <= 2) {
        summary_length = strlen(text) / 3;
    } else if (num_sentences <= 3) {
        summary_length = strlen(text) / 2;
    } else {
        summary_length = strlen(text) / num_sentences;
    }

    // Start summarizing
    int length = 0;
    char *token = strtok(text, " ");
    while (token != NULL && length < summary_length) {
        strcat(summary, token); // Add the next word to the summary
        strcat(summary, " "); // Add a space after the word
        length += strlen(token) + 1; // Increase the length of the summary
        token = strtok(NULL, " "); // Get the next word
    }

    // Print the summary
    printf("Summary:\n%s\n", summary);

    return 0;
}