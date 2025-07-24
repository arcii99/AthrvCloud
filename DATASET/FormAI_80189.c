//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* summarize_text(char* text, int max_length) {
    // Initialize variables
    int text_length = strlen(text);
    char* summary = malloc(sizeof(char) * (max_length + 1));

    // Divide the text into sentences
    char* sentence = strtok(text, ".");
    while (sentence != NULL) {
        // Check if the sentence is shorter than the maximum length
        if (strlen(summary) + strlen(sentence) < max_length) {
            // Append the sentence to the summary
            strcat(summary, sentence);
            strcat(summary, ".");

            // Check if the summary has reached the maximum length
            if (strlen(summary) >= max_length) {
                // Shorten the summary by removing the last sentence
                for (int i = strlen(summary) - 2; i >= 0; i--) {
                    if (summary[i] == '.') {
                        summary[i + 1] = '\0';
                        break;
                    }
                }

                // Return the summary
                return summary;
            }
        }

        sentence = strtok(NULL, ".");
    }

    // If the summary is still shorter than the maximum length, return the original text
    if (strlen(summary) < max_length) {
        return text;
    }

    // Shorten the summary by removing the last sentence
    for (int i = strlen(summary) - 2; i >= 0; i--) {
        if (summary[i] == '.') {
            summary[i + 1] = '\0';
            break;
        }
    }

    // Return the summary
    return summary;
}

int main() {
    // Example usage
    char* text = "This is a sample text. It is used to demonstrate the text summarizer program. The program should output a summary of the text that is no longer than a certain maximum length.";
    char* summary = summarize_text(text, 50);
    printf("%s\n", summary);
    free(summary);

    return 0;
}