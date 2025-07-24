//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define SUMMARY_LENGTH 200

char *summarize(char text[]) {
    char *summary = malloc(sizeof(char) * SUMMARY_LENGTH);
    int i, j = 0;
    char *word = strtok(text, " ");

    while (word != NULL && j < SUMMARY_LENGTH) {
        int word_len = strlen(word);
        if (j + word_len + 1 > SUMMARY_LENGTH) {
            break;
        }
        if (word[0] == '"' || word[word_len - 1] == '"' || word[0] == '(' || word[word_len - 1] == ')' ||
            word[0] == '[' || word[word_len - 1] == ']' || word[0] == '{' || word[word_len - 1] == '}') {
            continue;
        }
        for (i = 0; i < word_len; i++) {
            summary[j++] = word[i];
        }
        summary[j++] = ' ';
        word = strtok(NULL, " ");
    }
    summary[j-1] = '\0';
    return summary;
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter the text to summarize:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    printf("Summary:\n");
    printf("%s\n", summarize(text));
    return 0;
}