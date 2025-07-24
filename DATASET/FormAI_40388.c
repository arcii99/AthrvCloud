//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of characters in each sentence and maximum number of sentences in the document
#define MAX_SENTENCE_LENGTH 1000
#define MAX_NUM_SENTENCES 1000

int main() {
    char document[MAX_NUM_SENTENCES][MAX_SENTENCE_LENGTH];
    int num_sentences = 0;

    // Read in the document one sentence at a time
    while (fgets(document[num_sentences], MAX_SENTENCE_LENGTH, stdin)) {
        // Remove newline character from the end of the sentence
        document[num_sentences][strcspn(document[num_sentences], "\n")] = '\0';

        // If the sentence is just a newline character, we've reached the end of the document
        if (strcmp(document[num_sentences], "") == 0) {
            break;
        }

        num_sentences++;
    }

    // Create a summary string to store the summary
    char summary[MAX_SENTENCE_LENGTH * MAX_NUM_SENTENCES];
    strcpy(summary, "");

    // Loop through the sentences and add the first sentence to the summary
    strcat(summary, document[0]);
    strcat(summary, " ");

    // Loop through the remaining sentences and add them to the summary if they contain a keyword
    for (int i = 1; i < num_sentences; i++) {
        char* sentence = document[i];

        // Check if the sentence contains any of the keywords we care about
        if (strstr(sentence, "important") || strstr(sentence, "noteworthy") || strstr(sentence, "significant")) {
            strcat(summary, sentence);
            strcat(summary, " ");
        }
    }

    // Print out the summary
    printf("%s\n", summary);

    return 0;
}