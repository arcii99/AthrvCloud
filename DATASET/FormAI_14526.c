//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

int main() {
    char article[MAX_SENTENCES][MAX_WORDS][MAX_WORD_LENGTH] = {0};
    char input[MAX_WORDS * MAX_WORDS] = {0};
    char *word, *sentence;
    int sentence_count = 0, word_count = 0, i, j;
    float scores[MAX_SENTENCES] = {0};

    printf("Welcome to the C Text Summarizer!\n");
    printf("Please enter the article you would like to summarize:\n");

    fgets(input, sizeof(input), stdin);

    sentence = strtok(input, ".");
    while (sentence != NULL && sentence_count < MAX_SENTENCES) {
        word = strtok(sentence, " ");
        while (word != NULL && word_count < MAX_WORDS) {
            strcpy(article[sentence_count][word_count], word);
            word_count++;
            word = strtok(NULL, " ");
        }
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    for (i = 0; i < sentence_count; i++) {
        for (j = 0; j < word_count; j++) {
            if (strstr(article[i][j], "important") != NULL) {
                scores[i] += 10;
            }
            if (strstr(article[i][j], "interesting") != NULL) {
                scores[i] += 5;
            }
        }
    }

    printf("The summary of the article is:\n");

    for (i = 0; i < sentence_count; i++) {
        if (scores[i] >= 5) {
            printf("%s. ", article[i][0]);
        }
    }

    printf("\n");

    return 0;
}