//FormAI DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SUMMARY 500

int main() {
    // read input text
    char text[MAX_SUMMARY];
    printf("Enter text to summarize:\n");
    fgets(text, MAX_SUMMARY, stdin);

    // split input text into sentences
    char* sentences[MAX_SENTENCES];
    for (int i = 0; i < MAX_SENTENCES; i++) {
        sentences[i] = NULL;
    }

    const char* delimiters = ".!?";
    const char* sentence = strtok(text, delimiters);
    int num_sentences = 0;
    while (sentence != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, delimiters);
    }

    // rank sentences by importance
    int scores[MAX_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        scores[i] = 0;
    }

    const char* keywords[] = {"data", "algorithm", "program", "computer", "code", "software"};
    const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_keywords; j++) {
            if (strstr(sentences[i], keywords[j]) != NULL) {
                scores[i]++;
            }
        }
    }

    // generate summary
    char summary[MAX_SUMMARY];
    strcpy(summary, "");

    int num_summary = 0;
    for (int i = 0; i < num_sentences && num_summary < MAX_SENTENCES / 2; i++) {
        if (scores[i] > 0) {
            strncat(summary, sentences[i], strlen(sentences[i]));
            strncat(summary, ". ", 2);
            num_summary++;
        }
    }

    // print summary
    printf("\nSummary:\n%s\n", summary);

    return 0;
}