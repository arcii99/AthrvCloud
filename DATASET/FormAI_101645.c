//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SUMMARY_LENGTH 100

void update_summary(char summary[MAX_SUMMARY_LENGTH], char new_sentence[MAX_SUMMARY_LENGTH]) {
    int summary_len = strlen(summary);
    int new_sentence_len = strlen(new_sentence);

    if (summary_len + new_sentence_len <= MAX_SUMMARY_LENGTH) {
        strcat(summary, new_sentence);
        strcat(summary, ". ");
    } else {
        int i, j;
        for (i = 0; i < new_sentence_len && summary_len < MAX_SUMMARY_LENGTH - 2; ++i) {
            summary[summary_len++] = new_sentence[i];
        }
        summary[summary_len++] = '.';
        summary[summary_len++] = ' ';
    }
}

int main() {
    printf("Enter the text to summarize: ");

    // Read input text
    char input_text[1000];
    fgets(input_text, 1000, stdin);

    // Split input text into sentences
    char sentences[100][100];
    int sentence_count = 0;

    char* token = strtok(input_text, ".");
    while (token != NULL) {
        strcpy(sentences[sentence_count++], token);
        token = strtok(NULL, ".");
    }

    // Summarize the text
    char summary[MAX_SUMMARY_LENGTH] = "";
    for (int i = 0; i < sentence_count && strlen(summary) < MAX_SUMMARY_LENGTH; ++i) {
        char sentence[MAX_SUMMARY_LENGTH] = "";
        char* word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                strcat(sentence, word);
                strcat(sentence, " ");
            }
            word = strtok(NULL, " ");
        }
        if (strlen(sentence) > 0) {
            update_summary(summary, sentence);
        }
    }

    // Print the summary
    printf("Summary: %s", summary);

    return 0;
}