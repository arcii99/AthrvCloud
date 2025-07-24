//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a character is a vowel
int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    int state = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            state = 0;
        } else if (state == 0) {
            state = 1;
            count++;
        }
    }
    return count;
}

// Function to summarize a text
char* summarize(char* text, int max_words) {
    // Count the number of words in the text
    int num_words = countWords(text);

    // If the maximum number of words is greater than or equal to
    // the total number of words, return the original text
    if (max_words >= num_words) {
        return text;
    }

    // Otherwise, create a summary string
    char* summary = malloc((max_words * 9 + 1) * sizeof(char));
    summary[0] = '\0';

    // Loop through the text and add words to the summary
    int word_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL && word_count < max_words) {
        // Remove punctuation from the word
        int len = strlen(token);
        if (len > 0) {
            if (!isalpha(token[len-1])) {
                token[len-1] = '\0';
            }
        }

        strcat(summary, token);
        strcat(summary, " ");

        // If the word is a noun, add it to the summary twice
        if (token[0] > 64 && token[0] < 91 && !isVowel(token[0])) {
            strcat(summary, token);
            strcat(summary, " ");
        }

        // Move to the next word
        token = strtok(NULL, " ");
        word_count++;
    }

    // Add an ellipsis to the end of the summary
    strcat(summary, "...");
    return summary;
}

int main() {
    // Sample text to summarize
    char text[] = "It was a dark and stormy night. The rain fell in torrents, except at occasional intervals, when it was checked by a violent gust of wind which swept up the streets. In the midst of one of these tempests, an old man with ragged clothes and a cane limped down the street. He stopped in front of the door of a large, dark mansion and knocked three times. A moment later, the door creaked open and a young woman appeared.";

    // Summarize the text
    char* summary = summarize(text, 10);

    // Print the summary
    printf("%s\n", summary);

    // Free the memory allocated for the summary
    free(summary);

    return 0;
}