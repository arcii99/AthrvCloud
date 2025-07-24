//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SUMMARY 1000

void print_summary(char** summary, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s", summary[i]);
    }
}

char** summarize(char* article, int num_sentences, int* summary_len) {
    char* sentence;
    char** sentences = malloc(MAX_SENTENCES * sizeof(char*));
    char** summary = malloc(MAX_SUMMARY * sizeof(char*));
    int sentence_count = 0;
    int summary_count = 0;

    sentence = strtok(article, ".\n");

    while (sentence != NULL) {
        sentences[sentence_count++] = sentence;
        sentence = strtok(NULL, ".\n");
    }

    for (int i = 0; i < num_sentences; i++) {
        summary[summary_count++] = sentences[i];
    }

    *summary_len = summary_count;

    return summary;
}

int main() {
    char article[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed eget odio accumsan, suscipit erat et, luctus diam. Integer vel eleifend tellus. Fusce vel lorem egestas erat posuer.\n Vivamus blandit interdum nisi at elementum. Maecenas efficitur dui vel lorem pretium rutrum vel sit amet tellus. Sed blandit urna sed libero rhoncus volutpat. Nunc magna elit, vestibulum vitfdae magna eget, placerat dignissim ex. Sed nonuctor felis quis lacinia.";
    int summary_len = 0;
    char** summary = summarize(article, 2, &summary_len);

    print_summary(summary, summary_len);

    free(summary);
    return 0;
}