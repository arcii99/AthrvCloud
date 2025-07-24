//FormAI DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a word in a sentence
int countOccurrences(char *sentence, char *word) {
    int count = 0;
    char *token;

    // Get the first token
    token = strtok(sentence, " ");

    // Keep looping while there are more tokens
    while (token != NULL) {
        // If the token matches the word, increment the count
        if (strcmp(token, word) == 0) {
            count++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the count
    return count;
}

// Function to summarize a text by counting the occurrences of the most common words
void summarizeText(char *text) {
    int maxCount = 0;
    char *mostCommonWord = "";
    char *token;
    char *sentence;
    char *summary = (char*)malloc(100*sizeof(char));

    // Loop through each sentence in the text
    sentence = strtok(text, "\n");
    while (sentence != NULL) {
        // Loop through each word in the sentence
        token = strtok(sentence, " ");
        while (token != NULL) {
            // Count the number of occurrences of the word
            int count = countOccurrences(text, token);

            // If the count is higher than the maximum count, update the most common word and maximum count
            if (count > maxCount) {
                maxCount = count;
                mostCommonWord = token;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }

        // Add a brief summary of the sentence to the summary string
        sprintf(summary, "%s %s.", summary, strtok(sentence, "."));
        
        // Get the next sentence
        sentence = strtok(NULL, "\n");
    }

    // Print the summary and the most common word
    printf("Summary: %s\n", summary);
    printf("Most common word: %s", mostCommonWord);
}

// Main function
int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The dog didn't move because it was too lazy.";

    summarizeText(text);

    return 0;
}