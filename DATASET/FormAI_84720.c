//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 20
#define MAX_SENTENCE_LENGTH 1000

void summarize(char *text);

int main() {
    char text[MAX_SENTENCE_LENGTH * MAX_SENTENCES];
    printf("Enter the text to summarize:\n");
    fgets(text, sizeof(text), stdin);
    summarize(text);
    return 0;
}

void summarize(char *text) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_count = 0;
    char *p = strtok(text, ".?!");

    while (p != NULL && sentence_count < MAX_SENTENCES) {
        strcpy(sentences[sentence_count++], p);
        p = strtok(NULL, ".?!");
    }

    int i, j;
    int sentence_score[MAX_SENTENCES] = {0};
    char words[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int word_count = 0;

    for (i = 0; i < sentence_count; i++) {
        p = strtok(sentences[i], " \n\t");

        while (p != NULL && word_count < MAX_SENTENCES) {
            strcpy(words[word_count++], p);
            p = strtok(NULL, " \n\t");
        }
    }

    char common[10][10] = {"the", "and", "of", "to", "a", "in", "that", "is", "was", "for"};

    for (i = 0; i < word_count; i++) {
        for (j = 0; j < 10; j++) {
            if (strcmp(words[i], common[j]) == 0) {
                sentence_score[i / (word_count / sentence_count)]--;
                break;
            }
        }
        sentence_score[i / (word_count / sentence_count)]++;
    }

    int max_score = 0;
    int max_index = 0;

    for (i = 0; i < sentence_count; i++) {
        if (sentence_score[i] > max_score) {
            max_score = sentence_score[i];
            max_index = i;
        }
    }

    printf("\nSummary:\n%s", sentences[max_index]);
}