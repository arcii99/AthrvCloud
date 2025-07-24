//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 50
#define MAX_WORDS 1000
#define MAX_CHARS 100

void summarize(char *text);

int main() {
    char text[MAX_CHARS];
    printf("Enter a text to summarize:\n");
    fgets(text, MAX_CHARS, stdin);
    summarize(text);
    return 0;
}

void summarize(char *text) {
    char *sentences[MAX_SENTENCES];
    char words[MAX_SENTENCES][MAX_WORDS][MAX_CHARS];
    int freq[MAX_SENTENCES] = {0};
    int total_sentences = 0;
    char *sentence = strtok(text, ".!?\n");

    while (sentence != NULL && total_sentences < MAX_SENTENCES) {
        sentences[total_sentences++] = sentence;
        char *word = strtok(sentence, " ");
        int total_words = 0;

        while (word != NULL && total_words < MAX_WORDS) {
            char *clean_word = malloc(sizeof(char) * MAX_CHARS);
            int i, j;
            for (i = j = 0; word[i]; i++) {
                if (isalnum(word[i])) {
                    clean_word[j++] = tolower(word[i]);
                }
            }
            clean_word[j] = '\0';
            strcpy(words[total_sentences-1][total_words++], clean_word);
            free(clean_word);
            word = strtok(NULL, " ");
        }
        sentence = strtok(NULL, ".!?\n");
    }

    int i, j, k;
    for (i = 0; i < total_sentences; i++) {
        for (j = i+1; j < total_sentences; j++) {
            for (k = 0; k < MAX_WORDS && words[i][k][0] != '\0' && words[j][k][0] != '\0'; k++) {
                if (strcmp(words[i][k], words[j][k]) == 0) {
                    freq[i]++;
                    freq[j]++;
                }
            }
        }
    }

    printf("Summary:\n");
    for (i = 0; i < total_sentences; i++) {
        if (freq[i] > 0) {
            printf("%s.", sentences[i]);
        }
    }
}