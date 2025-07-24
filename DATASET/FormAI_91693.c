//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to remove punctuation from a string
void remove_punctuation(char *str) {
    char *p = str;
    while (*p) {
        if (ispunct(*p)) {
            memmove(p, p + 1, strlen(p + 1) + 1);
        } else {
            p++;
        }
    }
}

// function to convert a string to lowercase
void to_lower(char *str) {
    char *p = str;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
}

// function to tokenize a string into a list of words
void tokenize(char *str, char **tokens, int *num_tokens) {
    char *tok;
    *num_tokens = 0;
    tok = strtok(str, " ");
    while (tok != NULL) {
        tokens[*num_tokens] = tok;
        (*num_tokens)++;
        tok = strtok(NULL, " ");
    }
}

// function to perform sentiment analysis on a string
void analyze_sentiment(char *str) {
    int score = 0;
    char *tokens[100];
    int num_tokens = 0;
    remove_punctuation(str);
    to_lower(str);
    tokenize(str, tokens, &num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "good") == 0) {
            score++;
        } else if (strcmp(tokens[i], "bad") == 0) {
            score--;
        }
    }
    printf("Score: %d\n", score);
    if (score > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (score < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    analyze_sentiment(input);
    return 0;
}