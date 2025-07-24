//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Given a character, returns true if it is a punctuation mark,
 * false otherwise.
 */
int is_punctuation(char c) {
    return (c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':');
}

/*
 * Given a character, returns true if it is a whitespace character,
 * false otherwise.
 */
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

/*
 * Given a string, removes any punctuation marks from the beginning and end,
 * and converts all characters to lowercase.
 */
void normalize_string(char *str) {
    int n = strlen(str);

    /* remove punctuation marks from start of string */
    while (is_punctuation(str[0])) {
        memmove(str, str + 1, n - 1);
        n--;
    }

    /* remove punctuation marks from end of string */
    while (is_punctuation(str[n - 1])) {
        str[n - 1] = '\0';
        n--;
    }

    /* convert all characters to lowercase */
    for (int i = 0; i < n; i++) {
        str[i] = tolower(str[i]);
    }
}

/*
 * Given a string, calculates the sentiment score (positive or negative)
 * based on the words in the string and their scores.
 */
int calculate_sentiment(char *str, char **words, int *scores, int n_words) {
    int score = 0;
    char *word;
    int found_word;

    /* tokenize the string into words */
    word = strtok(str, " ");

    while (word != NULL) {
        found_word = 0;

        /* try to find the word in the list */
        for (int i = 0; i < n_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                found_word = 1;
                score += scores[i];
                break;
            }
        }

        /* if word not found, treat as neutral */
        if (!found_word) {
            score += 0;
        }

        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    /* the list of words and their corresponding scores */
    char *words[] = {"amazing", "awesome", "beautiful", "best", "cool", "excellent", "fantastic", "good", "great", "like", "love", "nice", "perfect", "pretty", "super", "terrific", "wonderful", "wow"};
    int scores[] = {4, 4, 3, 3, 3, 4, 4, 2, 3, 3, 4, 3, 3, 3, 3, 4, 4, 4};

    int n_words = 18;

    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    /* remove new line character from input */
    input[strcspn(input, "\n")] = '\0';

    /* create copy of input to normalize */
    char copy[1000];
    memcpy(copy, input, 1000);

    normalize_string(copy);

    int sentiment = calculate_sentiment(copy, words, scores, n_words);

    if (sentiment > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}