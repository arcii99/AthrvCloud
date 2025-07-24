//FormAI DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize text
char* text_summarizer(char *text, int summary_length) {
    // Split text into sentences
    char *sentence = strtok(text, ".");
    char sentences[100][1000];
    int num_sentences = 0;
    while (sentence != NULL) {
        strcpy(sentences[num_sentences], sentence);
        num_sentences++;
        sentence = strtok(NULL, ".");
    }

    // Calculate scores for each sentence
    int scores[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        scores[i] = strlen(sentences[i]);
    }

    // Sort sentences by score
    for (int i = 0; i < num_sentences; i++) {
        for (int j = i+1; j < num_sentences; j++) {
            if (scores[j] > scores[i]) {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                char temp_sentence[1000];
                strcpy(temp_sentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp_sentence);
            }
        }
    }

    // Generate summary
    char *summary = calloc(summary_length, sizeof(char));
    strcat(summary, "In summary, ");
    for (int i = 0; i < summary_length; i++) {
        if (i == summary_length-1) {
            strcat(summary, "...");
        } else {
            strcat(summary, sentences[i]);
        }
    }

    return summary;
}

// Main function
int main() {
    // Input text
    char text[] = "The quick brown fox jumped over the lazy dog. The lazy dog was not impressed. The fox shrugged and went on its way.";
    // Print input text
    printf("Input text:\n%s\n", text);
    // Summarize text
    char *summary = text_summarizer(text, 2);
    // Print summary
    printf("Summary:\n%s", summary);
    // Free memory allocated for summary
    free(summary);
    // Exit program
    return 0;
}