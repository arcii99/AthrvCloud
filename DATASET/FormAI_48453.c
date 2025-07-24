//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000
#define MAX_KEYWORDS 50

char *keywords[MAX_KEYWORDS];
int num_keywords = 0;

void add_keyword(char *keyword) {
    keywords[num_keywords++] = keyword;
}

int is_keyword(char *word) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void summarize(char *input, char *output) {
    char *word, *sentence, *out_ptr;
    int len, i, j, sentence_len, num_sentences = 0;

    out_ptr = output;
    sentence = strtok(input, ".!?");
    while (sentence != NULL) {
        num_sentences++;
        sentence_len = strlen(sentence);
        word = strtok(sentence, " \t\n\r");
        len = 0;
        while (word != NULL) {
            if (is_keyword(word)) {
                len += strlen(word);
                if (len > MAX_OUTPUT_SIZE - 1) {
                    break;
                }
                for (i = 0; i < strlen(word); i++) {
                    *out_ptr++ = word[i];
                }
                *out_ptr++ = ' ';
            }
            word = strtok(NULL, " \t\n\r");
        }
        *out_ptr++ = '.';
        *out_ptr++ = ' ';
        sentence = strtok(NULL, ".!?");
    }
    *out_ptr++ = '\n';
    *out_ptr = '\0';

    if (num_sentences == 0) {
        strcpy(output, "No sentences found.\n");
    }
}

int main() {
    char input[MAX_INPUT_SIZE], output[MAX_OUTPUT_SIZE];
    int num_keywords, i;

    add_keyword("programming");
    add_keyword("code");
    add_keyword("language");
    add_keyword("computer");
    add_keyword("algorithm");

    printf("Enter text to summarize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    summarize(input, output);

    printf("\nSummary:\n%s", output);

    return 0;
}