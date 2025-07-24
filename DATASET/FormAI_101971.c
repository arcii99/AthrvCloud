//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUMMARY_LENGTH 50

void summarize(char *text) {
    int word_count = 0;
    char *word = strtok(text, " ");

    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }

    if (word_count <= SUMMARY_LENGTH) {
        printf("%s\n", text);
        return;
    }

    char *summary = calloc(SUMMARY_LENGTH * sizeof(char), 1);
    word_count = 0;
    word = strtok(text, " ");

    while (word != NULL) {
        word_count++;

        if (word_count <= SUMMARY_LENGTH) {
            strcat(summary, word);
            strcat(summary, " ");
        } else {
            break;
        }

        word = strtok(NULL, " ");
    }

    strcat(summary, "...");
    printf("%s\n", summary);
    free(summary);
}

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed faucibus magna eget erat elementum dictum. Proin elementum volutpat facilisis. Nunc vel nisi ac metus bibendum ullamcorper vitae convallis est. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In vitae feugiat nulla. Sed placerat bibendum nisi. Pellentesque pharetra enim vel leo maximus, sit amet ullamcorper lectus elementum. Proin eget sagittis ligula. Quisque non magna justo. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae;";

    summarize(text);

    return 0;
}