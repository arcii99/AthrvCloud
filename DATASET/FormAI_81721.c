//FormAI DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

char* summarize_text(char* text);

int main() {
    char* text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed malesuada ipsum quis tellus faucibus, non auctor sapien suscipit. Sed viverra congue lorem vel facilisis. Etiam posuere lectus quis odio volutpat, vel venenatis nulla dignissim. Sed fringilla vestibulum sem ut rhoncus. Nam dictum ipsum at venenatis dapibus. Donec vel risus in turpis laoreet malesuada. Nulla congue tristique lorem ac bibendum.";

    char* summary = summarize_text(text);
    printf("Summary: %s", summary);

    free(summary);
    return 0;
}

char* summarize_text(char* text) {
    char** sentences = malloc(sizeof(char*));
    int num_sentences = 0;

    char* sentence = strtok(text, ".!?");

    while (sentence != NULL) {
        sentences[num_sentences] = malloc(strlen(sentence) + 1);
        strcpy(sentences[num_sentences], sentence);

        num_sentences++;
        sentences = realloc(sentences, sizeof(char*) * (num_sentences + 1));

        sentence = strtok(NULL, ".!?");
    }

    char* summary = malloc(MAX_SUMMARY_LENGTH + 1);
    strcpy(summary, "");

    int i;
    for (i = 0; i < num_sentences; i++) {
        if (strlen(summary) + strlen(sentences[i]) <= MAX_SUMMARY_LENGTH) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
        } else {
            break;
        }
    }

    if (strlen(summary) == 0 && num_sentences > 0) {
        strcat(summary, sentences[0]);
        strcat(summary, ".");
    }

    for (i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);

    return summary;
}